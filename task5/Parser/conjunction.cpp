#include "conjunction.h"

bool Conjunction::isSubstitute(const Expression *expr) const
{
    if (typeid(*this) != typeid(*expr))
    {
        return false;
    }
    return this->left->isSubstitute(static_cast<const Conjunction*>(expr)->left.get())
            && this->right->isSubstitute(static_cast<const Conjunction*>(expr)->right.get());
}

bool Conjunction::isEqual(const Expression *expr) const
{
    return typeid(*expr) == typeid(Conjunction)
            && left->isEqual(static_cast<const Conjunction*>(expr)->left.get())
            && right->isEqual(static_cast<const Conjunction*>(expr)->right.get())
            ;
}

bool Conjunction::calculate(bool result1, bool result2) const
{
    return result1 && result2;
}

std::shared_ptr<const Expression> Conjunction::substitute(std::map<std::string, std::shared_ptr<Expression const> > &comparasion) const
{
    return std::shared_ptr<Expression const>(new Conjunction(left->substitute(comparasion), right->substitute(comparasion)));
}

// 0 0
const std::string Conjunction::proofment0[] =
{
        "!A",
        "(A& B -> A) -> (A & B -> !A) -> !(A & B)",
        "A&B-> A",
        "(A&B -> !A) -> !(A & B)",
        "!A -> A & B -> !A",
        "A & B -> !A",
        "!(A & B)"
};
// 0 1
const std::string Conjunction::proofment1[] = {
        "!A",
        "(A & B -> A) -> (A & B -> !A) -> !(A & B)",
        "A & B -> A",
        "(A & B -> !A) -> !(A & B)",
        "!A -> A & B -> !A",
        "A & B -> !A",
        "!(A & B)"
};

// 1 0
const std::string Conjunction::proofment2[] = {
        "!B",
        "(A & B -> B) -> (A & B -> !B) -> !(A & B)",
        "A & B -> B",
        "(A & B -> !B) -> !(A & B)",
        "!B -> A & B -> !B",
        "A & B -> !B",
        "!(A & B)"
};
// 1 1
const std::string Conjunction::proofment3[] = {
        "A",
        "B",
        "A -> B -> A & B",
        "B -> A & B",
        "A & B"
};

const std::string* Conjunction::proofment[2][2] = {
        {proofment0, proofment1},
        {proofment2, proofment3}
};

std::string const *Conjunction::getSimpleProofment(int l1, int r1) const
{
    return proofment[l1][r1];
}

size_t Conjunction::getSimpleProofSize(int l1, int r1) const
{
    if (l1 == 0 && r1 == 0)
    {
        return std::extent<decltype(proofment0)>::value;
    }
    if (l1 == 0 && r1 == 1)
    {
        return std::extent<decltype(proofment1)>::value;
    }
    if (l1 == 1 && r1 == 0)
    {
        return std::extent<decltype(proofment2)>::value;
    }
    if (l1 == 1 && r1 == 1)
    {
        return std::extent<decltype(proofment3)>::value;
    }
    return std::extent<decltype(proofment[l1][r1])>::value;
}

bool Conjunction::calculate(const Tree &tree, const std::map<size_t, bool> &used) const
{
    return left->calculate(tree, used) && right->calculate(tree, used);
}
