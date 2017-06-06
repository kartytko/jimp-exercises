//
// Created by kartytko on 05.06.17.
//

#include <iostream>
#include "Tree.h"
#include "TreeIterators.h"

int main(){

    tree::Tree<int> simple_tree;
    simple_tree(0);
    std::cout<<simple_tree.Value();

        simple_tree.Insert(-20);
        simple_tree.Insert(80);
        simple_tree.Insert(10078);
        simple_tree.Insert(98341);
        simple_tree.Insert(198341);
        simple_tree.Insert(-90);
        simple_tree.Insert(-10);

    auto root = simple_tree.Root();
    std::cout<<root.Value();
    tree::PreOrderTreeIterator<int> iterator = PreOrderTreeIterator<int>(root);
    //++iterator;
    return 0;
}