#include <dirent.h>
#include <glob.h>
#include "proofcheck.h"
#include <algorithm>
#include <tgmath.h>
#include "../Parser/implication.h"
#include "../Parser/Parser.h"
#include "../Parser/kvantorexist.h"
#include "../Parser/kvantorall.h"
#include "../Parser/variable.h"
#include "../Parser/conjunction.h"
#include "../Parser/Shtrix.h"
#include "../Parser/Zero.h"

std::map<std::string, const Expression*> ProofCheck::variables;
const std::string ProofCheck::stringAxioms[] =
{
"A->B->A",
"(A->B)->(A->B->C)->(A->C)",
"A->B->A&B",
"A&B->A",
"A&B->B",
"A->A|B",
"B->A|B",
"(A->C)->(B->C)->(A|B->C)",
"(A->B)->(A->!B)->!A",
"!!A->A"
};
const std::string ProofCheck::stringArithmAxioms[] =
{
"a=b->a'=b'",
"a=b->a=c->b=c",
"a'=b'->a=b",
"!(a'=0)",
"a+b'=(a+b)'",
"a+0=a",
"a*0=0",
"a*b'=a*b+a"
};

ProofCheck::ProofCheck()
{
    for (size_t i = 0; i < axioms_size; i++)
    {
        axioms.emplace_back(Parser::parseString(stringAxioms[i]));
    }
    for (size_t i = 0; i < arithm_axioms_size; i++)
    {
        arithm_axioms.emplace_back(Parser::parseString(stringArithmAxioms[i]));
    }
}

int ProofCheck::isAxiom(const Expression *expr)
{
    for (size_t i = 0; i < ProofCheck::axioms_size; i++)
    {
        ProofCheck::variables.clear();
//        std::cerr << axioms[i]->toString() << "\n";
//        std::cerr << expr->toString() << "\n";
//        std::cerr << axioms[i]->isSubstitute(expr) << "\n";
        if (axioms[i]->isSubstitute(expr))
        {
            return (int)i;
        }
    }
    return -1;
}

void ProofCheck::addExpression(std::shared_ptr<const Expression> expr)
{
    expressions.emplace_back(expr);
    hash_expressions[expr->getHash()].push_back( expressions.size() - 1);
}


void ProofCheck::addExpression(const Expression *expr)
{
    addExpression(std::shared_ptr<const Expression>(expr));
}

std::pair<size_t, size_t> ProofCheck::getModusPones(const Expression *expr)
{
    size_t expr_hash = expr->getHash();
    for (size_t i = 0; i < expressions.size(); i++)
    {
        const Expression* approve = expressions[i].get();
        if (typeid(*approve) == typeid(Implication))
        {
            const Implication* implication = static_cast<const Implication*>(approve);
            if (implication->right->getHash() == expr_hash && implication->right->isEqual(expr)
                    && hash_expressions.find(implication->left->getHash()) != hash_expressions.end())
            {
                for (auto num : hash_expressions[implication->left->getHash()])
                {
                    if (expressions[num]->isEqual(implication->left.get()))
                    {
                        return std::make_pair(i, num);
                    }

                }
            }
        }
    }
    return std::make_pair(-1, -1);
}

void ProofCheck::clearData()
{
    expressions.clear();
    hash_expressions.clear();
    variables.clear();
}

std::shared_ptr<const Expression> &ProofCheck::getExpression(size_t i)
{
    return expressions[i];
}

int ProofCheck::wasExpression(std::shared_ptr<const Expression> expr)
{
    if (hash_expressions.find(expr->getHash()) != hash_expressions.end())
    {
        auto vec = hash_expressions[expr->getHash()];
        for (auto num : vec)
        {
            if (expr->isEqual(expressions[num].get()))
            {
                return num;
            }
        }
    }
    return -1;
}

PredicatResult ProofCheck::getPredicatRule(const Expression *expr)
{
    PredicatResult result;
    result.error = false;
    result.num = -1;
    if (typeid(*expr) == typeid(Implication))
    {
        const Implication* impl = static_cast<const Implication*>(expr);
        if (typeid(*impl->left.get()) == typeid(KvantorExist))
        {
            std::shared_ptr<const Expression> cur(
                    new Implication(static_cast<const KvantorExist*>(impl->left.get())->term, impl->right));
            result.num = wasExpression(cur);
//            std::cerr << res << "\n";
            if (result.num != -1)
            {
                std::vector<std::string> freeVar = impl->right->getVariables();
                result.varName = static_cast<const KvantorAll*>(impl->left.get())->variable->toString();
                if (std::find(freeVar.begin(), freeVar.end(), result.varName) != freeVar.end())
                {
                    result.error = true;
                    result.formula = impl->right.get();
                    return result;
                }
                return result;
            }
        }
        if (typeid(*impl->right.get()) == typeid(KvantorAll))
        {
            std::shared_ptr<const Expression> cur(
                    new Implication(impl->left, static_cast<const KvantorAll*>(impl->right.get())->term));
            result.num = wasExpression(cur);
            if (result.num != -1)
            {
                std::vector<std::string> freeVar = impl->left->getVariables();
                result.varName = static_cast<const KvantorAll*>(impl->right.get())->variable->toString();
                if (std::find(freeVar.begin(), freeVar.end(), result.varName) != freeVar.end()) {
                    result.error = true;
                    result.formula = impl->left.get();
                    return result;
                }
                return result;
            }
        }
    }
    return result;
}

