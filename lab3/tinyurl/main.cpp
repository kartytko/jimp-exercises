//
// Created by kartytko on 14.03.17.
//
#include "TinyUrl.h"
#include <iostream>
#include <regex>
#include <string>

int main(){
    std::string coded;
    std::string url;
    std::string coded2;
    std::string url2;
    std::unique_ptr<tinyurl::TinyUrlCodec> pointer = tinyurl::Init();
    coded = tinyurl::Encode("http://onet.pl/", &pointer);
    std::cout<<"Zahaszowany adres to:"<<coded<<std::endl;
    url = tinyurl::Decode(pointer, coded);
    std::cout<<"Adres tej strony to: "<<url<<std::endl;
    coded2 = tinyurl::Encode("http://pudelek.pl/", &pointer);
    std::cout<<"Zahaszowany adres to:"<<coded2<<std::endl;
    url2 = tinyurl::Decode(pointer, coded2);
    std::cout<<"Adres tej strony to: "<<url2<<std::endl;

    if(coded==coded2){
        std::cout<<"niejednoznaczne haszowanie";
    }

    return 0;
}