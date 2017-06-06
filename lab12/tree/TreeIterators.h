//
// Created by kartytko on 05.06.17.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include "Tree.h"
#include <vector>

namespace tree{
    template <class T>
    class PreOrder{

    };

    template<class T>
    class PreOrderTreeIterator {
    public:
        PreOrderTreeIterator() {}

        ~PreOrderTreeIterator() {}

        PreOrderTreeIterator(/*const Tree<T> &node*/Tree<T> node) {
            pointer_ = node;
        }

        /*void operator()(const Tree<T> &node) {
            pointer_ = std::make_shared<Tree<T>>(node);
        }*/


        /*void SortChildren(const Tree<T> &node){

            Tree<T> leftchild = *(node.GetLeft()).get();
            Tree<T> rightchild = *(node.GetRight()).get();

            children_pre_order_.push_back(node);
            if(node.GetLeft()!=nullptr){
                SortChildren(*node.GetLeft().get());
            }
            if(node.GetRight()!=nullptr){
                SortChildren(leftchild);
            }

            //    for(std::shared_ptr<Tree<T>> i=children_pre_order_.begin(); i<children_pre_order_.end(); i++){
            //        std::cout<< (*i.get()).Value()<<std::endl;
            //   }
        }
*/
        /*PreOrderTreeIterator &operator++() {
            //SortChildren(*pointer_.get());
            //bool found = false;
            //std::vector<Tree<T>> helping_vector = pointer_.Get_Vector();
            for (const auto &a:  children_pre_order_) {
                std::shared_ptr<Tree<T>> ptr = std::make_shared<Tree<T>>(a);
                std::cout << "to value" << (*ptr.get()).Value() << std::endl;
                if (found) {
                    pointer_ = std::make_shared<Tree<T>>(a);
                    break;
                }
                if (std::make_shared<Tree<T>>(a) == pointer_) {
                    found = true;
                }
                return *this;

            return pointer_.Get_Vector().find(pointer_).next();
        }*/


            //pointer_=(*pointer_.get()).GetLeft();
            //  InOrderTreeIterator <T> parent = *this;

      /*  T operator*() {
            return (*pointer_.get()).Value();
        }*/

     /*   bool operator!=(const PreOrderTreeIterator &iterator2) const {
            return *pointer_.get() != *iterator2.pointer_.get();;
        }*/

        /*void SortChildren2(const std::shared_ptr<Tree<T>> &pointer){

            Tree<T> leftchild = *((*pointer.get()).GetLeft()).get();
            Tree<T> rightchild = *((*pointer.get()).GetRight()).get();

            children_pre_order_.push_back(*pointer.get());
            if((*pointer.get()).GetLeft()!=nullptr){
                SortChildren(std::make_shared<Tree<T>>(leftchild));
            }
            if((*pointer.get()).GetRight()!=nullptr){
                SortChildren(std::make_shared<Tree<T>>(rightchild));
            }



            //    for(std::shared_ptr<Tree<T>> i=children_pre_order_.begin(); i<children_pre_order_.end(); i++){
            //        std::cout<< (*i.get()).Value()<<std::endl;
            //   }
        */


    private:
        Tree<T> pointer_;
        //int vector_iterator_ = 0;

    };

    template<class T>
    class PreOrderTreeView{};







    template <class T>
    class InOrder{

    };

    template<class T>
    class InOrderTreeIterator{
    public:
        InOrderTreeIterator(){}
        ~InOrderTreeIterator(){}
        InOrderTreeIterator(const Tree<T> &node){
            pointer_ = std::make_shared<Tree<T>>(node);
        }

        void operator()(const Tree<T> &node){
            pointer_ = std::make_shared<Tree<T>>(node);
        }

        void operator++(){
          //  InOrderTreeIterator <T> parent = *this;
        }

        T operator*(){
            return (*pointer_.get()).Value();
        }

        bool operator!=(InOrderTreeIterator &iterator2){
            return pointer_!=iterator2.pointer_;
        }

    private:
        std::shared_ptr<Tree<T>> pointer_;
    };

    template<class T>
    class InOrderTreeView{};






    template <class T>
    class PostOrder{

    };

    template<class T>
    class PostOrderTreeIterator{
    public:
        PostOrderTreeIterator(){}
        ~PostOrderTreeIterator(){}
        PostOrderTreeIterator(const Tree<T> &node){
            pointer_ = std::make_shared<Tree<T>>(node);
        }

        void operator()(const Tree<T> &node){
            pointer_ = std::make_shared<Tree<T>>(node);
        }

        void operator++(){
            //  InOrderTreeIterator <T> parent = *this;
        }

        T operator*(){
            return (*pointer_.get()).Value();
        }

        bool operator!=(PostOrderTreeIterator &iterator2){
            return pointer_!=iterator2.pointer_;
        }

    private:
        std::shared_ptr<Tree<T>> pointer_;
    };

    template<class T>
    class PostOrderTreeView{};


}

class TreeIterators {

};


#endif //JIMP_EXERCISES_TREEITERATORS_H
