//
// Created by sultan on 25.03.15.
//

#include "Shtrix.h"

bool Shtrix::isSubstitute(const Expression *expr) const
{
//    std::cerr << "Shtrix " << toString() << " " << (typeid(*this) == typeid(*expr)) << " "
//            << expr->toString() << "\n";
    return typeid(*this) == typeid(*expr)
            && mulp->isSubstitute(static_cast<const Shtrix*>(expr)->mulp.get());
}

bool Shtrix::isEqual(const Expression *expr) const
{
    return typeid(*this) == typeid(*expr)
            && mulp->isEqual(static_cast<const Shtrix*>(expr)->mulp.get());
}

bool Shtrix::calculate(const std::map<std::string, bool> &variables) const
{
    return mulp->calculate(variables);
}

std::string Shtrix::toString() const
{
    return mulp->toString() + "'";
}

std::vector<std::string> Shtrix::getVariables() const
{
    return mulp->getVariables();
}

std::shared_ptr<const Expression> Shtrix::substitute(std::map<std::string, std::shared_ptr<Expression const> > &comparasion) const
{
    return std::shared_ptr<const Expression>(new Shtrix(mulp->substitute(comparasion)));
}

void Shtrix::proofThis(std::vector<std::shared_ptr<const Expression> > &vout, const std::map<std::string, bool> &varValues) const
{
}

SubstState Shtrix::isFreeToSubstitute(const std::string &varName, const std::vector<std::string> &freeVariables) const
{
    return mulp->isFreeToSubstitute(varName, freeVariables);
}
