//
// Created by sultan on 25.03.15.
//

#ifndef _TASK4_SHTRIX_H_
#define _TASK4_SHTRIX_H_

#include "Expression.h"

class Shtrix : public Expression
{
    std::shared_ptr<const Expression> mulp;

public:
    template <typename T>
    Shtrix(T expr) : Expression("\'"), mulp(expr)
    {
//        hash = mulp->getHash() * ExpressionConsts::BASE_HASH + (long long) std::hash<std::string>()(stringExpr);
        hash_string = std::hash<std::string>()(toString());
    }
    bool isSubstitute(const Expression* expr) const;
    bool isEqual(const Expression* expr) const;

    bool calculate(const std::map<std::string, bool>& variables) const;

    std::string toString() const;

    std::vector<std::string> getVariables() const;

    std::shared_ptr<const Expression> substitute(std::map<std::string, std::shared_ptr<Expression const> > &comparasion) const;

    void proofThis(std::vector<std::shared_ptr<const Expression> >& vout, const std::map<std::string, bool>& varValues) const;

    virtual SubstState isFreeToSubstitute(const std::string &varName, const std::vector<std::string> &freeVariables) const override;
};


#endif //_TASK4_SHTRIX_H_
