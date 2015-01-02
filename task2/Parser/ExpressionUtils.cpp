#include "Expression.h"
#include "ExpressionUtils.h"
#include "ParserUtils.h"
#include "implication.h"
#include "variable.h"
#include "conjunction.h"
#include "disjunction.h"

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
    str = ',' + str.substr(0, breaker - 1);
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
}

ExpressionUtils::~ExpressionUtils()
{
    safeDeleteVector(axioms);
    safeDeleteVector(expressions);
    safeDeleteVector(assumptions);
    delete proposal;
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

void ExpressionUtils::writeSelfProof()
{
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
