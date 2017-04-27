//
// Created by kartytko on 14.03.17.
//

#include "TinyUrl.h"
#include <iostream>
#include <utility>
#include <string>
#include <array>
#include <memory>
#include <map>

namespace tinyurl{

    std::unique_ptr<TinyUrlCodec> Init(){
        std::unique_ptr<TinyUrlCodec> pointer = std::make_unique<TinyUrlCodec>();
        return pointer;
    }

    void NextHash(std::array<char, 6> *state){
        int i = 5;
        bool further=false;
        while(i>=0){
            (*state)[i]+=1;
            if((*state)[i]==58){   //pierwszy znak po '9'
                (*state)[i]=65;
                break;
            }
            if((*state)[i]==91){    //pierwszy znak po 'Z'
                (*state)[i]=97;
                break;
            }
            if((*state)[i]==123){   //pierwszy znak po 'z'
                (*state)[i]=48;
                i--;
                further=true;
            }
            if(further==false){
                break;
            }
            further=false;
        }
    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec){
        std::string shortcut;
        std::string latest_hash="000000";
        std::array<char, 6> hash_array;
        bool present=false;

        for(auto a: codec->get()->mymap2){
            if(a.first==url){
                shortcut=a.second;
                present=true;
            }
            latest_hash=a.second;
        }
        if(present==false){
            for(int i=0; i<hash_array.size(); i++){
                hash_array[i]=latest_hash[i];
            }
            NextHash(&hash_array);
            for(int i=0; i<hash_array.size(); i++){
                shortcut.push_back(hash_array[i]);
            }
            codec->get()->mymap2.emplace(url, shortcut);
        }
        return shortcut;
     }


    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash){
        std::string coded_url;
        for(auto a: codec->mymap2){
            if(a.second==hash){
                coded_url=a.first;
            }
        }
        return coded_url;
    }
}