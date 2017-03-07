//
// Created by kartytko on 06.03.17.
//

#include "DoubleBasePalindromes.h"
#include <cstdint>
#include <string>
#include <iostream>

using namespace std;

//funkcja is_palindrome skopiowana z modułu palindrome
bool is_palindrome(string str) {

    const char *characters = str.c_str();
    size_t size = str.size();
    int j = size-1;
    bool is=true;

    if(size==0 || size==1){
        return is;
    }

    for(int i=0; i<size; i++) {
        if (characters[i] != characters[j]) {
            is=false;
        }

        j=j-1;

        if(j<i){
            break;
        }
    }
    return is;
}


/*bool is_palindrom_numbers(int number){
    int counter = 0;    //sprawdza, ile cyfr ma liczba
    int divider = 1;
    int biggest_divider=1;
    int m;
    bool is=true;

    for(int i=1; i<=7; i++){
        for(int j=1; j<=i; j++){
            divider = divider*10;
        }
        if(number%divider!=0){
            counter=i;
            biggest_divider=divider;
        }
    }

    m = biggest_divider;
    for(int k=1; k<=biggest_divider; k=k*10){
        if(number%k!=number%m){
            is=false;
            return is;
        }
        m=m/10;
        if(m<k){
            break;
        }
    }

    return is;

}
*/

string to_binary(long int dec) {
    string binary_s = "";
    int reszta;
    string reszta_s;
    long int answer;
    while (dec != 0) {
        reszta = dec % 2;
        dec = dec - reszta;
        dec = dec / 2;
        reszta_s = to_string(reszta);
        binary_s = reszta_s + binary_s;
    }
    return binary_s;
}

uint64_t DoubleBasePalindromes(int max_vaule_exculsive){

    bool pali_dec=true;
    string str;
    string binary;
    uint64_t result=0;

    for(int i=1; i<=max_vaule_exculsive; i++){
        str = to_string(i);
        if(is_palindrome(str)==1){
//            cout << i << endl;
            binary = to_binary(i);
            if(is_palindrome(binary)==1){
//                cout<<i << "  "<< binary <<endl;
                result = result+i;
            }
        }

    }
    return result;
}