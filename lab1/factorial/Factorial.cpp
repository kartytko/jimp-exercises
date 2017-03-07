//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

int factorial(int value) {

    if(value>12 || value<-12){
        return 0;
    }

    if(value==0){
        return 1;
    }

    if(value>0) {
        int wynik = 1;
        for (int i = 1; i <= value; i++) {
            wynik = wynik * i;
        }

        return wynik;
    }

    if(value<0){
        int wynik = 1;
        for (int i=-1; i>=value; i--){
            wynik = wynik*i;
        }
        return wynik;
    }
}
