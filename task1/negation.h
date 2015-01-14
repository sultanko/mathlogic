#ifndef NEGATION_H
#define NEGATION_H

#include "unaryexpression.h"
#include <functional>

class Negation : public UnaryExpression
{
public:
    Negation(const Expression* expr) : UnaryExpression(expr, std::string("!")) {
        std::hash<std::string> hash_fn;
        hash = hash_fn("!") + expr->getHash();
    };

protected:
    virtual std::size_t getHash() const override;

    virtual std::string toString() const override;

    virtual bool isEqual(const Expression *expr) const override;

    virtual bool isSubstitute(const Expression *expr) const override;
};

#endif // NEGATION_H
