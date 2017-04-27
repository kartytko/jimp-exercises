//
// Created by kartytko on 25.03.17.
//

#include <iostream>
#include "SimpleUrl.h"
#include <regex>

int main(){
    std::regex pattern {R"((\w+):(\w+)*\/{0,2}@*((\w+-*\.*)*(com|pl|info|net|org|ge)):*(\d+)*(\/(\w|\d|[^a-zA-z0-9\s\?\#])+)*\?*((\w|\d|[^a-zA-z0-9\s\?\#])+)*#*((\w|\d|[^a-zA-z0-9\s])+)*)"};
    std::string line="mailto:someone@example.com?subject=This%20is%20the%20subject&cc=someone_else@example.com&body=This%20is%20the%20body";
    std::smatch match;
    if(std::regex_match(line, match, pattern)){
        std::cout<<"scheme: "<<match[1]<<std::endl;
        std::cout<<"login: "<<match[2]<<std::endl;
        std::cout<<"host: "<<match[3]<<std::endl;
        std::cout<<"port: "<<match[6]<<std::endl;
        std::cout<<"path: "<<match[7]<<std::endl; //usunąć pierwszego  slasha
        std::cout<<"query: "<<match[9]<<std::endl;
        std::cout<<"fragment: "<<match[11]<<std::endl;

    }
    std::cout<<std::endl;
    std::string line3 = "http://geofl.ge/#!/page_saxelmdzvanelo";
    nets::SimpleUrl url1(line3);
    std::string login = url1.Login();
    std::cout<<"scheme: "<<url1.Scheme()<<std::endl;
    std::cout<<"login: "<<url1.Login()<<std::endl;
    std::cout<<"host: "<<url1.Host()<<std::endl;
    std::cout<<"port: "<<url1.Port()<<std::endl;
    std::cout<<"path: "<<url1.Path()<<std::endl; //usunąć pierwszego  slasha
    std::cout<<"query: "<<url1.Query()<<std::endl;
    std::cout<<"fragment: "<<url1.Fragment()<<std::endl;
    return 0;
}