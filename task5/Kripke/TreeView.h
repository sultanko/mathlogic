//
// Created by sultan on 04.05.15.
//

#ifndef TASK4_TREEVIEW_H
#define TASK4_TREEVIEW_H

#include "Tree.h"
#include <memory>
#include <list>

class TreeView : public Tree
{
    std::list<std::shared_ptr<TreeView>> treesView;
    std::shared_ptr<Tree> treeLink;

public:
    TreeView(const std::shared_ptr<Tree>& tree) : Tree(tree->getWorld(), tree->getOrder()), treeLink(tree)
    { }

};


#endif //TASK4_TREEVIEW_H
