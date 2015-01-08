#ifndef CONJUNCTION_H
#define CONJUNCTION_H

#include "BinaryExpression.h"

class Conjunction : public BinaryExpression
{
public:
    Conjunction(Expression const *expr1, Expression const *expr2)
            : BinaryExpression(expr1, expr2, "&")
    {

    }

    virtual bool isSubstitute(const Expression *expr) const override;

    virtual bool isEqual(const Expression *expr) const override;
};

#endif // CONJUNCTION_H
