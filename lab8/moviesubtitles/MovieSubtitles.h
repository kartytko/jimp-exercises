//
// Created by kartytko on 07.05.17.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <iostream>
#include <string>
#include <sstream>
#include <regex>

namespace moviesubs{

    class MovieSubsDataValidationError:public std::runtime_error{
    public:
        MovieSubsDataValidationError(std::string a):runtime_error(a){
            invalid_argument_= a;
        }
        MovieSubsDataValidationError();
        virtual ~MovieSubsDataValidationError(){}

    protected:
        std::string invalid_argument_;
    };


    class NegativeFrameAfterShift: public MovieSubsDataValidationError{
    public:
        NegativeFrameAfterShift(): MovieSubsDataValidationError("NegativeFrameAfterShirt()"){};
        ~NegativeFrameAfterShift(){};
    };

    class SubtitleEndBeforeStart: public MovieSubsDataValidationError{
    public:
        SubtitleEndBeforeStart(int line_number, std::string line): MovieSubsDataValidationError("At line "+std::to_string(line_number)+": "+line), line_(line_number){};
        ~SubtitleEndBeforeStart(){};
        int LineAt() const{
            return line_;
        }
    protected:
        int line_;
    };

    class InvalidSubtitleLineFormat: public MovieSubsDataValidationError{
    public:
        InvalidSubtitleLineFormat(std::string message): MovieSubsDataValidationError(message){};
        InvalidSubtitleLineFormat(): MovieSubsDataValidationError("InvalidSubtitleLineFormat()"){};
        ~InvalidSubtitleLineFormat(){;}
    };

    class MissingTimeSpecification: public MovieSubsDataValidationError{
    public:
        MissingTimeSpecification();
    };

    class OutOfOrderFrames: public MovieSubsDataValidationError{
    public:
        OutOfOrderFrames(): MovieSubsDataValidationError("OutOfOrderFrames()"){};
        ~OutOfOrderFrames(){}
    };





    class MovieSubtitles{
    public:
        MovieSubtitles(){};
        virtual void ShiftAllSubtitlesBy(int delay, int frame, std::stringstream *in, std::stringstream *out)=0;
        virtual ~MovieSubtitles(){};
    };


    class MicroDvdSubtitles: public MovieSubtitles{
    public:
        MicroDvdSubtitles(){};
        virtual void ShiftAllSubtitlesBy(int delay, int frame, std::stringstream *in, std::stringstream *out);
        virtual void ChangeValues(std::string &line, int frames_to_add, int lines_counter);
    };


    class SubRipSubtitles: public  MovieSubtitles{
    public:
        SubRipSubtitles(){};
        virtual void ShiftAllSubtitlesBy(int delay, int frame, std::stringstream *in, std::stringstream *out);
        virtual int ToMiliseconds(std::string &value, int delay);
        virtual std::string FromMiliseconds(long long int miliseconds);
        virtual std::string &TimeConverterToString(long long int hours, std::string &answer);
        virtual void SubtitleLineFormatChecker(const std::string &line);
    };

}


#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
