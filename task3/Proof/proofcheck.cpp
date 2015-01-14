#include <dirent.h>
#include "proofcheck.h"
#include "../Parser/implication.h"
#include "../Parser/Parser.h"

std::map<std::string, size_t> ProofCheck::variables;

ProofCheck::ProofCheck()
        : stringAxioms(
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
        })
{
    for (size_t i = 0; i < axioms_size; i++)
    {
        axioms.emplace_back(Parser::parseString(stringAxioms[i]));
    }
}

int ProofCheck::isAxiom(const Expression *expr)
{
    for (size_t i = 0; i < axioms_size; i++)
    {
        ProofCheck::variables.clear();
        if (axioms[i]->isSubstitute(expr))
        {
            return (int) i;
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

bool ProofCheck::wasExpression(std::shared_ptr<const Expression> expr)
{
    if (hash_expressions.find(expr->getHash()) != hash_expressions.end())
    {
        auto vec = hash_expressions[expr->getHash()];
        for (auto num : vec)
        {
            if (expr->isEqual(expressions[num].get()))
            {
                return true;
            }
        }
    }
    return false;
}
