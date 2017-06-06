//
// Created by kartytko on 05.06.17.
//
#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <iostream>
#include <memory>

namespace tree {

    template<class T>
    class Tree {
    public:
        Tree(){};
        Tree(const T &node):value(node) {
            left_ = nullptr;
            right_ = nullptr;
            size_ = 1;
//            children_pre_order_={};
        }
        ~Tree(){};

        bool operator<(const Tree<T> &node) const {
            if (value < node.value) {
                return true;
            }
            else{
                return false;
            }
        }

        bool operator!=(const Tree<T> &node) const{
            if(value== node.value && left_==node.left_ && right_==node.right_){
                return false;
            }else{
                return true;
            }
        }

        void operator()(T new_value){
            value = new_value;
        }


        Tree<T> Root(){
            return *this;
        }

        void Insert(const T &node) {
            if (value < node) {
                if (left_ == nullptr) {
                    left_ = std::make_shared<Tree<T>>(node);
                } else {
                    left_->Insert(node);
                }
            } else {
                if (right_ == nullptr) {
                    right_ = std::make_shared<Tree<T>>(node);
                } else {
                    right_->Insert(node);
                }
            }
            size_++;
//            SortChildren(Root());
        }

        bool Find(const Tree<T> &node) {
            if (value == node) {
                return true;
            }
            if (value < node) {
                if (left_ == nullptr){
                    return false;
                }
                else{
                    left_->Find(node);
                }
            } else {
                if (right_ == nullptr){
                    return false;
                }
                else{
                    right_->Find(node);
                }
            }
        }

        size_t Depth() {
            if (left_ != nullptr and right_ != nullptr) {
                return 1 + std::max(left_->Depth(), right_->Depth());
            } else {
                if (left_ != nullptr)
                    return 1 + left_->Depth();
                if (right_ != nullptr)
                    return 1 + right_->Depth();
                return 1;
            }
        }
        size_t Size() {
            return size_;
        }

        int Value() {
            return value;
        }

        std::shared_ptr <Tree<T>> GetLeft()const {
            return left_;
        }

        std::shared_ptr <Tree<T>> GetRight()const{
            return right_;
        }



        //std::vector<Tree<T>> GetChildrenPreOrder(){
          //  return children_pre_order_;
       // }


    private:
      //  std::vector<Tree> children_pre_order_;
        std::shared_ptr<Tree<T>> left_;
        std::shared_ptr<Tree<T>> right_;
        T value;
        size_t size_;

    };


}



#endif //JIMP_EXERCISES_TREE_H
