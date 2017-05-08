//
// Created by kartytko on 05.04.17.
//

#include <iostream>
#include "Matrix.h"
#include <complex>

#include <iostream>
#include "Matrix.h"
using namespace std;

int main(int argc, char* argv[]){
    algebra::Matrix m1(argv[1]);
    algebra::Matrix m2(argv[2]);

    cout << "Macierz pierwsza: " << m1.print() << endl;
    cout << "Macierz druga: " << m2.print() << endl;

    cout << "Dodawanie" << (m1.add(m2)).print() << endl;
    cout << "Odejmowanie" << (m1.sub(m2)).print() << endl;
    cout << "Mnożenie" << (m1.mul(m2)).print() << endl;
    cout << "Dzielenie" << (m1.div(m2)).print() << endl;
    cout << "Potęgowanie" << (m1.pow(2)).print() << endl;
    cout << "Potęgowanie" << (m2.pow(2)).print() << endl;
}