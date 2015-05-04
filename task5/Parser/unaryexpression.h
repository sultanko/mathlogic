#ifndef UNARYEXPRESSION_H
#define UNARYEXPRESSION_H

#include "Expression.h"

class UnaryExpression : public Expression
{
protected:
    std::shared_ptr<const Expression> expr;
public:
    UnaryExpression(const Expression* expr1, const std::string& str);
    UnaryExpression(std::shared_ptr<const Expression> expr1, const std::string& str)
    : Expression(str), expr(expr1)
    {}

    ~UnaryExpression();

    virtual std::string toString() const;
};

#endif // UNARYEXPRESSION_H
