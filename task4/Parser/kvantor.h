#ifndef KVANTOR_H_
#define KVANTOR_H_

#include <stdio.h>
#include "Expression.h"

class Kvantor : public Expression
{
public:
    std::shared_ptr<const Expression> variable;
    std::shared_ptr<const Expression> term;
public:
    template <typename T1, typename T2>
    Kvantor(T1 var, T2 term, std::string const &stringExpr)
        : Expression(stringExpr),
        variable(var),
        term(term)
    {
    }

    bool isSubstitute(const Expression* expr) const;
    bool isEqual(const Expression* expr) const;

    std::string toString() const;

    std::vector<std::string> getVariables() const;

    void proofThis(std::vector<std::shared_ptr<const Expression> >& vout, const std::map<std::string, bool>& varValues) const;
    virtual SubstState isFreeToSubstitute(const std::string &varName, const std::vector<std::string> &freeVariables) const override;
};
#endif