PredicatResult ProofCheck::isPredicatAxiom(const Expression *expr)
{
//    std::cerr << "Axiom " << typeid(*expr).name() << "\n";
    PredicatResult result;
    result.error = false;
    result.num = -1;
    if (typeid(*expr) == typeid(Implication))
    {
        const Implication *impl = static_cast<const Implication*>(expr);
        if (typeid(*impl->left.get()) == typeid(KvantorAll))
        {
            ProofCheck::variables.clear();
            const KvantorAll *kvantor = static_cast<const KvantorAll*>(impl->left.get());
            std::string varName = kvantor->variable->toString();
//            std::cerr << "Predicat Axiom " <<  expr->toString() << " " << kvantor->term->isSubstitute(impl->right.get()) << "\n";
            if (kvantor->term->isSubstitute(impl->right.get()))
            {
                const Expression* curTerm = ProofCheck::variables[kvantor->variable->toString()];
                result.varName = varName;
//                std::cerr << "Predicat This " << kvantor->term->isFreeToSubstitute(varName, curTerm->getVariables()).successuful << "\n";
                result.num = 0;
                if (kvantor->term->isFreeToSubstitute(varName, curTerm->getVariables()).successuful)
                {
                    result.num = 1;
                }
                else
                {
                    result.error = true;
                    result.notFreeTerm = curTerm;
                    result.formula = impl->right.get();
                }
                return result;
            }
        }
        if (typeid(*impl->right.get()) == typeid(KvantorExist))
        {
            ProofCheck::variables.clear();
            const KvantorExist *kvantor = static_cast<const KvantorExist*>(impl->right.get());
            if (kvantor->term->isSubstitute(impl->left.get()))
            {
                const Expression* curTerm = ProofCheck::variables[kvantor->variable->toString()];
                std::string varName = kvantor->variable->toString();
                result.num = 0;
                if (kvantor->term->isFreeToSubstitute(varName, curTerm->getVariables()).successuful)
                {
                    result.num = 2;
                }
                else
                {
                    result.error = true;
                    result.notFreeTerm = curTerm;
                    result.formula = impl->left.get();
                }
                return result;
            }
        }
    }
    return result;
}

int ProofCheck::isArithmAxiom(Expression const * expr)
{
    for (size_t i = 0; i < ProofCheck::arithm_axioms_size; i++)
    {
        ProofCheck::variables.clear();
        if (arithm_axioms[i]->isSubstitute(expr))
        {
            return (int) i;
        }
    }
    if (typeid(*expr) == typeid(Implication))
    {
        const Implication* impl1 = static_cast<const Implication*>(expr);
        std::shared_ptr<const Expression> A = impl1->right;
        if (typeid(*impl1->left.get()) == typeid(Conjunction))
        {
            const Conjunction* conj = static_cast<const Conjunction*>(impl1->left.get());
            if (typeid(*conj->right.get()) == typeid(KvantorAll))
            {
                const KvantorAll* kvantor = static_cast<const KvantorAll*>(conj->right.get());
                std::string varName = kvantor->variable->toString();
                if (typeid(*kvantor->term.get()) == typeid(Implication))
                {
                    const Implication* impl2 = static_cast<const Implication*>(kvantor->term.get());
                    if (!A->isEqual(impl2->left.get()))
                    {
                        return -1;
                    }
                    std::shared_ptr<const Expression> mulled(new Shtrix(kvantor->variable));
                    std::map<std::string, std::shared_ptr<const Expression>> comparasion;
                    comparasion[varName] = mulled;
                    if (!impl2->right->isEqual(A->substitute(comparasion).get()))
                    {
                        return -1;
                    }
                    comparasion[varName] = std::shared_ptr<const Expression>(new Zero());
                    if (!conj->left->isEqual(A->substitute(comparasion).get()))
                    {
                        return -1;
                    }
                    return ProofCheck::arithm_axioms_size;
                }
            }
        }
    }
    return -1;
}
