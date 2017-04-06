//
// Created by kartytko on 16.03.17.
//

#include "MinimalTimeDifference.h"
#include <vector>
#include <sstream>
#include <regex>
#include <cmath>
#include <iostream>
#include <string>



namespace minimaltimedifference{
    void PrintVector(const std::vector<unsigned int> &v) {
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



    unsigned int ToMinutes(std::string time_HH_MM){
        std::regex time_pattern {R"((\d{1,2}):(\d{2}))"};
        std::smatch matches;
        int hours;
        int minutes;
        std::string hours_str;
        std::string minutes_str;

        if(std::regex_match(time_HH_MM, matches, time_pattern)){
            hours_str = matches[1];
            minutes_str = matches[2];
            hours = std::stoi(hours_str);
            minutes = std::stoi(minutes_str);
        }
        minutes = minutes + hours*60;

        return minutes;
    }

    static const int minutes_amount_in_a_day = 24*60;

    unsigned int MinimalTimeDifference(std::vector<std::string> times){
        using std::string;
        using std::vector;
        vector <unsigned int> minutes;
        int counter=0;
        int minimal_difference= minutes_amount_in_a_day;
        unsigned int minutes_int;

        for(auto n : times){
            minutes_int = ToMinutes(n);
            if(minutes.size()==0){
                minutes.push_back(minutes_int);
            }else{
                for(auto m : minutes){
                    if(minutes_int > minutes[minutes.size()-1]){
                        minutes.push_back(minutes_int);
                        break;
                    }
                    if(minutes_int > m){
                        counter++;
                    }
                    else{
                        minutes.insert(minutes.begin()+counter, minutes_int);
                        break;
                    }
                    //PrintVector(minutes);
                }
                counter = 0;
            }
        }
      //PrintVector(minutes);
      //  std::cout<<"dlugosc minutes to "<<minutes.size();
        for(int i=minutes.size()-1; i>0; i--){
            if(minutes[i]-minutes[i-1]<minimal_difference){
                minimal_difference = minutes[i]-minutes[i-1];
            }
           // std::cout<<"Iteracja "<<i<<" wartosc minimal "<<minimal_difference<<std::endl;
        }
        if((minutes[0] + minutes_amount_in_a_day) - minutes[minutes.size() - 1] < minimal_difference){
            minimal_difference = (minutes[0] + minutes_amount_in_a_day) - minutes[minutes.size() - 1];
           // std::cout<<"uruchomiony if"<<" wartosc minimal "<<minimal_difference<<std::endl;
        }
        minutes.clear();
        return minimal_difference;
    }
}