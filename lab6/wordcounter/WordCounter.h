//
// Created by kartytko on 15.04.17.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <string>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <list>

namespace datastructures{

    class Counts{
    public:
        Counts();
        Counts(int counts);
        ~Counts();
        int GetCounts();
        Counts &operator ++();
        operator int() const;
        bool operator==(const int &counts) const;
        bool operator==(const Counts &counts)const;
        bool operator<(const Counts &counts)const;
        bool operator>(const Counts &counts)const;

    private:
        int counts_;
    };




    class Word{
    public:
        Word();
        Word(std::string word);
        ~Word();
        bool operator==(const Word &word)const;
        bool operator<(const Word& word) const;
        std::string GetWord() const;

    private:
        std::string word_;
    };





    class WordCounter{
    public:
        WordCounter();
        WordCounter(std::initializer_list<Word> list);
        ~WordCounter();
        Counts operator [](const std::string word);
        void Append(Word single_word);
        int DistinctWords();
        int TotalWords();
        std::set <Word> Words();
        static WordCounter FromInputStream(std::istream &is);

        std::map <Word,Counts> list_;
    private:

    };

}

#endif //JIMP_EXERCISES_WORDCOUNTER_H
