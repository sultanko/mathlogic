#include <glob.h>
#include "subtraction.h"

const std::string *Subtraction::getSimpleProofment(int l1, int r1) const
{
    return nullptr;
}

size_t Subtraction::getSimpleProofSize(int l1, int r1) const
{
    return 0;
}

bool Subtraction::calculate(bool result1, bool result2) const
{
    return false;
}

std::shared_ptr<Expression const> Subtraction::substitute(std::map<std::string, std::shared_ptr<Expression const>> &comparasion) const
{
    return std::shared_ptr<Expression const>(new Subtraction(left->substitute(comparasion), right->substitute(comparasion)));
}
