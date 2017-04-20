//
// Created by kartytko on 27.03.17.
//

#include <iostream>
#include <experimental/optional>
#include <string>
#include <typeinfo>
#include <sstream>
#include <map>
#include <vector>


double foo(){
    return 0;
}
//int optional(int a){
//   return 1;
//}

double double_value(){
    return 7.43;
}
int main(){


    std::experimental::optional <double> double_value;
    std::ostringstream strs;
    double gunwo = -107.89;
    double_value = std::experimental::make_optional(gunwo);
    strs << *double_value;
    std::cout<<"double_value w stringu " <<strs.str()<<" i zwykle "<< gunwo << " "<< *double_value<<std::endl;

    std::experimental::optional <std::map<int, std::string>> cus;
    std::map<int, std::string> cus2= {{7, "hej"}};
    cus = std::experimental::make_optional(cus2);
    for(auto a: *cus){
        std::cout<<a.first<<" "<<a.second;
    }
    std::string helping_str="\"hi\"";
    std::cout<<helping_str;
    std::string result="";
    for(int i=0; i<helping_str.size(); i++){
        std::cout<<"helpingstr["<<i<<"] to "<<helping_str[i]<<std::endl;
        if(helping_str[i]=='"') {
            result = result + "\\";
        }
        result=result+ helping_str[i];
    }
    std::cout<<std::endl<<result<<" "<<helping_str;

    /*   std::string slowo = "hej";
    std::string slowo2;
    int k;
    double dob;
    std::cout << typeid(slowo).name()<< std::endl;
    std::cout << typeid(slowo2).name()<< std::endl;
    std::cout << typeid(k).name()<< std::endl;
    std::cout << typeid(dob).name()<< std::endl;

    if(typeid(k)== typeid(int)){
        std::cout<<"jest"<<std::endl;;
    }else{
        std::cout<<"niejest"<<std::endl;;
    }(*/
    return 0;
}