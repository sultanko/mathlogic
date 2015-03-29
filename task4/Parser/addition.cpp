#include <glob.h>
#include "addition.h"
std::shared_ptr<const Expression> Addition::substitute(std::map<std::string, std::shared_ptr<Expression const> > &comparasion) const
{
    return std::shared_ptr<Expression const>(new Addition(left->substitute(comparasion), right->substitute(comparasion)));
}

bool Addition::calculate(bool result1, bool result2) const
{
    return false;
}

const std::string *Addition::getSimpleProofment(int l1, int r1) const
{
    return nullptr;
}

size_t Addition::getSimpleProofSize(int l1, int r1) const
{
    return 0;
}
