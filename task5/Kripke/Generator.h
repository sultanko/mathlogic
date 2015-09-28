//
// Created by sultan on 02.05.15.
//

#ifndef TASK4_GENERATOR_H
#define TASK4_GENERATOR_H


#include "../Parser/Expression.h"
#include "World.h"
#include "Tree.h"
#include <vector>
#include <list>
#include <string>

class Generator
{
private:
    template <typename T>
    using sptr = std::shared_ptr<T>;
    std::vector<std::string> variables;
    std::vector<sptr<World>> worlds;
    std::list<sptr<Tree>> trees;
    size_t rootId;

    void generateWorlds(const std::shared_ptr<World> world, int pos);
    void generateTrees(sptr<Tree> tree, size_t pos);
    bool generateSubtrees(const Expression* expr, std::map<size_t, bool>& res,
                          const std::vector<size_t>& ids, size_t pos);

public:
    void generateWorlds(const Expression* expr);
    void generateTrees();

    std::map<size_t, bool> checkExpression(const Expression* expr);

    std::list<sptr<Tree>> const &getTrees() const
    {
        return trees;
    }
};


#endif //TASK4_GENERATOR_H
