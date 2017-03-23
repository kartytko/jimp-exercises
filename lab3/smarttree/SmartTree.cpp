//
// Created by kartytko on 18.03.17.
//

#include "SmartTree.h"
#include <ostream>
#include <iostream>
#include <string>
#include <memory>
#include <vector>

namespace datastructures{
    std::unique_ptr <SmartTree> CreateLeaf(int value){
        std::unique_ptr<SmartTree> new_leaf = std::make_unique<SmartTree>();
        new_leaf->value=value;
        std::cout<<std::endl<<"created :"<<new_leaf->value<<std::endl;
        return new_leaf;
    }

    std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree){
        std::unique_ptr <SmartTree> root = std::make_unique<SmartTree>();
        root = move(tree);
    //    root->left->value=left_subtree->value;
      //  root->left->right=move(left_subtree->right);
     //   root->left->left=move(left_subtree->left);
        root->left=move(left_subtree);
        if(root->left==nullptr){
            std::cout<<"nie tak1";
        }else{
            std::cout<<root->value<<" wskazuje na "<<root->left->value<<std::endl;
        }
        return root;
    }

    std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree){
        std::unique_ptr <SmartTree> root = std::make_unique<SmartTree>();
        root = move(tree);
      //  root->right->value=right_subtree->value;
      //  root->right->right=move(right_subtree->right);
      //  root->right->left=move(right_subtree->left);
        root->right=move(right_subtree);
        if(root->right== nullptr){
            std::cout<<"nie tak";
        }else{
            std::cout<<root->value<<" wskazuje na "<<root->right->value<<std::endl;
        }
        return root;
    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out){
        std::cout<<"printtreeinorder"<<std::endl;
        if(unique_ptr->left!=nullptr){
            PrintTreeInOrder(move(unique_ptr->left), out);
        }
        *out << unique_ptr->value<<", ";
        if(unique_ptr->right!=nullptr){
            PrintTreeInOrder(move(unique_ptr->right), out);
        }
    }

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree){
     //   std::cout<<"dumptree";
        std::string output="[";
        std::string value_str;
        int value;
        value=tree->value;
        value_str=std::to_string(value);
        output=output+value_str;
        if(tree->left!=nullptr){
            output = output + " " + DumpTree(tree->left);
        }else{
            output = output + " [none]";
        }
        if(tree->right!=nullptr){
            output = output + " " + DumpTree(tree->right);
        }else{
            output=output+" [none]";
        }
        return output + "]";
    }

    std::unique_ptr <SmartTree> RestoreLeft(const std::string &tree, int closed_brackets_counter, int open_brackets_counter){
        std::unique_ptr <SmartTree> root;
        int i=0;
        int value_int;
        std::string value_str="";
        std::string leftsubstree;
        std::string rightsubtree;
        while(true){
            if(tree[i]=='[' && (i+1<tree.size() && tree[i+1]!='n')){
                open_brackets_counter++;
            }
            if(tree[i]==']' &&(i-1>0 && tree[i-1]!='e')){
                closed_brackets_counter++;
            }
            if(tree[i]=='[' && (i+1<tree.size() && tree[i+1]=='n')){
                root=nullptr;
                break;
            }
            if(47<tree[i]<58){
                value_str=value_str+tree[i];
            }
            if(tree[i]==' '){
                value_int=std::stoi(value_str);
                root = CreateLeaf(value_int);
                value_str="";
                for(int j=i; j<tree.size()-1; j++){
                    if(tree[j]=='[' && (j+1<tree.size() && tree[j+1]=='n')){
                        open_brackets_counter++;
                    }
                    if(tree[j]==']' &&(j-1>0 && tree[j-1]=='e')){
                        closed_brackets_counter++;
                    }
                    if(open_brackets_counter-1==closed_brackets_counter){
                        leftsubstree=tree.substr(i, j);
                        rightsubtree=tree.substr(j, tree.size()-1-j);
                        root = InsertLeftChild(move(root), RestoreLeft(leftsubstree,closed_brackets_counter, open_brackets_counter));
                        root = InsertRightChild(move(root), RestoreRight(rightsubtree, closed_brackets_counter, open_brackets_counter));
                        break;
                    }
                }
            }
            i++;
        }
        return root;
    }
    std::unique_ptr <SmartTree> RestoreRight(const std::string &tree, int closed_brackets_counter, int open_brackets_counter){
        std::unique_ptr <SmartTree> root;
        int i=0;
        int value_int;
        std::string value_str="";
        std::string leftsubstree;
        std::string rightsubtree;
        while(true){
            if(tree[i]=='[' && (i+1<tree.size() && tree[i+1]!='n')){
                open_brackets_counter++;
            }
            if(tree[i]==']' &&(i-1>0 && tree[i-1]!='e')){
                closed_brackets_counter++;
            }
            if(tree[i]=='[' && (i+1<tree.size() && tree[i+1]=='n')){
                root=nullptr;
                break;
            }
            if(47<tree[i]<58){
                value_str=value_str+tree[i];
            }
            if(tree[i]==' '){
                value_int=std::stoi(value_str);
                root = CreateLeaf(value_int);
                value_str="";
                for(int j=i; j<tree.size()-1; j++){
                    if(tree[j]=='[' && (j+1<tree.size() && tree[j+1]=='n')){
                        open_brackets_counter++;
                    }
                    if(tree[j]==']' &&(j-1>0 && tree[j-1]=='e')){
                        closed_brackets_counter++;
                    }
                    if(open_brackets_counter-1==closed_brackets_counter){
                        leftsubstree=tree.substr(i, j);
                        rightsubtree=tree.substr(j, tree.size()-1-j);
                        root = InsertLeftChild(move(root), RestoreLeft(leftsubstree,closed_brackets_counter, open_brackets_counter));
                        root = InsertRightChild(move(root), RestoreRight(rightsubtree, closed_brackets_counter, open_brackets_counter));
                        break;
                    }
                }
            }
            i++;
        }
        return root;
    }
    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree){
        std::cout<<"restore";
        std::unique_ptr<SmartTree> root;
        std::unique_ptr<SmartTree> left_child;
        std::unique_ptr<SmartTree> right_child;
        std::string value_str="";
        std::string helping_str=tree;
        int open_brackets_counter=0;
        int closed_brackets_counter=0;
        int closed_brackets_counter_bis;
        int open_brackets_counter_bis;
        int char_to_int;
        int value_int;
        int i=0;
        int bracket_position;
        std::string leftsubstree;
        std::string rightsubtree;

        while(true){
            if(tree[i]=='[' && (i+1<tree.size() && tree[i+1]!='n')){
                open_brackets_counter++;
            }
            if(tree[i]==']' &&(i-1>0 && tree[i-1]!='e')){
                closed_brackets_counter++;
            }
            if(tree[i]=='[' && (i+1<tree.size() && tree[i+1]=='n')){
                root=nullptr;
                break;
            }
            if(47<tree[i]<58){
                value_str=value_str+tree[i];
            }
            if(tree[i]==' '){
                value_int=std::stoi(value_str);
                root = CreateLeaf(value_int);
                value_str="";
                for(int j=i; j<tree.size()-1; j++){
                    if(tree[j]=='[' && (j+1<tree.size() && tree[j+1]=='n')){
                        open_brackets_counter++;
                    }
                    if(tree[j]==']' &&(j-1>0 && tree[j-1]=='e')){
                        closed_brackets_counter++;
                    }
                    if(open_brackets_counter-1==closed_brackets_counter){
                        leftsubstree=tree.substr(i, j);
                        rightsubtree=tree.substr(j, tree.size()-1-j);
                        root = InsertLeftChild(move(root), RestoreLeft(leftsubstree,closed_brackets_counter, open_brackets_counter));
                        root = InsertRightChild(move(root), RestoreRight(rightsubtree, closed_brackets_counter, open_brackets_counter));
                        break;
                    }
                }
            }
            i++;
        }

/*

        while(i<tree.size()){
            if(tree[i]=='[' && (i+1<tree.size() && tree[i+1]!='n')){
                open_brackets_counter++;
                bracket_position=i;
            }
            if(tree[i]==']' && (i-1>0 && tree[i-1]!='e')){
                closed_brackets_counter++;
            }
            if(47<tree[i]<58){
                value_str=value_str+tree[i];
            }
            if(tree[i]==' '){
                if(value_str!=""){
                    value_int=std::stoi(value_str);
                    root = CreateLeaf(value_int);
                    helping_str.erase(helping_str.size()+i);
                    value_str="";
                    while(int j=i+1<tree.size()){
                        if(47<tree[j]<58){
                            value_str=value_str+tree[j];
                        }else{
                            helping_str.erase(helping_str.size()+j-(i+1));
                            root = InsertLeftChild(move(root), RestoreTree(helping_str));
                            break;
                        }
                        j++;
                    }
                }
                closed_brackets_counter_bis = closed_brackets_counter;
                open_brackets_counter_bis = open_brackets_counter;
                while(int j=i+1<tree.size()){
                    if(tree[i]==']' && (i-1>0 && tree[i-1]!='e')){
                        closed_brackets_counter_bis++;
                    }
                    if(tree[i]=='[' && (i+1<tree.size() && tree[i+1]!='n')){
                        open_brackets_counter_bis++;
                        bracket_position=i;
                    }

                    if(closed_brackets_counter_bis+1==open_brackets_counter_bis){
                        value_str="";
                        while(int k=j+1<tree.size()){
                            if(47<tree[k]<58) {
                                value_str = value_str + tree[k];
                            }else{
                                helping_str=tree;
                                helping_str.erase(tree.begin()+j);
                                root = InsertRightChild(move(root), RestoreTree(helping_str));
                            }
                        }
                    }
                    j++;
                }
                if(tree[i]=='[' && (i+1<tree.size() && tree[i]=='n')){
                    root = nullptr;
                    return root;
                }
            }
            i++;
        }*/

        /*for(int i=0; i<tree.size(); i++){
            std::cout<<"tree[i]"<<tree[i]<<std::endl;
            char_to_int = tree[i];
            if(tree[i]=='[' && (i+1<tree.size() && tree[i+1]!='n')){
                open_brackets_counter++;
              //  helping_str.erase(helping_str.begin(), helping_str.begin()+i);
              //  RestoreTree(helping_str);
                if(value_str!=""){
                    //akcja z przepchnięciem
                }
            }
            if(tree[i]=='[' && tree[i+1]=='n'){
                i=i+5;
                root = nullptr;
                return root;
            }
            if(tree[i]==']' && (i-1>0 && tree[i-1]!='e')){
                closed_brackets_counter++;
                return root;
            }

            if(47<char_to_int && char_to_int<58){
                value_str=value_str+tree[i];
                std::cout<<"value moje z"<<tree[i]<<" to "<<char_to_int<<" więc wartość value str to "<<value_str<<std::endl;
            }

            if(tree[i]==' ' && value_str!=""){
                std::cout<<"tworzę roota o value"<<value_str<<std::endl;
                value_int = std::stoi(value_str);
                root = CreateLeaf(value_int);
                std::cout<<"otwartych"<< open_brackets_counter<<" zamkniętych "<<closed_brackets_counter<<std::endl;
                if(open_brackets_counter-1==closed_brackets_counter){
                    helping_str.erase(helping_str.begin(), helping_str.begin()+i);
                    right_child = (RestoreTree(helping_str));
                    root = InsertRightChild(move(root), move(right_child));

                }else{
                    if(open_brackets_counter-1>closed_brackets_counter){
                    helping_str.erase(helping_str.begin(), helping_str.begin()+i);
                    left_child = (RestoreTree(helping_str));
                    root = InsertLeftChild(move(root), move(left_child));
                    }
                value_str="";
                }
            }

        }return root;*/

    }

}