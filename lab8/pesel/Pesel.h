//
// Created by kartytko on 27.04.17.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <iostream>
namespace academia {


    class AcademiaDataValidationError:public std::runtime_error{
    public:

        AcademiaDataValidationError(std::string a):runtime_error(a){
            invalid_argument_= a;
        }
//        virtual void validatePESEL(std::string a)=0;
        virtual ~AcademiaDataValidationError(){}

    protected:
        std::string invalid_argument_;
    };



    class InvalidPeselChecksum:public AcademiaDataValidationError{
    public:
        InvalidPeselChecksum(const std::string &pesel, int checksum): AcademiaDataValidationError("Invalid PESEL("+pesel+") checksum: "+std::to_string(checksum)){}
        ~InvalidPeselChecksum(){}
    private:
        std::string pesel_;
    };
    class InvalidPeselLength:public AcademiaDataValidationError{
    public:
        InvalidPeselLength(std::string pesel, int length): AcademiaDataValidationError("Invalid PESEL("+pesel+") length: "+std::to_string(length)){}
        ~InvalidPeselLength(){}
    private:
        std::string pesel_;

    };
    class InvalidPeselCharacter:public AcademiaDataValidationError{
    public:
        InvalidPeselCharacter(std::string pesel): AcademiaDataValidationError("Invalid PESEL("+pesel+") character set"){}
        ~InvalidPeselCharacter(){}
    private:
        std::string pesel_;
    };



    class Pesel {
    public:
        Pesel(std::string a){
            validatePESEL(a);
        }
        ~Pesel(){}
        void validatePESEL(std::string a){
            if (a.length() != 11){
                throw InvalidPeselLength(a, a.size());
            }
            for(int i=0; i<a.length(); i++){
                if((48<=a[i]) && (a[i]<=57)){

                }else{
                    throw InvalidPeselCharacter(a);
                }
            }

            int array[10]= {9, 7, 3, 1, 9, 7, 3, 1, 9, 7};
            int checksum = 0;
            for(int i=0; i<10; i++){
              checksum = checksum + array[i]*(a[i]-48);
            }
            checksum=checksum%10;
            if(checksum!=(a[10]-'0')){
                throw InvalidPeselChecksum(a, checksum);
            }
        }

    private:
        std::string pesel_;

    };
}

#endif //JIMP_EXERCISES_PESEL_H
