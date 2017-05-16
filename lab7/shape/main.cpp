//
// Created by ela on 24.04.17.
//

#include <iostream>
#include "Shape.h"
#include <vector>
#include <cstdlib>
#include <ctime>

int main(){

    int random;
    std::vector <Ksztalt*> wektor;
    std::srand(std::time(0));

    for(int i=0; i<3; i++){
        random = rand() % 100;

        if(random%3==0){
            wektor.push_back(new Trojkat);
        }else {
            if(random%3==1){
                wektor.push_back(new Kwadrat);
            }else{
                wektor.push_back(new Kolo);
            }
        }
    }
    for(auto a: wektor){
        a->rysuj();
    }

    for(auto b: wektor){
        delete b;
    }

    return 0;
}