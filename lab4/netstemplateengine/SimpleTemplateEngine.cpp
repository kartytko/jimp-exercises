//
// Created by kartytko on 26.03.17.
//

#include "SimpleTemplateEngine.h"
#include <vector>

namespace nets {
    View::View() {
        view_ = "";
        vector_view_ = {};
    }

    View::View(std::string view) {
        std::string single_word = "";
        std::string single_word2 = "";
        view_ = view;
        int j = 0;


        for (int i = 0; i < view.size(); i++) {
            if (view[i] != '{') {
                single_word = single_word + view[i];
            } else {
                if (i + 1 < view.size() && view[i + 1] != '{') {
                    single_word = single_word + view[i];
                } else {
                    single_word2 = single_word2 + view[i] + view[i + 1];
                    j = i + 2;
                    for (j; j < view.size(); j++) {
                        //std::cout<<"dodaję w zaplętlonej. slowo: "<<single_word<<"slowo2: "<<single_word2<<std::endl;
                        if ((97 <= view[j] && view[j] <= 122) || (65 <= view[j] && view[j] <= 90) ||
                            (48 <= view[j] && view[j] <= 57) || view[j] == 95) {
                            single_word2 = single_word2 + view[j];
                        } else {
                            if (view[j] == '}' && (j + 1 < view.size() && view[j + 1] == '}')) {
                                single_word2 = single_word2 + view[j] + view[j + 1];
                                vector_view_.push_back(single_word);
                                vector_view_.push_back(single_word2);
                                //      std::cout<<"dodaję w ifie1 . slowo: "<<single_word<<"slowo2: "<<single_word2<<std::endl;
                                single_word = "";
                                single_word2 = "";
                                i = j + 1;
                                break;
                            } else {
                                //    std::cout<<"dodaję w ifie2 . slowo: "<<single_word<<"slowo2: "<<single_word2<<std::endl;
                                single_word = single_word + single_word2[0];
                                single_word2 = "";
                                //  std::cout<<"dodaję w ifie2'2 . slowo: "<<single_word<<"slowo2: "<<single_word2<<std::endl;
                                break;
                            }
                        }
                    }
                }
            }
            if (single_word != "" && i + 1 == view.size()) {
                vector_view_.push_back(single_word);
            }
        }
    }


    View::~View() {
        vector_view_.clear();
    }


    std::string View::Render(const std::unordered_map<std::string, std::string> &model) const {
        /*bool first = true;
        for(auto n : vector_view_) {
            if (!first) {
                std::cout<< ", ";
            } else {
                std::cout<<"wektor view: ";
                first = false;
            }
            std::cout << n;
        }*/

        //  std::cout<<"view to: "<<view_<<std::endl;
        std::cout << std::endl;
        std::string result = "";
        std::string model_with_brackets = "";

        for (auto m : vector_view_) {
            if (m[0] == '{' && m[1] == '{' && m[m.size() - 2] == '}' && m[m.size() - 1] == '}') {
                for (auto n : model) {
                    model_with_brackets = "{{" + n.first + "}}";
                    //            std::cout << "model z braketami: " << model_with_brackets << std::endl;
                    if (model_with_brackets == m) {
                        result = result + n.second;
                        //  std::cout << "1. result " << result << std::endl;
                    }
                }
            } else {
                result = result + m;
            }
            //std::cout << "2. reult " << result << std::endl;
        }
        return result;
    }
}