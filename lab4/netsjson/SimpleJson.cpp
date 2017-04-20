//
// Created by kartytko on 27.03.17.
//

#include "SimpleJson.h"
#include <experimental/optional>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <regex>
using ::std::literals::operator""s;

namespace nets{

    JsonValue::JsonValue(){};
    JsonValue::JsonValue (std::string str){
        string_value_ = std::experimental::make_optional(str);
    }
    JsonValue::JsonValue(int integer){
        int_value_ = std::experimental::make_optional(integer);
    }
    JsonValue::JsonValue(double double_number){
        double_value_ = std::experimental::make_optional(double_number);
    }
    JsonValue::JsonValue(bool bool_lean){
        bool_value_ = std::experimental::make_optional(bool_lean);
    }
    JsonValue::JsonValue(std::vector <JsonValue> json_vector){
        json_vector_=std::experimental::make_optional(json_vector);
    }
    JsonValue::JsonValue(std::map<std::string, JsonValue> json_map){
        json_map_ = std::experimental::make_optional(json_map);
    }
    JsonValue::~JsonValue(){    };

    std::experimental::optional <JsonValue> JsonValue::ValueByName(const std::string &name) const{
        if(json_map_){
            for(auto &m: *json_map_){
                if(m.first==name){
                    auto answer = std::experimental::make_optional(m.second);
                    return answer;
                }
            }
        }
    }

    std::string JsonValue::ToString() const{
        std::string result="";

        if(string_value_){
            std::string helping_str=*string_value_;
            result="\""+*string_value_+"\"";
            //for(int i=0; i<helping_str.size(); i++){
            //    std::cout<<helping_str[i]<<" <- iteracja "<<i<<std::endl;
           /*     if(helping_str[i]==92){
                    result=result+"\\";
                }
                if(helping_str[i]==34){
                    result=result+"\\";
                }
                result=result+helping_str[i];
            }*/
            //result = *string_value_;
        }


        if(bool_value_){
            if((*bool_value_)==true){
                result = "true";
            }else{
                result = "false";
            }
        }


        if(int_value_){
            result = std::to_string((*int_value_));
        }

        if(json_vector_){
            result="[";
            bool first = true;
            for(auto a: (*json_vector_)){
                if(first){
                    result= result + a.ToString();
                    first=false;
                }else{
                    result= result +", "+ a.ToString();
                }
            }
            result=result+"]";

        }

        if(json_map_){
            for(auto &b: *json_map_){
                result = b.first + b.second.ToString();
            }
        }

        if(double_value_){

            std::ostringstream strs;
            strs << (*double_value_);
            result = strs.str();
        }

        return result;
    }
}