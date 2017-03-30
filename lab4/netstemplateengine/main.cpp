//
// Created by kartytko on 26.03.17.
//

#include <iostream>
#include "SimpleTemplateEngine.h"
#include <unordered_map>
int main(){
    std::unordered_map<std::string, int> elo={{"hej", 1}, {"eldo", 2}, {"moja", 3}, {"plis", 4}};
    for(auto m: elo){
        std::cout<<m.first<<" "<<m.second<<std::endl;
    }
    return 0;
}