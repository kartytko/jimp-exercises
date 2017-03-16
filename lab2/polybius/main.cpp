//
// Created by kartytko on 09.03.17.
//

#include <iostream>
#include <fstream>
#include "Polybius.h"

int main(int argc, char** argv){

    if(argc!=4){
        std::cout<<"Niepoprawna ilość argumentów";
        return 0;
    }

    if(*argv[3]=='1'){
        char line[256];

        std::string str_encrypted;

        std::ifstream file (argv[1]);
        std::ofstream encryptedfile (argv[2], std::ios_base::in | std::ios_base::app);

        if(!file)
            std::cout<<"Bład w otwarciu pierwszego pliku";
        if(!encryptedfile)
            std::cout<<"Bład w otwarciu drugiego pliku";

        while(!file.eof()){
            file.getline(line, 256);
            str_encrypted = PolybiusCrypt(line);
            encryptedfile << str_encrypted;
        }
        file.close();
        encryptedfile.close();

    }
    if(*argv[3]=='0') {
        char line[256];
        std::string str_line;

        std::ifstream file (argv[1]);
        std::ofstream decryptedfile (argv[2], std::ios_base::in | std::ios_base::app);

        if(!file){
            std::cout<<"Nie można otworzyć pliku pierwszego";
        }
        if(!decryptedfile){
            std::cout<<"Nie można otworzyć pliku drugiego";
        }
        while(!file.eof()){
            file.getline(line, 256);
            str_line = PolybiusDecrypt(line);
            decryptedfile << str_line;
        }
        decryptedfile.close();
        file.close();
    }
//    std::cout<<"Niepoprawna wartość czwartego argumentu." <<std::endl << "(1) - szyfrowanie " << std::endl << "(2) - odszyfrowywanie";




    return 0;
}
