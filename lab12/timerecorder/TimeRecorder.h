//
// Created by kartytko on 06.06.17.
//


#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H
#include<iostream>
#include <chrono>
namespace profiling {

    template<typename T>
    auto TimeRecorder(T t){
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();
        auto n=(t)();
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        return std::make_pair(n ,elapsed_seconds.count()*1000);
    };
}



#endif //JIMP_EXERCISES_TIMERECORDER_H