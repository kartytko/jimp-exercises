//
// Created by kartytko on 15.04.17.
//

#include "WordCounter.h"

namespace datastructures{
    Counts::Counts(){
        counts_=0;
    }
    Counts::Counts(int counts) {
        counts_ = counts;
    }
    Counts::~Counts(){}

    int Counts::GetCounts(){
        return counts_;
    }

    Counts::operator int() const{
        return this->counts_;
    }

    Counts & Counts::operator ++(){
        ++counts_;
        return *this;
    }

    bool Counts::operator==(const Counts &counts)const{
        return counts_==counts.counts_;
    }

    bool Counts::operator==(const int &counts) const{
        return counts_==counts;
    }

    bool Counts::operator<(const Counts &counts)const{
        return counts_<counts.counts_;
    }

    bool Counts::operator>(const Counts &counts)const{
        return counts_>counts.counts_;
    }






    Word::Word(){
        word_="";
    }
    Word::Word(std::string word){
        word_ = word;
    }
    Word::~Word(){}

    bool Word::operator==(const Word &word) const {
        return word_==word.word_;
    }

    bool Word::operator<(const Word& word) const {
        return word_ < word.word_;
    }
    std::string Word::GetWord()const{
        return word_;
    }






    WordCounter::WordCounter(){
        list_={};
    }

    WordCounter::WordCounter(std::initializer_list<Word> list){
        Counts counter = 1;
        bool is_first=true;
        bool after_loop=false;
        for(auto a : list){
            if(is_first){
                list_.insert(std::make_pair(a, counter));
                is_first=false;
                continue;
            }
            for(auto it=list_.begin(); it!=list_.end();  it++){
                if((*it).first==a){
                    ++(*it).second;
                    after_loop=true;
                    break;
                }
            }
            if(!after_loop){
                list_.insert(std::make_pair(a, counter));
            }else{
                after_loop=false;
            }

        }
    }
    WordCounter::~WordCounter(){}

    Counts WordCounter::operator [](const std::string word){
        std::map<Word,Counts>::iterator it;
        it = list_.find(word);
        if (it != list_.end()){
            return this->list_[word];
        }else{
            Counts result;
            return result;
        }

    }

    void WordCounter::Append(Word single_word){
        bool after_loop = false;
        if(list_.size()==0){
            list_.insert(std::make_pair(single_word, Counts(1)));
        }

        for (auto &a: list_){
            if(a.first == single_word){
                ++a.second;
                after_loop=true;
                break;
            }
        }

        if(!after_loop){
            list_.insert(std::make_pair(single_word, Counts(1)));
        }
    }


    int WordCounter::DistinctWords(){
        int result=0;
        for(auto m : list_){
            result++;

        }
        return result;
    }

    int WordCounter::TotalWords(){
        int result=0;
        for(auto m : list_){
            result = result + m.second.GetCounts();
        }
        return result;
    }

    std::set <Word> WordCounter::Words(){
        std::set <Word> unique_words={};
        for(auto a : list_){
            unique_words.insert(a.first);
        }
        return unique_words;
    }


    WordCounter WordCounter::FromInputStream(std::istream &is){
        char c;
        WordCounter list{};
        std::vector <Word> words;
        std::string single_word="";
        while(is.get(c)){
            if((60<=c && c<=95) || (97<=c && c<=122)){
                single_word=single_word+c;
            }
            else{
                if(single_word!=""){
                    words.insert(words.begin(), Word(single_word));
                    single_word="";
                }
            }
        }
        for(auto a : words){
            list.Append(a);
        }

/*        for(auto m : list.list_){
            std::cout << "to jest m.first " << m.first.GetWord() << ", m.second "<<m.second.GetCounts()<<std::endl ;
        }
*/
        return list;

    }

}