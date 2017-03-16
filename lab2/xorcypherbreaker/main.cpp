//
// Created by kartytko on 12.03.17.
//

#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int ToBinary(int dec){
    int decimal = dec;
    int binary;
    string remainder_char;
    string binary_str;
    int remainder;

    while(decimal!=0){
        remainder = decimal%2;
        decimal = (decimal-remainder)/2;
        remainder_char = std::to_string(remainder);
        binary_str = binary_str + remainder_char;
    }

    binary = std::stoi(binary_str);
    return binary;
}

int main(){



    return 0;
}