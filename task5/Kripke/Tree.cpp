//
// Created by sultan on 02.05.15.
//

#include "Tree.h"
#include <iostream>

template <typename T>
using sptr = std::shared_ptr<T>;

size_t Tree::treeCounter = 0;

bool Tree::containsKey(const std::string &variable) const
{
    return world->containsVariable(variable);
}

sptr<Tree> Tree::addTree(const std::shared_ptr<World> &world)
{
    trees.emplace_back(new Tree(world));
    return trees.back();
}

std::ostream &Tree::printTree(std::ostream& os, int shift) const
{
    for (int i = 0; i < shift; ++i)
    {
        os << " ";
    }
    os << "* ";
    for (auto item : world->getForced())
    {
        os << item << " ";
    }
    os << "\n";
//    std::cerr << trees.size() << "\n";
    for (auto item : trees)
    {
        item->printTree(os, shift + 4);
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const Tree &tree)
{
    return tree.printTree(os, 0);
}

bool Tree::checkExpression(const Expression *expr) const
{
    if (!expr->calculate(*this, (std::map<size_t, bool>())))
    {
        return false;
    }
    for (auto item : trees)
    {
        if (!item->checkExpression(expr))
        {
            return false;
        }
    }
    return true;
}

void Tree::printTree(std::ostream &os, const std::map<size_t, bool>& used, int shift)
{
    for (int i = 0; i < shift; ++i)
    {
        os << " ";
    }
    os << "* ";
    for (auto item : world->getForced())
    {
        os << item << " ";
    }
    os << "\n";
//    std::cerr << trees.size() << "\n";
    for (auto item : trees)
    {
        if (used.find(item->getId())->second)
        {
            item->printTree(os, used, shift + 4);
        }
    }
}
