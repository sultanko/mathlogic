#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include <string>
#include <typeinfo>

namespace ExpressionConsts {
    const long long BASE_HASH = 31;
}

class Expression
{
protected:
    std::string stringExpr;
public:

    Expression(const std::string &stringExpr) : stringExpr(stringExpr)
    {
    }

    virtual bool isSubstitute(const Expression* expr) const = 0;
    virtual bool isEqual(const Expression* expr) const = 0;
    virtual std::string toString() const = 0;
    virtual std::size_t getHash() const = 0;
    virtual ~Expression() {};
};

#endif

