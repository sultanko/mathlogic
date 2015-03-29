//
// Created by sultan on 25.03.15.
//

#include "Zero.h"

bool Zero::isEqual(const Expression *expr) const
{
    return typeid(*expr) == typeid(Zero);
}

bool Zero::isSubstitute(const Expression *expr) const
{
    return isEqual(expr);
}

bool Zero::calculate(const std::map<std::string, bool> &variables) const
{
    return false;
}

std::string Zero::toString() const
{
    return "0";
}

std::vector<std::string> Zero::getVariables() const
{
    return std::vector<std::string>();
}

std::shared_ptr<const Expression> Zero::substitute(std::map<std::string, std::shared_ptr<Expression const> > &comparasion) const
{
    return std::shared_ptr<Expression const>(new Zero());
}

void Zero::proofThis(std::vector<std::shared_ptr<const Expression> > &vout, const std::map<std::string, bool> &varValues) const
{
    throw new ExpressionException((const std::string &) "unsupported exception");
}

SubstState Zero::isFreeToSubstitute(const std::string &varName, const std::vector<std::string> &freeVariables) const
{
    return SubstState();
}
