#include "disjunction.h"

bool Disjunction::isSubstitute(const Expression *expr) const
{
    if (typeid(*this) != typeid(*expr))
    {
        return false;
    }
    return this->left->isSubstitute(static_cast<const Disjunction*>(expr)->left)
            && this->right->isSubstitute(static_cast<const Disjunction*>(expr)->right);
}

bool Disjunction::isEqual(const Expression *expr) const
{
    return false;
}
