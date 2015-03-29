#ifndef PREDICAT_H_
#define PREDICAT_H_

#include <stdio.h>
#include "Expression.h"
#include "FArguments.h"

class Predicat : public FArguments
{
public:

    Predicat(std::string const &stringExpr,
             const std::vector<std::shared_ptr<const Expression>> terms)
            : FArguments(stringExpr, terms)
    {
    }

    bool calculate(const std::map<std::string, bool>& variables) const;

    void proofThis(std::vector<std::shared_ptr<const Expression> >& vout, const std::map<std::string, bool>& varValues) const;

    virtual bool isSubstitute(const Expression *expr) const override;

    virtual std::shared_ptr<const Expression> substitute(std::map<std::string, std::shared_ptr<Expression const> > &comparasion) const override;
};
#endif
