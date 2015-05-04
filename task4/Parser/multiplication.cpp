#include "multiplication.h"


std::shared_ptr<const Expression> Multiplication::substitute(std::map<std::string, std::shared_ptr<Expression const> > &comparasion) const
{
    return std::shared_ptr<Expression const>(new Multiplication(left->substitute(comparasion), right->substitute(comparasion)));
}


bool Multiplication::calculate(bool result1, bool result2) const
{
    return false;
}

const std::string *Multiplication::getSimpleProofment(int l1, int r1) const
{
    return nullptr;
}

size_t Multiplication::getSimpleProofSize(int l1, int r1) const
{
    return 0;
}
