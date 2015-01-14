#include <iostream>
#include <dirent.h>
#include "implication.h"
#include "Parser.h"

bool Implication::isSubstitute(const Expression *expr) const
{
    if (typeid(*this) != typeid(*expr))
    {
        return false;
    }
/*    std::cout<<this->toString()<<"\n";
    std::cout<<expr->toString()<<"\n";*/
    return (this->left->isSubstitute(static_cast<const Implication*>(expr)->left.get()))
            && this->right->isSubstitute(static_cast<const Implication*>(expr)->right.get());
}

bool Implication::isEqual(const Expression *expr) const
{
    return typeid(*expr) == typeid(Implication)
            && left->isEqual(static_cast<const Implication*>(expr)->left.get())
            && right->isEqual(static_cast<const Implication*>(expr)->right.get())
            ;
}

bool Implication::calculate(bool result1, bool result2) const
{
    return !(result1  && !result2);
}

std::shared_ptr<const Expression> Implication::substitute(std::map<std::string, std::shared_ptr<Expression const> > &comparasion) const
{
    return std::shared_ptr<Expression const>(new Implication(left->substitute(comparasion), right->substitute(comparasion)));
}

const std::string Implication::proofment0[] =
{
        "!A",
        "!A->A->!A",
        "A->!A",
        "!B",
        "!B->A->!B",
        "A->!B",
        "A->A->A",
        "(A->A->A)->(A->(A->A)->A)->A->A",
        "(A->(A->A)->A)->A->A",
        "(A->(A->A)->A)",
        "A->A",
        "(A -> !B -> A)",
        "(A -> !B -> A)->A->(A -> !B -> A)",
        "A->(A -> !B -> A)",
        "(A->A)->(A->A->(!B->A))->A->(!B->A)",
        "(A->A->(!B->A))->A->(!B->A)",
        "A->(!B->A)",
        "(!A -> !B -> !A)",
        "(!A -> !B -> !A)->A->(!A -> !B -> !A)",
        "A->(!A -> !B -> !A)",
        "(A->!A)->(A->!A->(!B->!A))->A->(!B->!A)",
        "(A->!A->(!B->!A))->A->(!B->!A)",
        "A->(!B->!A)",
        "((!B -> A) -> (!B -> !A) -> !!B)",
        "((!B -> A) -> (!B -> !A) -> !!B)->A->((!B -> A) -> (!B -> !A) -> !!B)",
        "A->((!B -> A) -> (!B -> !A) -> !!B)",
        "(A->(!B->A))->(A->(!B->A)->((!B -> !A) -> !!B))->A->((!B -> !A) -> !!B)",
        "(A->(!B->A)->((!B -> !A) -> !!B))->A->((!B -> !A) -> !!B)",
        "A->((!B -> !A) -> !!B)",
        "(A->(!B->!A))->(A->(!B->!A)->!!B)->A->!!B",
        "(A->(!B->!A)->!!B)->A->!!B",
        "A->!!B",
        "(!!B->B)",
        "(!!B->B)->A->(!!B->B)",
        "A->(!!B->B)",
        "(A->!!B)->(A->!!B->B)->A->B",
        "(A->!!B->B)->A->B",
        "A->B"
};
const std::string Implication::proofment1[] = {
        "B",
        "B->A->B",
        "A->B"
};

const std::string Implication::proofment2[] = {
        "A",
        "!B",
        "((A->B)->A)->((A->B)->!A)->!(A->B)",
        "A->(A->B)->A",
        "(A->B)->A",
        "((A->B)->!A)->!(A->B)",
        "!B->(A->B)->!B",
        "(A->B)->!B",
        "(A->B)->(A->B)->(A->B)",
        "((A->B)->(A->B)->(A->B))->((A->B)->((A->B)->(A->B))->(A->B))->(A->B)->(A->B)",
        "((A->B)->((A->B)->(A->B))->(A->B))->(A->B)->(A->B)",
        "((A->B)->((A->B)->(A->B))->(A->B))",
        "(A->B)->(A->B)",
        "((A->B)->(A->!B)->!A)",
        "((A->B)->(A->!B)->!A)->(A->B)->((A->B)->(A->!B)->!A)",
        "(A->B)->((A->B)->(A->!B)->!A)",
        "((A->B)->(A->B))->((A->B)->(A->B)->((A->!B)->!A))->(A->B)->((A->!B)->!A)",
        "((A->B)->(A->B)->((A->!B)->!A))->(A->B)->((A->!B)->!A)",
        "(A->B)->((A->!B)->!A)",
        "(!B->A->!B)",
        "(!B->A->!B)->(A->B)->(!B->A->!B)",
        "(A->B)->(!B->A->!B)",
        "((A->B)->!B)->((A->B)->!B->(A->!B))->(A->B)->(A->!B)",
        "((A->B)->!B->(A->!B))->(A->B)->(A->!B)",
        "(A->B)->(A->!B)",
        "((A->B)->(A->!B))->((A->B)->(A->!B)->!A)->(A->B)->!A",
        "((A->B)->(A->!B)->!A)->(A->B)->!A",
        "(A->B)->!A",
        "!(A->B)"
};
const std::string Implication::proofment3[] = {
        "B",
        "B->A->B",
        "A->B"
};

const std::string* Implication::proofment[2][2] = {
{proofment0, proofment1},
{proofment2, proofment3}
};


std::string const *Implication::getSimpleProofment(int l1, int r1) const
{
        return proofment[l1][r1];
}

size_t Implication::getSimpleProofSize(int l1, int r1) const
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
        return 0;
}
