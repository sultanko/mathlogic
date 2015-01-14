#include "unaryexpression.h"

UnaryExpression::UnaryExpression(const Expression *expr1, const std::string& str)
    : Expression(str), expr(expr1)
{

}

UnaryExpression::~UnaryExpression()
{
}

std::string UnaryExpression::toString() const
{
    return "(" + expr->toString() + ")";
}

