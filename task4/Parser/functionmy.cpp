#include "functionmy.h"

bool FunctionMy::calculate(const std::map<std::string, bool> &variables) const
{
    return false;
}

void FunctionMy::proofThis(std::vector<std::shared_ptr<const Expression> > &vout, const std::map<std::string, bool> &varValues) const
{

}

std::shared_ptr<const Expression> FunctionMy::substitute(std::map<std::string, std::shared_ptr<Expression const> > &comparasion) const
{
    std::vector<std::shared_ptr<const Expression>> sTerms;
    for (auto item : terms)
    {
        sTerms.push_back(item->substitute(comparasion));
    }
    return std::shared_ptr<Expression const>(new FunctionMy(stringExpr, sTerms));
}
