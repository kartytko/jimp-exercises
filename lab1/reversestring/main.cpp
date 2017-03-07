//
// Created by kartytko on 06.03.17.
//

#include <iostream>
#include <string>
#include "ReverseString.h"

using namespace std;

int main() {

    string str;

    cout << "Podaj słowo" << endl;
    cin >> str;

   cout << "To słowo od tyłu: " << reverse(str) << endl;

    return 0;
}
