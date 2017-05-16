//
// Created by kartytko on 07.05.17.
//

#include "MovieSubtitles.h"

namespace moviesubs{

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int frame, std::stringstream *in, std::stringstream *out){
        char c;
        int lines_counter = 0;
        double double_delay = delay;
        double_delay=double_delay/1000;
        int frames_to_add = double_delay*frame;
        std::string current_line;

        if(frame<0){
            throw std::invalid_argument("Invalid argument");
        }

        while((*in).get(c)){
            if(c!='\n'){
                current_line=current_line+c;
            }else{
                lines_counter++;
                if(current_line!=""){
                        ChangeValues(current_line, frames_to_add, lines_counter);
                    *out<<current_line;
                    current_line="";
                }
                *out<<c;
            }

        }
        if(current_line!=""){
            ChangeValues(current_line, frames_to_add, lines_counter);
            *out<<current_line;
            *out<<'\n';
        }

    }



    void MicroDvdSubtitles::ChangeValues(std::string &line, int frames_to_add, int lines_counter) {
        int start = 0;
        int end = 0;
        std::string answer="";
        std::string start_str = "";
        std::string end_str = "";
        bool completed_start_value = false;
        bool completed_end_value = false;
        int open_bracket = 0;
        int closed_bracket= 0;

        for (int i = 0; i < line.length(); i++) {

            if(line[i]=='{'){
                open_bracket++;
            }
            if(open_bracket<3 && (line[i]=='{') && !(line[i+1] >= '0' && line[i+1] <= '9')){
                throw InvalidSubtitleLineFormat();
            }
            if(line[i]=='}'){
                closed_bracket++;
                if(open_bracket!=closed_bracket){
                    throw InvalidSubtitleLineFormat();
                }
            }
            if (!completed_start_value) {
                if ((line[i] >= '0' && line[i] <= '9')) {
                    start_str = start_str + line[i];
                    if (line[i + 1] >= '0' && line[i + 1] <= '9') {
                        continue;
                    } else {
                        completed_start_value = true;
                        start=std::stoi(start_str);
                        start=start+frames_to_add;
                        if(start<0){
                            throw NegativeFrameAfterShift();
                        }
                        answer=answer+std::to_string(start);
                    }
                }else{
                    answer=answer+line[i];
                }
            } else {
                if(!completed_end_value){
                    if ((line[i] >= '0' && line[i] <= '9')) {
                        end_str = end_str + line[i];
                        if (line[i + 1] >= '0' && line[i + 1] <= '9') {
                            continue;
                        } else {
                            completed_end_value = true;
                            end=std::stoi(end_str);
                            end=end+frames_to_add;
                            if(end<0){
                                throw NegativeFrameAfterShift();
                            }
                            answer=answer+std::to_string(end);
                        }
                    }else{
                        answer=answer+line[i];
                    }
                }else{
                    answer=answer+line[i];
                }
            }
        }

        if(closed_bracket!=open_bracket){
            throw InvalidSubtitleLineFormat();
        }else{
            //if(closed_bracket!=2){
            if(closed_bracket<2){
                throw InvalidSubtitleLineFormat();
            }
        }


        if(end<start) {
            throw SubtitleEndBeforeStart(lines_counter, line);
        }
        line=answer;
    }







    void SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int frame, std::stringstream *in, std::stringstream *out) {
        char c;
        bool pushed=false;
        int end_of_line_counter=0;
        int arrow_counter=0;
        std::string first="";
        std::string second="";
        long long int miliseconds_amount_first=0;
        long long int miliseconds_amount_second=0;
        int line_at=0;
        int previous_line_at=0;
        std::string current_line="";

        if(frame<0){
            throw std::invalid_argument("Invalid argument");
        }


        while((*in).get(c)){
            if((end_of_line_counter%4==0) && c!='\n'){
                previous_line_at = line_at;
                line_at=c-'0';

            }
            if(c=='\n'){
                end_of_line_counter++;
                *out << '\n';
                if((end_of_line_counter%4==2) && pushed==false){
                    throw InvalidSubtitleLineFormat();
                }else{
                    pushed=false;
                }
                continue;
            }

            if(end_of_line_counter==4){
                end_of_line_counter=0;
            }

            if(end_of_line_counter==1){
                if(first.length()!=12){
                    first=first+c;
                    current_line=current_line+c;
                    continue;
                }
                if(arrow_counter==5){
                    if(second.length()!=12 && first.length()==12){
                        second=second+c;
                        current_line=current_line+c;
                    }
                }else{
                    arrow_counter++;
                    current_line=current_line+c;
                }
                if(second.length()==12 && first.length()==12){
                    SubtitleLineFormatChecker(current_line);
                    miliseconds_amount_first = ToMiliseconds(first, delay);
                    miliseconds_amount_second =ToMiliseconds(second, delay);
                    if(miliseconds_amount_first>miliseconds_amount_second){
                        throw SubtitleEndBeforeStart(line_at, first+" --> "+second);
                    }
                    if(previous_line_at+1!=line_at){
                        throw OutOfOrderFrames();
                    }

                    first = FromMiliseconds(miliseconds_amount_first);
                    second = FromMiliseconds(miliseconds_amount_second);
                    *out << first <<" --> "<<second;

                    arrow_counter=0;
                    first="";
                    second="";
                    current_line="";
                    pushed=true;
                }


            }else{
                *out << c;
            }
        }
    }


    int SubRipSubtitles::ToMiliseconds(std::string &value, int delay) {
        long long int miliseconds_amount = 0;
        long long int hours = (value[0] - '0') * 10 + (value[1] - '0');
        long long int minutes = (value[3] - '0') * 10 + (value[4] - '0');
        long long int seconds = (value[6] - '0') * 10 + (value[7] - '0');
        long long int miliseconds = (value[9] - '0') * 100 + (value[10] - '0') * 10 + (value[11] - '0');
        std::string answer = "";


        miliseconds_amount = hours * 60 * 60 * 1000 + minutes * 60 * 1000 + seconds * 1000 + miliseconds;
        miliseconds_amount = miliseconds_amount + delay;

        if (miliseconds_amount < 0) {
            throw NegativeFrameAfterShift();
        }
        return miliseconds_amount;
    }

    std::string SubRipSubtitles::FromMiliseconds(long long int miliseconds_amount){
        long long int miliseconds=0;
        long long int seconds=0;
        long long int minutes=0;
        long long int hours=0;
        std::string answer ="";

        miliseconds=miliseconds_amount%1000;
        seconds=(miliseconds_amount-miliseconds)%(60*1000);
        minutes=(miliseconds_amount-miliseconds-seconds)%(60*1000*60);
        hours=(miliseconds_amount-miliseconds-seconds-minutes)%(60*60*60*1000);
        seconds=seconds/1000;
        minutes=minutes/(60*1000);
        hours=hours/(60*60*1000);

        answer = TimeConverterToString(hours, answer);
        answer = TimeConverterToString(minutes, answer);
        answer = TimeConverterToString(seconds, answer);
        answer[answer.length()-1]=',';
        if(miliseconds<100){
            if(miliseconds<10){
                answer=answer+"00"+std::to_string(miliseconds);
            }else{
                answer=answer+'0'+std::to_string(miliseconds);
            }
        }else{
            answer=answer+std::to_string(miliseconds);
        }

        return answer;
    }

    std::string &SubRipSubtitles::TimeConverterToString(long long int hours, std::string &answer) {
        if (hours < 10){
            answer= answer + '0' + std::__cxx11::to_string(hours);
        }else{
            answer= answer + std::__cxx11::to_string(hours);
        }
        answer=answer+':';
        return answer;
    }

    void SubRipSubtitles::SubtitleLineFormatChecker(const std::string &line) {

        if (line[8] == '.' || line[25] == '.') {
            throw InvalidSubtitleLineFormat("milisecond separator should be a coma (,)");
        }
        if (line[14] == '>') {
            throw InvalidSubtitleLineFormat("arrow is too short");
        }
        if ((line[13] != '-') && (line[14] != '-')) {
            throw InvalidSubtitleLineFormat("missing arrow");
        }
        if ((line[2] == ';') || (line[5] == ';') || (line[19] == ';') || (line[22] == ';')) {
            throw InvalidSubtitleLineFormat("semicolon instead of colon");
        }
        if ((line[13] == '-') && (line[14] == '-') && (line[15] == '-') && (line[16] == '>')) {
            throw InvalidSubtitleLineFormat("too long arrow");
        }
        if ((('0' <= line[8]) && (line[8] <= '9')) || (('0' <= line[25]) && (line[25] <= '9'))) {
            throw InvalidSubtitleLineFormat("seconds out of range");
        }

    }

}