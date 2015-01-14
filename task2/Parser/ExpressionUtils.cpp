#include "Expression.h"
#include "ExpressionUtils.h"
#include "ParserUtils.h"
#include "implication.h"
#include "variable.h"
#include "conjunction.h"
#include "disjunction.h"

using std::cout;

ExpressionUtils::ExpressionUtils()
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
    , expressions()
    , hash_expressions()
{
    for (size_t i = 0; i < axioms_size; i++)
    {
        axioms.push_back(ParserUtils::parseString(stringAxioms[i]));
    }
}

int ExpressionUtils::isAxiom(Expression const *expr)
{

    for (size_t i = 0; i < axioms_size; i++)
    {
        variables.clear();
        if (axioms[i]->isSubstitute(expr))
        {
            return (int) i;
        }
    }
    return -1;
}

void ExpressionUtils::addExpression(const Expression *expr)
{
    expressions.push_back(expr);
    hash_expressions[expr->getHash()] = expressions.size() - 1;
}

std::pair<size_t, size_t> ExpressionUtils::getModusPones(const Expression *expr)
{
    size_t expr_hash = expr->getHash();
    for (size_t i = 0; i < expressions.size(); i++)
    {
        const Expression* approve = expressions[i];
        if (typeid(*approve) == typeid(Implication))
        {
            const Implication* implication = static_cast<const Implication*>(approve);
            if (implication->right->getHash() == expr_hash
                    && hash_expressions.find(implication->left->getHash()) != hash_expressions.end())
            {
                return std::make_pair(i, hash_expressions[implication->left->getHash()]);
            }
        }
    }
    return std::make_pair(-1, -1);
}

void ExpressionUtils::addHeader(std::string str)
{
    size_t breaker = str.find('|', 0);
    size_t breaker_old = breaker;
    str = ',' + str.substr(0, breaker);
    breaker_old++;
    breaker = str.rfind(',', str.size() - 1);
    proposalStr = str.substr(breaker + 1, breaker_old - breaker - 1);
    proposal = ParserUtils::parseString(proposalStr);
    breaker_old = breaker;
    while (breaker != 0)
    {
        breaker = str.rfind(',', breaker_old - 1);
        assumptions.push_back(
            ParserUtils::parseString(
                str.substr(breaker + 1, breaker_old - breaker - 1)));
        breaker_old = breaker;
    }
    proposalStr = "(" + proposalStr + ")";
    for (auto assumption : assumptions)
    {
        writeProof(assumption);
    }
    writeProof(proposal);
}

ExpressionUtils::~ExpressionUtils()
{
    safeDeleteVector(axioms);
    safeDeleteVector(expressions);
    //safeDeleteVector(assumptions);
    //delete proposal;
}

int ExpressionUtils::isAssumption(const Expression *expr)
{
    for (size_t i = 0; i < assumptions.size(); i++)
    {
        if (assumptions[i]->isEqual(expr))
        {
            return i;
        }
    }
    return -1;
}

void ExpressionUtils::writeProof(const Expression *now)
{
    addExpression(now);
    int num_axiom = isAxiom(now);
    int num_assumpt = isAssumption(now);
//    std::cerr << num_axiom << " " << num_assumpt << "\n";
    if (num_axiom != -1 || num_assumpt != -1)
    {
        writeAxiomProof(now->toString());
    }
    else if (proposal->isEqual(now))
    {
        writeSelfProof();
    }
    else
    {
        writeMpProof(now);
    }
    cout << proposalStr << "->(" << now->toString() << ")\n";
}

void ExpressionUtils::writeAxiomProof(const std::string &strNow)
{
//    cout << "Axiom or assumption\n";
    cout << strNow << "\n";
    cout << "(" << strNow << ")" << "->((" <<  proposalStr << ")->" << "(" << strNow << "))\n";
}

void ExpressionUtils::writeSelfProof()
{
//    cout << "Selfi \n";
    using namespace std;
    cout << proposalStr << "->(" << proposalStr << "->" << proposalStr << ")" << "\n";
    cout
            << "(" << proposalStr << "->(" << proposalStr << "->" << proposalStr << ")" << ")"
            << "->" << "(" << proposalStr << "->" << "((" << proposalStr << "->"  << proposalStr << ")"
            << "->" << proposalStr << "))" << "->" << "(" << proposalStr << "->" << proposalStr << ")"
            << "\n";
    cout
            << "(" << proposalStr << "->" << "((" << proposalStr << "->"  << proposalStr << ")"
            << "->" << proposalStr << "))" << "->" << "(" << proposalStr << "->" << proposalStr << ")"
            << "\n";
    cout
            << "(" << proposalStr << "->" << "((" << proposalStr << "->"  << proposalStr << ")"
            << "->" << proposalStr << "))"
            << "\n";
}

void ExpressionUtils::writeMpProof(Expression const *now)
{
    // first > second
    std::pair<size_t, size_t> approves = getModusPones(now);
    const std::string& str = now->toString();
//    cout << "M.P " << approves.first << " " << approves.second <<"\n";
    std::string m2 = ExpressionUtils::getInstance()->getExpressions()[approves.first]->toString();
    std::string m1 = ExpressionUtils::getInstance()->getExpressions()[approves.second]->toString();
    cout << "(" <<  proposalStr << "->" << m1 << ")"
            << "->" << "((" << proposalStr << "->" << "(" <<  m1 << "->" << str << ")" << ")"
            << "->" << "(" << proposalStr << "->" << str << "))"
            << "\n";
    cout
            << "(" << proposalStr << "->(" << m2 << "))"
            << "->" << "(" << proposalStr << "->" << str << ")"
            << "\n";
}
