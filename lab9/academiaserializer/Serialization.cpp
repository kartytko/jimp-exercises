//
// Created by ela on 04.05.17.
//

#include "Serialization.h"
namespace academia {


    Room::Room(int id_) : id_(id_) {}
    Room::Room(const std::string &name_) : name_(name_) {}
    Room::Room(int id_, const std::string &name_, Room::Type type_) : id_(id_), name_(name_), type_(type_) {}
    Room::~Room() {}

    std::string Room::TypeToString(Room::Type type) const {
        switch(type) {
            case Type::COMPUTER_LAB:
                return "COMPUTER_LAB";
            case Type::LECTURE_HALL:
                return "LECTURE_HALL";
            case Type::CLASSROOM:
                return "CLASSROOM";
        }
    }

    void Room::Serialize(Serializer *serializer) const {
        serializer->Header("room");
        serializer->IntegerField("id", id_);
        serializer->StringField("name", name_);
        serializer->StringField("type", TypeToString(type_));
        serializer->Footer("room");
    }

    Serializer::Serializer() {}
    Serializer::~Serializer() {}
    Serializer::Serializer(std::ostream *out): out_(out) {}


    DummySerializer::DummySerializer(std::ostream *out) : Serializer(out) {}
    DummySerializer::~DummySerializer() {}


    Building::Building() {}
    Building::~Building() {}

    void Building::Serialize(Serializer *serializer) const {
        std::vector<std::reference_wrapper<const Serializable>> rooms2;
        for(const Room &r : rooms_){
            rooms2.emplace_back(r);
        }

        serializer->Header("building");
        serializer->IntegerField("id", id_);
        serializer->StringField("name", name_);
        serializer->ArrayField("rooms", rooms2);
        serializer->Footer("building");
    }

    int Building::Id() const{
        return id_;
    }


    XmlSerializer::XmlSerializer() {}
    XmlSerializer::~XmlSerializer() {}
    XmlSerializer::XmlSerializer(std::ostream *out) : Serializer(out) {
    }
    //("<room><id>117<\\id><name>218<\\name><type>COMPUTER_LAB<\\type><\\room>"
    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        std::string helper ="<"+field_name+">";
        *out_<<helper<<value<<"<\\"+field_name+">";
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {}

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        std::string helper ="<"+field_name+">";
        *out_<<helper<<value<<"<\\"+field_name+">";
    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {}
    void XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        *out_ << "<" + field_name + ">";
        value.Serialize(this);
        *out_ << "<\\" + field_name + ">";
    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                   const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        std::string helper = "<"+field_name+">";
        *out_<<helper;
        bool is_first = true;
        for(const Serializable &a: value){
            if (is_first){
                is_first= false;
            }else{
            }
            a.Serialize(this);
        }

        *out_<<"<\\"+field_name+">";

    }
    void XmlSerializer::Header(const std::string &object_name) {
        *out_<<"<"+object_name+">";
    }
    void XmlSerializer::Footer(const std::string &object_name) {
        *out_<<"<\\"+object_name+">";

    }






    JsonSerializer::JsonSerializer() {}
    JsonSerializer::~JsonSerializer() {}
    JsonSerializer::JsonSerializer(std::ostream *out) : Serializer(out) {}

    //("{\"id\": 117, \"name\": \"218\", \"type\": \"COMPUTER_LAB\"}"s, out.str());
    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        std::string helper="\""+field_name+"\": ";
        *out_ << helper <<value;
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {}
    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        std::string helper="\""+field_name+"\": ";
        std::string helper2="\""+value+"\"";
        if(value=="buildings"){
            *out_<<helper<<helper2;
        }else{
        *out_<<", "<<helper<<helper2;
        }
    }
    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {}
    void JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        //*out_<<value;
    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
    std::string helper="";
        if(field_name=="buildings"){
            helper = "\""+field_name+"\": ";
        }else{
            helper = ", \""+field_name+"\": ";
        }
        *out_<<helper + "[";
        bool is_first = true;
        for(const Serializable &a: value){
            if (is_first){
               //*out_<<", ";
                is_first= false;

            }else{
               *out_<<", ";
            }
            a.Serialize(this);
        }
        *out_<<"]";

    }

    void JsonSerializer::Header(const std::string &object_name) {
        *out_  << "{";
    }

    void JsonSerializer::Footer(const std::string &object_name) {
        *out_ << "}";
    }



    BuildingRepository::BuildingRepository(const std::initializer_list <Building> &building_list): buildings_(building_list){}

    void BuildingRepository::Add(const Building &building) {
        buildings_.emplace_back(building);
    }

    std::experimental::optional <Building> BuildingRepository::operator[](int size) const{
        std::experimental::optional <Building> answer;
        for(auto &m: buildings_){
            if(m.Id()== size){
                answer = std::experimental::make_optional(m);
                return answer;
            }
        }
        Building building;
        answer= std::experimental::make_optional(building);
        return answer;
    }

    void BuildingRepository::StoreAll(Serializer *serializer) const {
        serializer->Header("building_repository");
        std::vector<std::reference_wrapper<const academia::Serializable>> helping_buildings;
        for(const auto &m: buildings_){
            helping_buildings.emplace_back(m);
        }
        serializer->ArrayField("buildings",helping_buildings);
        serializer->Footer("building_repository");
    }


    //std::experimental::optional BuildingRepository::operator[]() {
    //    return std::experimental::optional();
  //  }

}