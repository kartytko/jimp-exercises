//
// Created by kartytko on 03.04.17.
//

#include "TextPool.h"
#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <iostream>

namespace pool{
    //domyślny konstruktor
    //konstruktor z listą inicjalizacyjną
    TextPool::TextPool() {}
    TextPool::~TextPool(){
        poolset_.clear();
    }

    //konstruktor przenoszący
    TextPool::TextPool(TextPool &&xxx): poolset_{nullptr}{
        std::swap(poolset_, xxx.poolset_);
    }

    //operator przypisania przenoszący
    TextPool & TextPool::operator=(TextPool &&xxx){
        if (this == &xxx) {
            return *this;
        }
        poolset_.clear();
        std::swap(poolset_, xxx.poolset_);
    }

    TextPool::TextPool (std::initializer_list<std::experimental::string_view> poolset): poolset_(poolset){};

    std::experimental::string_view TextPool::Intern(const std::string &str){
        auto j = poolset_.begin();
        for(auto i = poolset_.begin(); i!=poolset_.end(); i++){
            if(str==*i){
                return *i;
            }
        }
        poolset_.insert(std::experimental::string_view(str));
        for(auto i = poolset_.begin(); i!=poolset_.end(); i++){
            if(str==*i){
                return *i;
            }
        }

    }


    size_t TextPool::StoredStringCount() const{
        size_t j=0;

        for(auto m : poolset_){
            j++;
            if(m=="\0"){
                //  std::cout<<"brejkuję"<<std::endl;
                j--;}

            //std::cout<<"jestem poolset, oto elemnty: "<<m<<std::endl;
        }
        return j;
    }
}