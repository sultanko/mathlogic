//
// Created by sultan on 02.05.15.
//

#include "Generator.h"
#include <iostream>
#include <algorithm>

using namespace std;
template <typename T>
using sptr = std::shared_ptr<T>;

void Generator::generateWorlds(const Expression *expr)
{
    vector<string> vars = expr->getVariables();
    set<string> uniqVars;
    for (auto var : vars)
    {
        uniqVars.insert(var);
    }
    this->variables.clear();
    this->variables.assign(uniqVars.begin(), uniqVars.end());
    this->worlds.clear();
    this->trees.clear();
    worlds.emplace_back(new World());
    generateWorlds(worlds.back(), 0);
    sort(worlds.begin(), worlds.end(), [](const std::shared_ptr<World>& w1, const std::shared_ptr<World>& w2) -> bool
    {
        return w1->getForced().size() < w2->getForced().size();
    });
//    cerr << "Worlds generated" << "\n";
}

void Generator::generateWorlds(const std::shared_ptr<World> world, int pos)
{
    if (pos >= (int)variables.size())
    {
        return;
    }
//    cerr << "Pos: " << pos << "\n";
    World* world2 = new World(world);
    std::shared_ptr<World> world1(world2);
    world1->addVar(variables[pos]);
    worlds.push_back(world1);
    generateWorlds(worlds.back(), pos + 1);
    generateWorlds(world, pos + 1);
}

void Generator::generateTrees(sptr<Tree> tree, size_t pos)
{
    for (size_t i = pos; i < worlds.size(); ++i)
    {
        if (tree->getWorld()->isLessAndSubset(*worlds[i].get()))
        {
            tree->addTree(worlds[i], 1);
        } else if (tree->getWorld()->isSubset(*worlds[i].get())) {
            if ((tree->getOrder() <= worlds.back()->getSize()
                    && worlds[i]->getSize() == 0)
            )
            {
                tree->addTree(worlds[i], tree->getOrder() + 1);
            }
        }
    }
//    std::cerr << "Trees: " << tree->getTrees().size() << "\n";
    for (size_t i = 0; i < tree->getTrees().size(); ++i)
    {
//        if (tree->getWorld()->getSize() == tree->getChild(i)->getWorld()->getSize()) {
//            generateTrees(tree->getChild(i), pos + 1);
//        } else
//        {
            generateTrees(tree->getChild(i), pos);
//        }
    }
}

void Generator::generateTrees()
{
//    cerr << "Generate trees:" << "\n";
    std::shared_ptr<World> sworld(new World());
    trees.emplace_back(new Tree(sworld, 1));
//    trees.back()->addTree(sworld, 1);
    generateTrees(trees.back(), 0);
//    std::cerr << "Worlds " << worlds.size() << "\n";
//    cerr << "Variables " << variables.size() << "\n";
}

map<size_t, bool> Generator::checkExpression(const Expression *expr)
{
    map<size_t, bool> result;
    const set<size_t> ids = trees.front()->getIdTrees();
    vector<size_t> idsvec(ids.begin(), ids.end());
    for (auto item : ids)
    {
        result.insert(make_pair(item, false));
    }
//    std::cerr << idsvec.size() << "\n";
    rootId = trees.front()->getId();
    result[rootId] = true;
//    map<size_t, bool>::iterator iter = result.begin();
    if (!generateSubtrees(expr, result, idsvec, 0))
    {
        return result;
    }
    result.clear();
    return result;
}

bool Generator::generateSubtrees(const Expression *expr, std::map<size_t, bool> &res,
                                 const std::vector<size_t>& ids, size_t pos)
{
//    static int counter = 0;
    if (pos == ids.size())
    {
//        if (counter%100000 == 0) {
//            std::cerr << counter << "\n";
//            if (counter == 0) {
//                std::cout << *trees.front().get() << "\n";
//            }
//        }
//        ++counter;
        return expr->calculate(*trees.front().get(), res);
    }
    if (ids[pos] == rootId)
    {
        return generateSubtrees(expr, res, ids, pos + 1);
    }
    res[ids[pos]] = true;
    if (!generateSubtrees(expr, res, ids, pos+1))
    {
        return false;
    }
    res[ids[pos]] = false;
    if (!generateSubtrees(expr, res, ids, pos + 1))
    {
        return false;
    }
    return true;
}
