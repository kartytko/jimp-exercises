//
// Created by kartytko on 06.03.17.
//

#include <iostream>
#include <string>
#include "Palindrome.h"

using namespace std;

int main() {

    bool dzialanie = true;
    char opcja;
    string slowo;
    bool is;

    while(dzialanie){

        cout<<"(S)prawdź palindrom / (W)yjście" << endl;
        cin>>opcja;

        if(opcja=='S'){
            cout<<"Wprowadź słowo " << endl;
            cin>>slowo;
            is = is_palindrome(slowo);

            if(is==1){
                cout << "Jest palindromem" << endl;
            }
            else{
                cout << "Nie jest palindromem" << endl;
            }
        }

        if(opcja=='W'){
            dzialanie=false;
        }

        if(opcja!='W' && opcja!='S'){
            cout<<"Błędna komenda"<<endl;
        }
    }

    return 0;
}
