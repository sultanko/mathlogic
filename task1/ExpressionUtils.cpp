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
    expressions.emplace_back(expr);
    mymap.insert(std::pair<const Expression*, size_t>(expr, expressions.size() - 1));
}

std::pair<size_t, size_t> ExpressionUtils::getModusPones(const Expression *expr)
{
    for (size_t i = 0; i < expressions.size(); i++)
    {
        const Expression* approve = expressions[i].get();
        if (typeid(*approve) == typeid(Implication))
        {
            const Implication* implication = static_cast<const Implication*>(approve);
            if (implication->right->getHash() == expr->getHash() && implication->right->isEqual(expr))
            {
                auto mit = mymap.find(implication->left);
                if (mit != mymap.end()) {
                    return std::make_pair(i, mit->second);
                }
            }
        }
    }
    return std::make_pair(-1, -1);
}
