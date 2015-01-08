#ifndef IMPLICATION_H
#define IMPLICATION_H

#include "BinaryExpression.h"

class Implication : public BinaryExpression
{
public:

    Implication(Expression const *expr1, Expression const *expr2)
            : BinaryExpression(expr1, expr2, "->")
    {
    }

    virtual bool isSubstitute(const Expression *expr) const override;

    virtual bool isEqual(const Expression *expr) const override;
};

#endif // IMPLICATION_H
