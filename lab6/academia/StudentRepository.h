//
// Created by kartytko on 12.04.17.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H
#include <iostream>

namespace academia{
/*    class Student{
        public:
            //friend class StudyYear;
            std::string id;
            std::string first_name;
            std::string last_name;
            std::string program;
            //friend StudyYear year{};

        private:
    };
*/

    class StudyYear{
        public:
            StudyYear();
            ~StudyYear();
            StudyYear(int study_year);
            StudyYear &operator++();
            StudyYear &operator--();
            int GetYear();
            void SetYear(int new_year);
            operator int() const;
            bool operator == (const StudyYear &new_study_year)const;
            bool operator == (const int &study_year) const;
            bool operator<(const StudyYear &new_study_year)const;
            //std::ostream & operator<< (const StudyYear &study_year);

        private:
            int study_year_;
          //  std::ostream out_;
    };

    int ReadNumber(std::istream* is);
    std::istream& operator>>(std::istream &in, StudyYear& study_year);

}

#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
