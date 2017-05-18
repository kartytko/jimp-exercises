//
// Created by kartytko on 16.05.17.
//

#include "Scheduler.h"
#include <iostream>
using namespace academia;

int main(){

    Schedule schedule;
    schedule.InsertScheduleItem(SchedulingItem {0, 1, 2, 3, 4});
    schedule.InsertScheduleItem(SchedulingItem {5, 6, 7, 8, 9});

    Schedule firstTeacherSchedule = schedule.OfTeacher(1);
    for(auto &a: schedule.schedule_){
        std::cout<<a.TeacherId()<<std::endl;
    }

    return 0;
}