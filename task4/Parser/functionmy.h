#ifndef FUCNTION_MY_H_
#define FUCNTION_MY_H_

#include "BinaryExpression.h"
#include "FArguments.h"

class FunctionMy : public FArguments
{
    std::vector<std::shared_ptr<const Expression>> terms;

public:
    FunctionMy(std::string const &stringExpr
            , std::vector<std::shared_ptr<const Expression>> terms)
        : FArguments(stringExpr, terms)
    {
    }

    bool calculate(const std::map<std::string, bool>& variables) const;


    virtual std::shared_ptr<const Expression> substitute(std::map<std::string, std::shared_ptr<Expression const> > &comparasion) const override;

    void proofThis(std::vector<std::shared_ptr<const Expression> >& vout, const std::map<std::string, bool>& varValues) const;
};
#endif
