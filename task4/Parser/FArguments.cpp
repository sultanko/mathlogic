//
// Created by sultan on 26.03.15.
//

#include "FArguments.h"

std::string FArguments::toString() const
{
    std::string name = stringExpr;
    if (!terms.empty()) {
        name += '(';
        for (auto it = this->terms.begin(); it != terms.end(); it++)
        {
            if (it != terms.begin())
            {
                name += ',';
            }
            name += it->get()->toString();
        }
        name += ')';
    }
    return name;
}

bool FArguments::isEqual(const Expression *expr) const
{
    if (typeid(*expr) != typeid(*this))
    {
        return false;
    }
    const FArguments* farg = static_cast<const FArguments*>(expr);
    bool ok = farg->stringExpr == stringExpr && farg->terms.size() == terms.size();
    auto itf = farg->terms.begin();
    for (auto it = this->terms.begin(); it != terms.end() && ok; ++it)
    {
        ok &= it->get()->isEqual(itf->get());
        ++itf;
    }
    return ok;
}

std::vector<std::string> FArguments::getVariables() const
{
    typedef std::vector<std::string> vecstr;
    vecstr res;
    for (auto item : terms) {
        vecstr varItem = item->getVariables();
        res.insert(res.end(), varItem.begin(), varItem.end());
    }
    return res;
}

SubstState FArguments::isFreeToSubstitute(const std::string &varName, const std::vector<std::string> &freeVariables) const
{
    SubstState res;
    for (auto item : terms)
    {
        res = item->isFreeToSubstitute(varName, freeVariables);
    }
    return res;
}

bool FArguments::isSubstitute(const Expression *expr) const
{
    if (typeid(*expr) != typeid(*this))
    {
        return false;
    }
    const FArguments* farg = static_cast<const FArguments*>(expr);
    bool ok = farg->stringExpr == stringExpr && farg->terms.size() == terms.size();
    auto itf = farg->terms.begin();
    for (auto it = terms.begin(); it != terms.end() && ok; ++it)
    {
        ok &= it->get()->isSubstitute(itf->get());
        ++itf;
    }
    return ok;
}

