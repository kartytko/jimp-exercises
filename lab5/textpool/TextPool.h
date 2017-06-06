//
// Created by kartytko on 03.04.17.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H
#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <map>

namespace pool{

    class TextPool{
    public:

        TextPool();
        ~TextPool();
        //konstruktor przenoszący
        TextPool(TextPool &&xxx);
        //operator przypisania przenoszący
        TextPool &operator=(TextPool &&xxx);
        TextPool (std::initializer_list<std::experimental::string_view> poolset);

        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;

        std::set <std::experimental::string_view> poolset_;
    private:
        //std::experimental::string_view pointer_;

    };
}
#endif //JIMP_EXERCISES_TEXTPOOL_H
