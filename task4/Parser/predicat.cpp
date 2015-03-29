#include "predicat.h"
#include "../Proof/proofcheck.h"

bool Predicat::calculate(const std::map<std::string, bool> &variables) const
{
    return false;
}

void Predicat::proofThis(std::vector<std::shared_ptr<const Expression> > &vout, const std::map<std::string, bool> &varValues) const
{
}

std::shared_ptr<const Expression> Predicat::substitute(std::map<std::string, std::shared_ptr<Expression const> > &comparasion) const
{
    std::vector<std::shared_ptr<const Expression>> sTerms;
    for (auto item : terms)
    {
        sTerms.push_back(item->substitute(comparasion));
    }
    return std::shared_ptr<Expression const>(new Predicat(stringExpr, sTerms));
}

bool Predicat::isSubstitute(const Expression *expr) const
{
    if (!terms.empty())
    {
        return FArguments::isSubstitute(expr);
    }
//    std::cerr << stringExpr << " " << expr->toString() << "\n";
    ProofCheck* utils = ProofCheck::getInstance();
    if (utils->variables.find(stringExpr) == utils->variables.end())
    {
        utils->variables[stringExpr] = expr;
    }
    else
    {
        if ((size_t) utils->variables[stringExpr]->getHash() != (size_t) expr->getHash())
        {
//            std::cerr << "BAD " << utils->variables[stringExpr]->getHash() << " " << expr->getHash() << "\n";
            return false;
        }
    }
    return true;
}
