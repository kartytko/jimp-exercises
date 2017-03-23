//
// Created by kartytko on 16.03.17.
//

#include <iostream>
#include <regex>
#include "MinimalTimeDifference.h"

using namespace std;
int main(){
    regex pattern {R"((\d{1,2}):(\d{1,3}))"};
    string line {"51:78"};
    smatch matches;
    if (regex_match(line, matches, pattern)) {
        cout<<"udało się dopasować do linii: "<<line<<endl;
        cout<<"zerowa grupa przechwytująca to całe dopasowanie: "<<matches[0]<<endl;
        cout<<"pierwsza grupa przechwytująca to napis: "<<matches[1]<<endl;
        cout<<"druga grupa przechwytująca to liczba: "<<matches[2]<<endl;
    }

    return 0;
}

