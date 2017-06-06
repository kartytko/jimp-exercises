//
// Created by ela on 15.05.17.
//

#include "Scheduler.h"
namespace academia {

    int SchedulingItem::CourseId() const {
        return course_id;
    }

    int SchedulingItem::TeacherId() const {
        return teacher_id;
    }

    int SchedulingItem::RoomId() const {
        return room_id;
    }

    int SchedulingItem::TimeSlot() const {
        return time_slot;
    }

    int SchedulingItem::Year() const {
        return year;
    }


    Schedule Schedule::OfTeacher(int teacher_id) const {
        std::vector<SchedulingItem> tmp;
        std::vector<SchedulingItem> teacher_;
        std::copy_if(schedulingitem_list_.begin(), schedulingitem_list_.end(), std::back_inserter(tmp),
                     [teacher_id](SchedulingItem i) { return (teacher_id == i.TeacherId()); });
        Schedule ofteacher_(tmp);
        return ofteacher_;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        std::vector<SchedulingItem> tmp;
        std::copy_if(schedulingitem_list_.begin(), schedulingitem_list_.end(), std::back_inserter(tmp),
                     [room_id](SchedulingItem i) { return (room_id == i.RoomId()); });
        Schedule ofroom_(tmp);
        return ofroom_;
    }

    Schedule Schedule::OfYear(int year) const {
        std::vector<SchedulingItem> tmp;
        std::copy_if(schedulingitem_list_.begin(), schedulingitem_list_.end(), std::back_inserter(tmp),
                     [year](SchedulingItem i) { return (i.Year() == year); });
        Schedule year_(tmp);
        return year_;
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        std::vector<int> slots_tmp;
        std::vector<int> slots_;
        for (auto n:schedulingitem_list_)
            slots_tmp.emplace_back(n.TimeSlot());
        for (int i = 1; i <= n_time_slots; i++) {
            if (std::find(slots_tmp.begin(), slots_tmp.end(), i) == slots_tmp.end())
                slots_.emplace_back(i);
        }
        return slots_;
    }

    void Schedule::InsertScheduleItem(const SchedulingItem &item) {
        schedulingitem_list_.emplace_back(item);
    }

    size_t Schedule::Size() const {
        return schedulingitem_list_.size();
    }

    SchedulingItem Schedule::operator[](const int idx) const {
        return schedulingitem_list_[idx];
    }


    Schedule Scheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                           const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                           const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) {
        Schedule schedule;
        std::vector<std::vector<int>> item;
        std::vector<int> v_intersection;

        for (auto n: courses_of_year) {
            if (n.second.size() < n_time_slots) {}
            else
                throw NoViableSolutionFound();
        }
        for (auto n: teacher_courses_assignment) {
            if (n.second.size() < n_time_slots) {}
            else
                throw NoViableSolutionFound();
        }


       int i = 0;
       int m = 0;

        for (auto t:teacher_courses_assignment) {
            for(auto teacher_:t.second) {
                for (auto y:courses_of_year) {
                    for (auto course_:y.second) {
                        if (teacher_==course_ ) {
                            item.push_back({course_ ,t.first,rooms[m],i, y.first});
                            if(m<rooms.size()-1){m++;}
                            i++;
                        }

                    }
                }

            }
        }



            for(int k=0;k<item.size();k++)
                 schedule.InsertScheduleItem(SchedulingItem{item[k][0],item[k][1],item[k][2],item[k][3],item[k][4]});


        return schedule;
    }

}


//
//        std::vector<int> v_intersection;
//        std::vector<int> teachers;
//        for (auto i:teacher_courses_assignment) {
//            for(auto n: i.second)
//                teachers.emplace_back(n);
//        }
//        std::vector<int> courses;
//        std::vector<int> years;
//        for (auto i:courses_of_year) {
//            for(auto n: i.second)
//                courses.emplace_back((n));
//            //for(auto k: i.first)
//            //    years.emplace_back((k));
//
//        }
//        std::set_intersection(teachers.begin(),teachers.end(),
//                              courses.begin(), courses.end(),
//                              std::back_inserter(v_intersection));
//
//
//
//        for(int n : v_intersection)
//            //schedule.InsertScheduleItem(SchedulingItem{n, teachers[n],rooms[n],n_time_slots, 1});
//            item[n].push_back(n);
//
//        for(int n : teachers) {
//            item[n].push_back(n);
//            item[n+1].push_back(rooms[0]);
//            item[n+2].push_back(n_time_slots);
//            item[n+3].push_back(1);
//        }
//
//
//

