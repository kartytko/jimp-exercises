//
// Created by kartytko on 12.03.17.
//

#include "XorCypherBreaker.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


using std::find;
using std::vector;
using std::string;


void PrintVector(const vector<string> &v) {
        bool first = true;
        for(auto n : v) {
                if (!first) {
                        std::cout<< ", ";
                } else {
                        first = false;
                }
                std::cout << n;

        }
        std::cout<<std::endl;
}

string XorCypherBreaker(const vector<char> &cryptogram, int key_length, const vector<string> &dictionary){

        vector <string> new_vector;
        string single_word="";
        char single_character;
        int single_character_int;
        bool found = false;
        char char_key1, char_key2, char_key3;
        string key="";
        string key2 = "32s4";
        int counter=0;
        int previous_counter=0;
        int optimization_size=cryptogram.size();
        if(cryptogram.size()>200){
                optimization_size = 200;
        }

        for(int x=0; x<26; x++){
                for(int y=0; y<26; y++){
                        for(int z=0; z<26; z++){
                                for(int i=0; i<optimization_size; i++){

                                        if(i%3==0){
                                                single_character = cryptogram[i] ^ (97+x);
                                                single_character_int = single_character;
                                        }


                                        if(i%3==1){
                                                single_character = cryptogram[i] ^ (97+y);
                                                single_character_int = single_character;
                                        }


                                        if(i%3==2) {
                                                single_character = cryptogram[i] ^ (97 + z);
                                                single_character_int = single_character;
                                        }




                                         if(91>single_character_int && single_character_int>64){
                                                single_word=single_word+single_character;
                                                        //std::cout<<"jestem tu "<<std::endl;

                                         }
                                         else{
                                                if(123>single_character && single_character_int>96){
                                                        single_word=single_word+single_character;
                                                               // std::cout<<"jestem tu1 "<<std::endl;
                                                }else{
                                                        if(single_word==""){
                                                                single_word.push_back(single_character);
                                                                new_vector.push_back(single_word);
                                                                single_word = "";
                                                        }
                                                        else{
                                                                new_vector.push_back(single_word);
                                                                single_word="";
                                                                single_word.push_back(single_character);
                                                                new_vector.push_back(single_word);
                                                                single_word="";
                                                        }
                                                }
                                         }
                                }


                                        for(int b=0; b<dictionary.size(); b++){
                                                if(find(new_vector.begin(), new_vector.end(), dictionary[b]) != new_vector.end()){                     //po petli i;
                                                        counter++;
                                                       // std::cout<<"znalazlem "<<x<<" "<<y<<" "<<z<<" "<<dictionary[b]<<std::endl;
                                                        if(counter>previous_counter){
                                                                key = "";
                                                                char_key1 = x+97;
                                                                char_key2 = y+97;
                                                                char_key3 = z+97;

                                                                key.push_back(char_key1);
                                                                key.push_back(char_key2);
                                                                key.push_back(char_key3);
                                                                previous_counter = counter;
                                                                // std::cout<<"Kod to "<< char_key1 << " " <<char_key2 << "  " << char_key3 <<std::endl;
                                                                //std::cout<<key;
                                                              //  found = true;
                                                               // break;
                                                        }
                                                }
                                        }

                                        counter=0;
                                        new_vector.clear();
                                        if(found==true)
                                                break;

                        }
                        if(found==true)
                                break;

                }
                if(found==true)
                        break;
        }

        return key;
}
