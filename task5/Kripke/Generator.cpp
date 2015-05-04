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
//    cerr << "Worlds generated start" << "\n";
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
            tree->addTree(worlds[i]);
        }
    }
//    std::cerr << "Trees: " << tree->getTrees().size() << "\n";
    for (size_t i = 0; i < tree->getTrees().size(); ++i)
    {
        generateTrees(tree->getChild(i), pos);
    }
}

void Generator::generateTrees()
{
    std::shared_ptr<World> sworld(new World());
    trees.emplace_back(new Tree(sworld));
//    trees.back()->addTree(sworld);
    generateTrees(trees.back(), 1);
//    std::cerr << "Worlds " << worlds.size() << "\n";
//    cerr << "Variables " << variables.size() << "\n";
}

map<size_t, bool> Generator::checkExpression(const Expression *expr)
{
    map<size_t, bool> result;
    const set<size_t> ids = trees.front()->getIdTrees();
    for (auto item : ids)
    {
        result.insert(make_pair(item, false));
    }
    rootId = trees.front()->getId();
    result[rootId] = true;
//    map<size_t, bool>::iterator iter = result.begin();
    if (!generateSubtrees(expr, result, result.begin()))
    {
        return result;
    }
    result.clear();
    return result;
}

bool Generator::generateSubtrees(const Expression *expr, std::map<size_t, bool> &res,
                                 std::map<size_t, bool>::iterator iter)
{
    if (iter == res.end())
    {
        return expr->calculate(*trees.front().get(), res);
    }
    if (iter->first == rootId)
    {
        return generateSubtrees(expr, res, ++iter);
    }
    std::map<size_t, bool>::iterator iter2 = iter;
    ++iter2;
    res[iter->first] = true;
    if (!generateSubtrees(expr, res, iter2))
    {
        return false;
    }
    res[iter->first] = false;
    if (!generateSubtrees(expr, res, iter2))
    {
        return false;
    }
    return true;
}
