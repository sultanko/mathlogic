#include "kvantorexist.h"

bool KvantorExist::calculate(const std::map<std::string, bool>& variables) const{

return false;
}

std::shared_ptr<const Expression> KvantorExist::substitute(std::map<std::string, std::shared_ptr<Expression const> > &comparasion) const
{
    if (comparasion.find(variable->toString()) != comparasion.end())
    {
        return std::shared_ptr<Expression const>(new KvantorExist(variable, term));
    }
    return std::shared_ptr<const Expression>(new KvantorExist(variable, term->substitute(comparasion)));
}
