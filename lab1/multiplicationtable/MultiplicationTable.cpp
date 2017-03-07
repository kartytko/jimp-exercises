//
// Created by kartytko on 06.03.17.
//

#include "MultiplicationTable.h"
#include <iostream>
using namespace std;


void MultiplicationTable(int tab[][10]){
    int liczba;
    for (int i=1; i<=10; i++){
        for (int j=1; j<=10; j++){
            liczba=i*j;
            tab[i-1][j-1]=liczba;
            cout << tab[i-1][j-1] << "   ";
        }
        cout<<endl;
    }

}