#include "unaryexpression.h"

UnaryExpression::UnaryExpression(const Expression *expr, const std::string& str)
    : Expression(str), expr(expr)
{

}

UnaryExpression::~UnaryExpression()
{
    delete expr;
}
