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

    virtual SubstState isFreeToSubstitute(const std::string &varName, const std::vector<std::string> &freeVariables) const override;
};

#endif // UNARYEXPRESSION_H
