#include "kvantor.h"
#include <algorithm>

bool Kvantor::isEqual(Expression const *expr) const{
    return typeid(*this) == typeid(*expr)
            && variable->isEqual(static_cast<const Kvantor*>(expr)->variable.get())
            && term->isEqual(static_cast<const Kvantor*>(expr)->term.get());
}

bool Kvantor::isSubstitute(const Expression *expr) const
{
    return typeid(*this) == typeid(*expr)
            && term->isSubstitute(static_cast<const Kvantor*>(expr)->term.get());
}

std::string Kvantor::toString() const
{
    return stringExpr + variable->toString() + "(" + term->toString() + ")";
}

std::vector<std::string> Kvantor::getVariables() const
{
    std::vector<std::string> res = term->getVariables();
    auto it = std::find(res.begin(), res.end(), variable->toString());
    if (it != res.end()) {
        res.erase(it);
    }
    return res;
}

void Kvantor::proofThis(std::vector<std::shared_ptr<const Expression> > &vout, const std::map<std::string, bool> &varValues) const
{

}

SubstState Kvantor::isFreeToSubstitute(const std::string &varName, const std::vector<std::string> &freeVariables) const
{
    if (varName == variable->toString())
    {
        return SubstState();
    }
    SubstState res(term->isFreeToSubstitute(varName, freeVariables));
    if (res.wasSubstitued)
    {
        if (std::find(freeVariables.begin(), freeVariables.end(), variable->toString()) != freeVariables.end())
        {
            res.successuful = false;
        }
    }
    return res;
}
