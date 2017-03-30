//
// Created by kartytko on 16.03.17.
//

#ifndef JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H
#define JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H

#include <iostream>
#include <string>
#include <vector>

namespace minimaltimedifference{
    unsigned int ToMinutes(std::string time_HH_MM);
    unsigned int MinimalTimeDifference(std::vector<std::string> times);
    void PrintVector(const std::vector<unsigned int> &v);
}
#endif //JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H
