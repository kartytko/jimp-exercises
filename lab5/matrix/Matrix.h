

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <complex>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <initializer_list>
namespace algebra {

    class Matrix {
    public:
        Matrix();
        Matrix(const std::initializer_list <std::vector<std::complex<double>>> &vec) : vec_(vec){
            rowsize_=vec_.size();
            colsize_=vec_[0].size();
        };
        Matrix(size_t rowsize,size_t colsize);
        Matrix(const Matrix &xxx);

        ~Matrix();



        Matrix Add(const Matrix &matrix2) const;

        Matrix Sub(const Matrix &matrix2)const;

        Matrix Mul(const Matrix &matrix2)const;

        Matrix Div(const Matrix &matrix2)const;

        Matrix Pow(int power);
        std::pair<size_t,size_t> Size();
        std::string Print()const;
        void Set(size_t row, size_t col, std::complex<double> value);
        std::complex<double> Get(size_t row, size_t col);

    private:
        size_t rowsize_;
        size_t colsize_;
        std::vector<std::vector<std::complex<double>>> vec_;

    };
}


#endif //JIMP_EXERCISES_MATRIX_H

