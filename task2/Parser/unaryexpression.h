#ifndef UNARYEXPRESSION_H
#define UNARYEXPRESSION_H

#include "Expression.h"

class UnaryExpression : public Expression
{
protected:
    const Expression* expr;
public:
    UnaryExpression(const Expression* expr, const std::string& str);

    ~UnaryExpression();


    virtual std::string toString() const;
};

#endif // UNARYEXPRESSION_H
