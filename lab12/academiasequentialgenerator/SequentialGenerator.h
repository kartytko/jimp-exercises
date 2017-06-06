//
// Created by DELL on 05.06.2017.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

#include <iostream>

template<class T, class U>
class SequentialIdGenerator {
public:
    SequentialIdGenerator(){
        id_=0;
        iter_=0;
    };
    ~SequentialIdGenerator(){};
    SequentialIdGenerator(U id){
        id_=id;
        iter_=0;
    }
    T NextValue(){
        if(iter_==0){
            iter_++;
            return int(id_);
        }
        else{
            ++id_;
            return int(id_);
        }
    }
private:
    U id_;
    int iter_;
};


#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
