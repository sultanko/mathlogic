#ifndef BINARY_EXPRESSION_H_
#define BINARY_EXPRESSION_H_

#include "Expression.h"

class BinaryExpression : public Expression
{
public:
    const Expression* left;
    const Expression* right;

public:
    BinaryExpression(const Expression* expr1, const Expression* expr2, const std::string& str);

    std::size_t getHash() const;

    std::string toString() const;

    ~BinaryExpression();
};

#endif
