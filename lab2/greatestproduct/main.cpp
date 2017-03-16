//
// Created by kartytko on 11.03.17.
//

#include <iostream>
#include "GreatestProduct.h"
#include <vector>


using std::cout;
using std::endl;
using std::vector;
using std::cin;

int main(){
    int greatestproduct;
    int vector_length;
    int single_number;
    int factors_number;
    vector <int> numbers;

    cout << "Ile liczb chcesz wprowadzić?"<<endl;
    cin >> vector_length;

    for(int i=0; i<vector_length; i++){
        cout<<"Podaj liczbę do tablicy"<<endl;
        cin>>single_number;
        numbers.push_back(single_number);
    }
    cout << "Z ilu czynników ma składać się iloczyn?";
    cin >> factors_number;


    greatestproduct = GreatestProduct(numbers, factors_number);

    cout << greatestproduct;


    return 0;
}