//
// Created by kartytko on 18.03.17.
//

#ifndef JIMP_EXERCISES_SMARTTREE_H
#define JIMP_EXERCISES_SMARTTREE_H
#include <ostream>
#include <string>
#include <memory>

namespace datastructures{
    struct SmartTree{
        int value;
        std::unique_ptr<SmartTree> left=nullptr;
        std::unique_ptr<SmartTree> right= nullptr;
    };
    std::unique_ptr <SmartTree> CreateLeaf(int value);
    std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree);
    std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree);
    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out);
    std::string DumpTree(const std::unique_ptr<SmartTree> &tree);
    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree);
    std::unique_ptr <SmartTree> RestoreRight(const std::string &tree, int closed_brackets_counter, int open_brackets_counter);
    std::unique_ptr <SmartTree> RestoreLeft(const std::string &tree, int closed_brackets_counter, int open_brackets_counter);
}

#endif //JIMP_EXERCISES_SMARTTREE_H
