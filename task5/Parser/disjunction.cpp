#include "disjunction.h"

bool Disjunction::isSubstitute(const Expression *expr) const
{
    if (typeid(*this) != typeid(*expr))
    {
        return false;
    }
    return this->left->isSubstitute(static_cast<const Disjunction*>(expr)->left.get())
            && this->right->isSubstitute(static_cast<const Disjunction*>(expr)->right.get());
}

bool Disjunction::isEqual(const Expression *expr) const
{
    return typeid(*expr) == typeid(Disjunction)
            && left->isEqual(static_cast<const Disjunction*>(expr)->left.get())
            && right->isEqual(static_cast<const Disjunction*>(expr)->right.get())
            ;
}

bool Disjunction::calculate(bool result1, bool result2) const
{
    return result1 || result2;
}

std::shared_ptr<const Expression> Disjunction::substitute(std::map<std::string, std::shared_ptr<Expression const> > &comparasion) const
{
    return std::shared_ptr<Expression const>(new Disjunction(left->substitute(comparasion), right->substitute(comparasion)));
}


// 0 0
const std::string Disjunction::proofment0[] =
{
        "!A",
        "!B",
        "(A|B->A)->(A|B->!A)->!(A|B)",
        "(A->A)->(B->A)->(A|B->A)",
        "A->A->A",
        "(A->A->A)->(A->(A->A)->A)->(A->A)",
        "(A->(A->A)->A)->(A->A)",
        "A->(A->A)->A",
        "A->A",
        "(B->A)->(A|B->A)",
        "!B->B->!B",
        "B->!B",
        "B->B->B",
        "(B->B->B)->(B->(B->B)->B)->B->B",
        "(B->(B->B)->B)->B->B",
        "(B->(B->B)->B)",
        "B->B",
        "(!!A->A)",
        "(!!A->A)->B->(!!A->A)",
        "B->(!!A->A)",
        "((!A->B)->(!A->!B)->!!A)",
        "((!A->B)->(!A->!B)->!!A)->B->((!A->B)->(!A->!B)->!!A)",
        "B->((!A->B)->(!A->!B)->!!A)",
        "(B->!A->B)",
        "(B->!A->B)->B->(B->!A->B)",
        "B->(B->!A->B)",
        "(B->B)->(B->B->(!A->B))->B->(!A->B)",
        "(B->B->(!A->B))->B->(!A->B)",
        "B->(!A->B)",
        "(B->(!A->B))->(B->(!A->B)->((!A->!B)->!!A))->B->((!A->!B)->!!A)",
        "(B->(!A->B)->((!A->!B)->!!A))->B->((!A->!B)->!!A)",
        "B->((!A->!B)->!!A)",
        "(!B->!A->!B)",
        "(!B->!A->!B)->B->(!B->!A->!B)",
        "B->(!B->!A->!B)",
        "(B->!B)->(B->!B->(!A->!B))->B->(!A->!B)",
        "(B->!B->(!A->!B))->B->(!A->!B)",
        "B->(!A->!B)",
        "(B->(!A->!B))->(B->(!A->!B)->!!A)->B->!!A",
        "(B->(!A->!B)->!!A)->B->!!A",
        "B->!!A",
        "(B->!!A)->(B->!!A->A)->B->A",
        "(B->!!A->A)->B->A",
        "B->A",
        "A|B->A",
        "(A|B->!A)->!(A|B)",
        "!A->A|B->!A",
        "A|B->!A",
        "!(A|B)"
};
// 0 1
const std::string Disjunction::proofment1[] = {
        "B",
        "B->A | B",
        "A | B"
};

// 1 0
const std::string Disjunction::proofment2[] = {
        "A",
        "A->A | B",
        "A | B"
};
// 1 1
const std::string Disjunction::proofment3[] = {
        "A",
        "A->A | B",
        "A | B"
};

const std::string* Disjunction::proofment[2][2] = {
        {proofment0, proofment1},
        {proofment2, proofment3}
};

const std::string *Disjunction::getSimpleProofment(int l1, int r1) const
{
        return proofment[l1][r1];
}

size_t Disjunction::getSimpleProofSize(int l1, int r1) const
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

bool Disjunction::calculate(const Tree &tree, const std::map<size_t, bool> &used) const
{
        return left->calculate(tree, used) || right->calculate(tree, used);
}
