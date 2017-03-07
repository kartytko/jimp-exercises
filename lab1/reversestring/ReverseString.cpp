//
// Created by kartytko on 06.03.17.
//

#include "ReverseString.h"
#include <string>
#include <iostream>

using namespace std;



string reverse(string str){

    const char *characters = str.c_str();
    size_t size = str.size();
    char first, last;

    last = characters[size-1];
    first = characters[0];

    if(size==1 || size==0){
        return str;
    }
    else{

        str.erase(str.begin()+size-1);
        str.erase(str.begin());


        if(size==2){
            return last+str+first;
        }
        return last+reverse(str)+first;
    }

}

