//
// Created by sultan on 02.05.15.
//

#include "World.h"
#include <iostream>

bool World::containsVariable(const std::string &var) const
{
//    std::cerr << "Varialbe " << var << " " << "Res: " << (forced.find(var) != forced.end()) << "\n";
    return forced.find(var) != forced.end();
}

World::World(const std::shared_ptr<const World> &pworld)
    : forced()
{
//    std::cerr << "World copy " << "\n";
//    forced.insert(pworld->getForced().begin(), pworld->getForced().end());
    for (const std::string& str : pworld->getForced())
    {
//        std::cerr << "Copying " << str << "\n";
        forced.insert(str);
//        std::cerr << "Copying end" << "\n";
    }
//    std::cerr << "World copy end\n";
}

std::ostream &operator<<(std::ostream &os, const World& world)
{
    os << " [";
    for (auto item : world.getForced())
    {
        os << item << ",";
    }
    os << "] ";
    return os;
}

bool World::isSubset(const World &world) const
{
    for (auto item : forced)
    {
        if (!world.containsVariable(item))
        {
            return false;
        }
    }
    return true;
}

bool World::isLessAndSubset(const World &world) const
{
    return forced.size() <  world.forced.size()
            && isSubset(world);
}
