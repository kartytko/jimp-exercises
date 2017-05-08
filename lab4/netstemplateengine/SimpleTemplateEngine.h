//
// Created by kartytko on 26.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

namespace nets{
    class View{
        public:
            View();
            View(std::string view);
            ~View();

            std::string Render(const std::unordered_map <std::string, std::string> &model) const;

        private:
            std::string view_;
            std::vector<std::string> vector_view_;
    };
}

#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
