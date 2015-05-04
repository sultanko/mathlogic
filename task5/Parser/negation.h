#ifndef NEGATION_H
#define NEGATION_H

#include "unaryexpression.h"
#include <functional>

class Negation : public UnaryExpression
{
public:
    template <typename T>
    Negation(T expr) : UnaryExpression(expr, std::string("!"))
    {
       hash = std::hash<std::string>()("!") * ExpressionConsts::BASE_HASH + expr->getHash();
    };

protected:
    virtual std::string toString() const override;

    virtual bool isEqual(const Expression *expr) const override;

public:
    virtual bool calculate(const std::map<std::string, bool> &variables) const override;

    virtual std::vector<std::string> getVariables() const override;


    virtual std::shared_ptr<const Expression> substitute(std::map<std::string, std::shared_ptr<Expression const> > &comparasion) const override;

    virtual bool isSubstitute(const Expression *expr) const override;

    virtual void proofThis(std::vector<std::shared_ptr<const Expression> > &vout, const std::map<std::string, bool> &varValues) const override;

    virtual bool calculate(const Tree &tree, const std::map<size_t, bool> &used) const override;
    bool calculateTrueExpr(const Tree &tree, const Expression *expression, const std::map<size_t, bool> &used) const;

public:
    static const std::string proofment0[];
    static const std::string proofment1[];
};

#endif // NEGATION_H
