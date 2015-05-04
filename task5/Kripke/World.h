//
// Created by sultan on 02.05.15.
//

#ifndef TASK4_WORLD_H
#define TASK4_WORLD_H

#include <memory>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <unordered_map>

class World
{
public:
    World() {}
    World(const std::shared_ptr<const World>& pworld);
    const std::unordered_set<std::string>& getForced() const
    {
        return forced;
    }

    void addVar(const std::string& var)
    {
        forced.insert(var);
    }

    bool containsVariable(const std::string& var) const;

    bool isSubset(const World& world) const;

    bool isLessAndSubset(const World& world) const;

    friend std::ostream& operator<<(std::ostream& os, const World& world);

private:
    std::unordered_set<std::string> forced;
};


#endif //TASK4_WORLD_H
