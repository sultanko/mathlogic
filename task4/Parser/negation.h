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
        hash_string = std::hash<std::string>()(toString());
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

public:
    static const std::string proofment0[];
    static const std::string proofment1[];
};

#endif // NEGATION_H