//
// Created by kartytko on 27.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H
#include <experimental/optional>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <regex>
using ::std::literals::operator""s;

namespace nets{
    class JsonValue{
        public:
        JsonValue();
        JsonValue(std::string str);
        JsonValue(int integer);
        JsonValue(double double_number);
        JsonValue(bool bool_lean);
        JsonValue(std::vector <JsonValue> json_vector);
        JsonValue(::std::map <std::string, JsonValue> json_map);
        ~JsonValue();

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;

        private:
        std::experimental::optional<std::string>  string_value_;
        std::experimental::optional<int>  int_value_;
        std::experimental::optional<double>  double_value_;
        std::experimental::optional<bool>  bool_value_;
        std::experimental::optional<std::vector<JsonValue>> json_vector_;
        std::experimental::optional<std::map <std::string, JsonValue>> json_map_;
    };

}
#endif //JIMP_EXERCISES_SIMPLEJSON_H
