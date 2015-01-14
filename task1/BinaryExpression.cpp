#include "BinaryExpression.h"
#include <functional>
#include <string>

std::size_t BinaryExpression::getHash() const
{
    return hash;
}

BinaryExpression::BinaryExpression(const Expression *expr1, const Expression *expr2
        , const std::string& str)
    : left(expr1), right(expr2), Expression(str)
{
    hash = left->getHash() * (ExpressionConsts::BASE_HASH + 32) +
            + std::hash<std::string>()(stringExpr) * 37 +
            right->getHash();
}

std::string BinaryExpression::toString() const
{
    return
//            "(" +
            left->toString() + stringExpr + right->toString()
//            + ")"
            ;
}

BinaryExpression::~BinaryExpression()
{
    delete left;
    delete right;
}
