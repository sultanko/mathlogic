#include "negation.h"

std::size_t Negation::getHash() const
{
    std::hash<std::string> hash_fn;
    return hash_fn("!") + expr->getHash();
}

std::string Negation::toString() const
{
    return "!" + expr->toString();
}

bool Negation::isEqual(const Expression *expr) const
{
    return typeid(*expr) == typeid(Negation)
            && expr->isEqual(static_cast<const Negation*>(expr)->expr)
            ;
}

bool Negation::isSubstitute(const Expression *expr) const
{
    if (typeid(*this) != typeid(*expr))
    {
        return false;
    }
    return this->expr->isSubstitute(static_cast<const Negation*>(expr)->expr);
}
