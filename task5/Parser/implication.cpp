#include <iostream>
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

bool Implication::checkTrueBoth(const Tree &tree, const Expression *expr1, const Expression *expr2,
                                const std::map<size_t, bool> &used) const
{
//    std::cerr << "Tree: " << *tree.getWorld().get() << " "
//    << expr1->toString() << " " << expr1->calculate(tree)
//    << " " << expr2->toString() << " " << expr2->calculate(tree) << "\n";
    if (expr1->calculate(tree, used) && !expr2->calculate(tree, used))
    {
        return false;
    }
    for (auto item : tree.getTrees())
    {
        if (used.find(item->getId())->second && !checkTrueBoth(*item.get(), expr1, expr2, used))
        {
            return false;
        }
    }
    return true;
}

bool Implication::calculate(const Tree &tree, std::map<size_t, bool> const &used) const
{
//    if (tree.getWorld()->getForced().size() == 0) {
//        std::cerr << "Impl: " << toString() << " Size: " << tree.getWorld()->getForced().size() << " Res: " << checkTrueBoth(tree, left.get(), right.get()) << "\n";
//    }
    return checkTrueBoth(tree, left.get(), right.get(), used);
}
