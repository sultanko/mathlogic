#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include <string>
#include "iostream"
#include <map>
#include <typeinfo>
#include <vector>
#include <memory>

namespace ExpressionConsts {
    const long long BASE_HASH = 59;
}

class ExpressionException : public std::exception {
private:
    std::string message;
public:

    ExpressionException(const std::string &message) : exception(), message(message)
    {
        this->message.append(exception::what());
    }


    virtual const char *what() const _GLIBCXX_USE_NOEXCEPT override;
};

struct SubstState {
    bool wasSubstitued;
    bool successuful;
    SubstState() : wasSubstitued(false), successuful(true) {}

    SubstState(bool wasSubstitued, bool successuful = true) : wasSubstitued(wasSubstitued), successuful(successuful)
    {
    }

    SubstState& operator=(const SubstState& other)
    {
        wasSubstitued |= other.wasSubstitued;
        successuful &= other.successuful;
        return *this;
    }
};

class Expression
{
protected:
    std::string stringExpr;
    size_t hash_string;

public:

    Expression(const std::string &stringExpr) : stringExpr(stringExpr) {}

    virtual bool isSubstitute(const Expression* expr) const = 0;
    virtual bool isEqual(const Expression* expr) const = 0;

    virtual bool calculate(const std::map<std::string, bool>& variables) const = 0;

    virtual std::string toString() const = 0;
    virtual size_t getHash() const;

    virtual std::vector<std::string> getVariables() const = 0;

    virtual std::shared_ptr<const Expression> substitute(std::map<std::string, std::shared_ptr<Expression const> > &comparasion) const = 0;

    virtual void proofThis(std::vector<std::shared_ptr<const Expression> >& vout, const std::map<std::string, bool>& varValues) const = 0;

    virtual SubstState isFreeToSubstitute(const std::string &varName, const std::vector<std::string> &freeVariables) const = 0;

    virtual ~Expression() {};
};

#endif

