#ifndef DISJUNCTION_H
#define DISJUNCTION_H

#include "BinaryExpression.h"

class Disjunction : public BinaryExpression
{
public:
    Disjunction(Expression const *expr1, Expression const *expr2)
            : BinaryExpression(expr1, expr2, "|")
    {
    }

    virtual bool isSubstitute(const Expression *expr) const override;

    virtual bool isEqual(const Expression *expr) const override;
};

#endif // DISJUNCTION_H
