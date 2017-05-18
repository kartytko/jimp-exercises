//
// Created by kartytko on 15.04.17.
//

#include <iostream>
#include "WordCounter.h"
#include <ostream>
#include <fstream>

using ::datastructures::WordCounter;
using ::datastructures::Counts;
using ::datastructures::Word;

int main(){

    std::ifstream is ("/home/kartytko/Pulpit/repo/exercises/lab6/wordcounter/myfile.txt");
    WordCounter wc = WordCounter::FromInputStream(is);

    int ilosc = wc["programowanie"];

    std::cout<<"oto ilosc wystapienia slowa \"programowanie\" "<<ilosc<<std::endl;

    return 0;
}