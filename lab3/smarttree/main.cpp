#include "SmartTree.h"
#include <iostream>
#include <ostream>
#include <string>


int main(){

        std::unique_ptr <datastructures::SmartTree> root = datastructures::CreateLeaf(5);
        std::unique_ptr <datastructures::SmartTree> child = datastructures::CreateLeaf(2);
        std::string output;
    //    std::unique_ptr <datastructures::SmartTree> new_root =  datastructures::InsertLeftChild(move(root), move(child));

        std::cout<<std::endl<<"wartość roota: "<<root->value<<std::endl<<"wartosc childa :"<<child->value;
    /*if(root->left==nullptr){
        std::cout<<"hej";
        root->left = move(child);
    }
    if(root->left!= nullptr){
        std::cout<<"drugie hej";
        std::cout<<root->left->value;
    }
*/

    int value_int;
    std::string value_str="45";
    value_int=std::stoi(value_str);
    std::cout<<"to value"<<value_int;

    root = datastructures::InsertLeftChild(move(root), move(child));
    root->left = datastructures::InsertLeftChild(move(root->left), datastructures::CreateLeaf(77));
    root = datastructures::InsertRightChild(move(root), datastructures::CreateLeaf(12));
    output = datastructures::DumpTree(root);
    std::cout<<std::endl;
    std::cout<<output;

    std::string strink = "to ja";
    for(int i=0; i<strink.size(); i++){
        std::cout<<i<<" '"<<strink[i]<<"'"<<std::endl;
    }
    return 0;
}