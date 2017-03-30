//
// Created by kartytko on 16.03.17.
//

#include "CCounter.h"
#include <iostream>
#include <string>
#include <memory>
#include <map>


namespace ccounter{

    std::unique_ptr<Counter> Init() {
        std::unique_ptr<Counter> counter = std::make_unique<Counter>();
        return counter;
    }

    void Inc(std::string key, std::unique_ptr<Counter> *counter) {
        std::cout<<"inc  "<<key<<std::endl;
        bool is_object=false;
        for(auto &a: counter->get()->mymap){
            if(a.first==key){
                a.second++;
                is_object=true;
            }
        }
        if(is_object==false){
            counter->get()->mymap.emplace(key, 1);
        }
        for(auto a: counter->get()->mymap){
            std::cout<<a.first<<" "<<a.second<<std::endl;
        }
    }

    int Counts(const std::unique_ptr<Counter> &counter, std::string key) {
        int object_counter=0;

        std::cout<<"to jest key: "<<key<<std::endl;
        for(auto m: counter->mymap){
            if(m.first==key){
                object_counter=m.second;
            }
        }
       return object_counter;
    }

    void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter) {
        for (auto &a: counter->get()->mymap){
            if(a.first==key){
                a.second=value;
            }
        }
    }
}