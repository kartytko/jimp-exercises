//
// Created by kartytko on 16.03.17.
//

#include <iostream>
#include "CCounter.h"
#include <map>
#include <memory>

using std::cout;
using std::endl;
using std::map;

void PrintMap(const map<std::string,int> &v) {
    bool first = true;
    for(const auto &n : v) {
        if (!first) {
            cout<< ", ";
        } else {
            first = false;
        }
        cout << n.first << " -> " << n.second;

    }
    cout<<endl;
}

int main()
{
    int value=7;

    std::unique_ptr<::ccounter::Counter> pointer = ::ccounter::Init();
    auto pointer2 = &pointer;
    std::string zmienna="ho";
    pointer->mymap.emplace("ho", 7);
    pointer->mymap.emplace("hi", 10);
    PrintMap(pointer->mymap);
    pointer->mymap[zmienna]=10;
    PrintMap(pointer->mymap);


    //WOOOHOOO!

    //   ccounter::Counter mapa;
 //   pointer = &mapa;
 //   mapa.mymap.insert({"hi", 7});





    //auto p = counter.get();

/*
    // Create a vector containing integers
    map<char, int> v = {{'a',17}, {'c',-2}, {'g',67}, {'z',13}};
    char znak = 'a';
    cout << "initilized with 4 numbers"<<endl;
    PrintMap(v);

    // Add two more integers to vector
    v.emplace('h',25);
    v.emplace('$',13);
    cout << "after 2 more inserted"<<endl;
    PrintMap(v);

    //copy of the value inside vector
    for (const auto &n : v) {
        //Compilation error
        //++n.second;
    }

    cout << "BUT: after incrementation"<<endl;
    PrintMap(v);

    //reference to the value inside vector, therefore one can change the value
    for (auto &n : v) {
        ++n.second;
    }

    v[znak]+=1;
    cout << "and again... can you spot the difference?"<<endl;
    PrintMap(v);
*/}