//
// Created by kartytko on 06.06.17.
//


#include "TeacherHash.h"
namespace academia {

    academia::TeacherId::TeacherId() {

    }

    TeacherId::~TeacherId() {

    }

    TeacherId::TeacherId(int id) {
        id_=id;
    }

    TeacherId::operator int() {
        return id_;
    }

    bool TeacherId::operator==(const TeacherId &id) const {
        return id_==id.id_;
    }

    bool TeacherId::operator!=(const TeacherId &id) const {
        return id_!=id.id_;
    }

    int TeacherId::Id() const {
        return id_;
    }

    bool operator==(int i, const TeacherId &id) {
        return i==id.Id();
    }

    Teacher::Teacher() {
    }

    Teacher::~Teacher() {
    }

    Teacher::Teacher(TeacherId id, std::string name, std::string department) {
        id_=id;
        name_=name;
        department_=department;
    }

    TeacherId Teacher::Id() const {
        return id_;
    }

    std::string Teacher::Name() const {
        return name_;
    }

    std::string Teacher::Department() const {
        return department_;
    }

    bool Teacher::operator==(const Teacher &teacher)const {
        return id_==teacher.id_ and name_==teacher.name_ and department_==teacher.department_;
    }

    bool Teacher::operator!=(const Teacher &teacher) const {
        return id_!=teacher.id_ or name_!=teacher.name_ or department_!=teacher.department_;
    }

/*
    size_t TeacherHash::operator()(const Teacher &teacher) const{
        int id1=teacher.Id().Id();
        std::string hash_string1=teacher.Name();
        std::string hash_string2=teacher.Department();
        std::size_t h1 = std::hash<int>{}(id1);
        std::size_t h2=std::hash<std::string>{}(hash_string1);
        std::size_t h3=std::hash<std::string>{}(hash_string2);
        return h1^(h2+h3);
    }
*/
}

