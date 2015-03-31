#include "BinaryExpression.h"

std::size_t BinaryExpression::getHash() const
{
    return left->getHash() * ExpressionConsts::BASE_HASH + right->getHash();
}

BinaryExpression::BinaryExpression(const Expression *expr1, const Expression *expr2
        , const std::string& str)
    : Expression(str), left(expr1), right(expr2)
{
}

std::string BinaryExpression::toString() const
{
    return
            "(" +
            left->toString() + stringExpr + right->toString()
            + ")"
            ;
}

BinaryExpression::~BinaryExpression()
{
    delete left;
    delete right;
}
