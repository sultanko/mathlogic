#include "unaryexpression.h"

UnaryExpression::UnaryExpression(const Expression *expr1, const std::string& str)
    : Expression(str), expr(expr1)
{
    hash_string = std::hash<std::string>()(toString());
}

UnaryExpression::~UnaryExpression()
{
}

std::string UnaryExpression::toString() const
{
    return "(" + expr->toString() + ")";
}

SubstState UnaryExpression::isFreeToSubstitute(const std::string &varName, const std::vector<std::string> &freeVariables) const
{
    return expr->isFreeToSubstitute(varName, freeVariables);
}
