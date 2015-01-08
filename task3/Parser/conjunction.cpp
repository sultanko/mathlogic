#include "conjunction.h"

bool Conjunction::isSubstitute(const Expression *expr) const
{
    if (typeid(*this) != typeid(*expr))
    {
        return false;
    }
    return this->left->isSubstitute(static_cast<const Conjunction*>(expr)->left)
            && this->right->isSubstitute(static_cast<const Conjunction*>(expr)->right);
}

bool Conjunction::isEqual(const Expression *expr) const
{
    return typeid(*expr) == typeid(Conjunction)
            && left->isEqual(static_cast<const Conjunction*>(expr)->left)
            && right->isEqual(static_cast<const Conjunction*>(expr)->right)
            ;
}
