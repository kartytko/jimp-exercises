//
// Created by kartytko on 09.03.17.
//

#include "Polybius.h"
#include <iostream>
#include <string>
#include <cmath>


std::string PolybiusCrypt(std::string message){
    const char* characters = message.c_str();
    size_t size = message.size();

    std::string crypted_message="";
    std::string row, column;
    int number;



    for(int i=0; i<size; i++){
        if(characters[i]==' '){
            continue;
        }

        //zmiana poszczegolnych liter na cyfry, gdzie (a=1, b=2 ... i/j=9, k=10 ...)
        if(characters[i]>=97){
            if(characters[i]<=105){
                number = characters[i] - 96;
            }else{
                number = characters[i] - 97;            // male litery
            }

        }
        else{
            if(characters[i]<=73){
                number = characters[i] - 96 + 32;
            }else{
                number = characters[i] - 97 + 32;       // wielkie litery
            }
        }


        switch(number%5){                               //wyznaczanie numeru kolumny
            case 1:
                column = std::to_string(1);
                break;
            case 2:
                column = std::to_string(2);
                break;
            case 3:
                column = std::to_string(3);
                break;
            case 4:
                column = std::to_string(4);
                break;
            default:
                column = std::to_string(5);
                break;
        }

        number = number-1;
        switch(int(floor(number/5))){                   //wyznaczanie numeru wiersza
            case 0:
                row = std::to_string(1);
                break;
            case 1:
                row = std::to_string(2);
                break;
            case 2:
                row = std::to_string(3);
                break;
            case 3:
                row = std::to_string(4);
                break;
            default:
                row = std::to_string(5);
                break;
        }

        crypted_message = crypted_message + row + column;
    }

    return crypted_message;
}


std::string PolybiusDecrypt(std::string crypted){

    const char* characters = crypted.c_str();
    size_t size = crypted.size();

    std::string encrypted = "";
    char current_char;


    char alphabet[5][5];
    int row, column;
    int counter = 97;  //numer litery w kodzie ASCII


    //tworzenie tablicy 5x5, szachownicy Polibiusza
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            alphabet[i][j]=counter;
            counter++;

            if(counter==106)            //kiedy counter wskazuje na litere 'j'
                counter++;
        }
    }


    for(int i=0; i<size; i++){
        if(i%2==0){
            row = int(characters[i])-48;
        }
        else{
            column = int(characters[i])-48;
            current_char = alphabet[row-1][column-1];
            encrypted = encrypted + current_char;
        }
    }
    return encrypted;

}