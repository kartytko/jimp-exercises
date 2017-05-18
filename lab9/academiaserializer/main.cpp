//
// Created by kartytko on 09.05.17.
//

#include <iostream>
#include "Serialization.h"
using namespace academia;

int main(){
/*
    BuildingRepository repository{};
    Building
            b1{101, "B-1", {Room {101301, "H-24", Room::Type::LECTURE_HALL}, Room {102683, "021", Room::Type::COMPUTER_LAB}}};
    Building b2{102, "B-2", {}};
    Building c2{103, "C-2", {Room {100110, "208", Room::Type::COMPUTER_LAB}}};
    std::stringstream out;
    XmlSerializer serializer{&out};

    repository.Add(b1);
    repository.Add(b2);
    repository.Add(c2);

    out<<"hej";

    std::cout<<out.str();
*/
    std::cout<<"siema-1";
    BuildingRepository repository{};
    Building
            b1{101, "B-1", {Room {101301, "H-24", Room::Type::LECTURE_HALL}, Room {102683, "021", Room::Type::COMPUTER_LAB}}};
    Building b2{102, "B-2", {}};
    Building c2{103, "C-2", {Room {100110, "208", Room::Type::COMPUTER_LAB}}};
    std::cout<<"siema0";
    repository.Add(b1);
    repository.Add(b2);
    repository.Add(c2);

    std::cout<<"siema";
     std::experimental::optional<Building> ob1 = repository[101];
    /*  std::cout<<"siema2";
     Building &b1_ref = ob1.value();
     std::cout<<"siema3";
     std::cout<<b1_ref.Id()<<std::endl;
     std::cout<<repository[102].value().Id()<<std::endl;
     std::cout<<repository[103].value().Id()<<std::endl;
 */
    return 0;
}
