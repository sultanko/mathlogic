#include "kvantorall.h"

bool KvantorAll::calculate(const std::map<std::string, bool>& variables) const {
return false;
}

std::shared_ptr<const Expression> KvantorAll::substitute(std::map<std::string, std::shared_ptr<Expression const> > &comparasion) const
{
    if (comparasion.find(variable->toString()) != comparasion.end())
    {
        return std::shared_ptr<Expression const>(new KvantorAll(variable, term));
    }
    return std::shared_ptr<const Expression>(new KvantorAll(variable, term->substitute(comparasion)));
}
