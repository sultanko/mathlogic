#include <glob.h>
#include "equality.h"

size_t Equality::getSimpleProofSize(int l1, int r1) const
{
    return 0;
}

const std::string *Equality::getSimpleProofment(int l1, int r1) const
{
    return nullptr;
}

bool Equality::calculate(bool result1, bool result2) const
{
    return false;
}

std::shared_ptr<const Expression> Equality::substitute(std::map<std::string, std::shared_ptr<Expression const> > &comparasion) const
{
    return std::shared_ptr<Expression const>(new Equality(left->substitute(comparasion), right->substitute(comparasion)));
}
