//
// Created by sultan on 02.05.15.
//

#ifndef TASK4_TREE_H
#define TASK4_TREE_H

#include <memory>
#include <set>
#include <string>
#include <vector>
#include "World.h"
#include "../Parser/Expression.h"
#include <ostream>

class Expression;

class Tree
{
private:
    template <typename T>
    using sptr = std::shared_ptr<T>;

    static size_t treeCounter;

    sptr<World> world;
    std::vector<sptr<Tree>> trees;
    const size_t id;

public:
    Tree(const std::shared_ptr<World>& world)
            : world(world), trees(), id(++treeCounter)
    {}

    void addTree(const sptr<Tree>& ptree)
    {
        trees.push_back(ptree);
    }


    size_t const getId() const
    {
        return id;
    }

    std::set<size_t> getIdTrees() const
    {
        std::set<size_t> result;
        for (auto item : trees)
        {
            const std::set<size_t> iItem = item->getIdTrees();
            result.insert(iItem.begin(), iItem.end());
        }
        result.insert(getId());
        return result;
    }

    virtual sptr<Tree> addTree(const sptr<World>& world);

    virtual std::vector<sptr<Tree>> const &getTrees() const
    {
        return trees;
    }


    std::shared_ptr<World> const &getWorld() const
    {
        return world;
    }

    virtual sptr<Tree> getChild(size_t i)
    {
        return trees.at(i);
    }

    void printTree(std::ostream& os, const std::map<size_t, bool>& used, int shift);

    bool containsKey(const std::string& variable) const;

    virtual bool checkExpression(const Expression* expr) const;

    std::ostream& printTree(std::ostream& os, int shift) const;

    virtual ~Tree() {}

    friend std::ostream& operator<<(std::ostream& os, const Tree& tree);
};


#endif //TASK4_TREE_H
