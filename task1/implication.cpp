#include <iostream>
#include "implication.h"

bool Implication::isSubstitute(const Expression *expr) const
{
    if (typeid(*this) != typeid(*expr))
    {
        return false;
    }
/*    std::cout<<this->toString()<<"\n";
    std::cout<<expr->toString()<<"\n";*/
    return (this->left->isSubstitute(static_cast<const Implication*>(expr)->left))
            && this->right->isSubstitute(static_cast<const Implication*>(expr)->right);
}

bool Implication::isEqual(const Expression *expr) const
{
    return false;
}
