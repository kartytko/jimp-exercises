//
// Created by kartytko on 12.04.17.
//

#include "StudentRepository.h"
#include <iostream>
#include <strstream>

namespace academia{
    //konstruktory
    StudyYear::StudyYear(){
        study_year_ = 1;
    }

    StudyYear::StudyYear(int study_year){
        study_year_ = study_year;
    }

    StudyYear::~StudyYear(){}



    //funkcje
    int StudyYear::GetYear(){
        return study_year_;
    }

    void StudyYear::SetYear(int new_year){
        study_year_ = new_year;
    }




    //operatory
    StudyYear & StudyYear::operator++(){
        study_year_++;
        return *this;
    }

    StudyYear & StudyYear::operator--(){
        study_year_--;
        return *this;
    }

    StudyYear::operator int() const{
        return this->study_year_;

    }

    bool StudyYear::operator == (const StudyYear &new_study_year)const{
        return study_year_==new_study_year.study_year_;
    }

    bool StudyYear::operator == (const int &study_year) const{
        return study_year_ == study_year;
    }

    bool StudyYear::operator<(const StudyYear &new_study_year)const{
        return study_year_ < new_study_year.study_year_;
    }


    int ReadNumber(std::istream* is) {
        int d;
        (*is) >> d;
        return d;
    }

    std::istream& operator>>(std::istream &in, StudyYear& study_year){
        study_year.SetYear(ReadNumber(&in));
        return in;
    }

    std::ostream& operator<<(std::ostream &out, StudyYear &study_year){
        out<<study_year.GetYear();
        return out;
    }

}