//
// Created by kartytko on 06.03.17.
//

#include "Palindrome.h"
#include <string>
#include <iostream>

using namespace std;

bool is_palindrome(string str) {

    const char *characters = str.c_str();
    size_t size = str.size();
    int j = size-1;
    bool is=true;

    if(size==0 || size==1){
        return is;
    }

    for(int i=0; i<size; i++) {
        if (characters[i] != characters[j]) {
            is=false;
        }

        j=j-1;

        if(j<i){
            break;
        }
    }

    return is;
}

