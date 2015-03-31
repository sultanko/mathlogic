#ifndef NEGATION_H
#define NEGATION_H

#include "unaryexpression.h"
#include <functional>

class Negation : public UnaryExpression
{
public:
    Negation(const Expression* expr) : UnaryExpression(expr, std::string("!")) {
//        hash = hash_fn("!") + expr->getHash();
        hash_str = std::hash<std::string>()(toString());
    };

protected:
    virtual std::string toString() const override;

    virtual bool isEqual(const Expression *expr) const override;

    virtual bool isSubstitute(const Expression *expr) const override;
};

#endif // NEGATION_H
