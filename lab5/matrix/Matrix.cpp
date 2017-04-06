//
// Created by kartytko on 06.04.17.
//

#include "Matrix.h"
// Created by ela on 02.04.17.
//

#include "Matrix.h"
namespace algebra{
    Matrix::Matrix() {
    }


    Matrix::Matrix(size_t rowsize,size_t colsize) {
        rowsize_ = rowsize;
        colsize_=colsize;
        vec_.resize(rowsize);
        for(int i=0; i<rowsize_;++i)
            vec_[i].resize(colsize_);
    };


    Matrix::Matrix(const Matrix &xxx) {
        rowsize_ =xxx.rowsize_;
        colsize_ =xxx.colsize_;
        vec_=xxx.vec_;
    };

    Matrix::~Matrix() {};









    void Matrix::Set(size_t row, size_t col, std::complex<double> value) {
        this->vec_[row][col]=value;
    }

    std::complex<double> Matrix::Get(size_t row, size_t col){
        return this->vec_[row][col];
    }

    std:: pair<size_t ,size_t> Matrix::Size() {
        return std::make_pair(rowsize_,colsize_);
    }

    std::string Matrix::Print()const {
        // std::string strvec=std::to_string(vec_);
        if(vec_.size()==0){
            return "[]";
        }

        std::string toprint="[";
        for(int i=0; i<rowsize_;i++){
            for(int j=0; j<colsize_;j++){
                std::stringstream tmp1;
                tmp1<<(vec_[i][j].real());
                toprint+=tmp1.str();
                toprint+="i";
                std::stringstream tmp2;
                tmp2<<(vec_[i][j].imag());
                toprint+=tmp2.str();
                toprint+=", ";
            }
            //toprint=toprint.substr(0,toprint.size()-2);
            toprint=toprint.erase(toprint.size()-2,2);
            toprint+="; ";
        }

        toprint=toprint.erase(toprint.size()-2,2);

        //toprint=toprint.substr(0,toprint.size()-3);
        toprint+="]";
        return toprint;
    }









    Matrix Matrix::Add(const Matrix &matrix2)const{
        Matrix  sum(rowsize_,colsize_);
        if((this->rowsize_!=matrix2.rowsize_) or (this->colsize_!=matrix2.colsize_)){
            return {};
        }
        for(int i=0;i<rowsize_;++i){
            for(int j=0;j<colsize_;++j)
                sum.vec_[i][j]=(this->vec_[i][j]+matrix2.vec_[i][j]);
        }
        return sum;
    }

    Matrix Matrix::Sub(const Matrix &matrix2)const {
        Matrix  sub(rowsize_,colsize_);;
        if((this->rowsize_!=matrix2.rowsize_) or (this->colsize_!=matrix2.colsize_)){
            return Matrix(0,0);
        }
        for(int i=0;i<rowsize_;++i){
            for(int j=0;j<colsize_;++j)
                sub.vec_[i][j]=(this->vec_[i][j]-matrix2.vec_[i][j]);
        }
        return sub;
    }

    Matrix Matrix::Mul(const Matrix &matrix2)const {
        Matrix  mul(rowsize_,matrix2.colsize_);
        if((this->colsize_)!=(matrix2.rowsize_)){
            return Matrix(0, 0);
        }
        if((this->colsize_)==(matrix2.rowsize_)){
            for (int i =0; i <rowsize_; i++) {
                for (int j = 0; j <matrix2.colsize_; j++) {
                    mul.vec_[i][j] = 0;
                    for (int k = 0; k< colsize_; k++) {
                        mul.vec_[i][j] += (vec_[i][k]) * (matrix2.vec_[k][j]);
                    }
                }
            }
            return mul;
        }
        return Matrix();
    }

    Matrix Matrix::Div(const Matrix &matrix2)const {
        return Matrix();
    }

    Matrix Matrix::Pow( int power) {

        if (power == 0) {
            Matrix pow(rowsize_,colsize_);

            for (int i = 0; i < rowsize_; i++) {
                for (int j = 0; j <colsize_; j++) {
                    if (i == j)
                        pow.vec_[i][j] = 1.;
                    else
                        pow.vec_[i][j] = 0.;
                }
            }
            return pow;

        }
        if( rowsize_ != colsize_){
            return Matrix(0, 0);
        }


        if(power==1){
            return  Matrix(*this);
        }

        if (power > 0 && rowsize_ == colsize_) {
            Matrix pow(rowsize_,colsize_);
            pow = *this;
            for (int i = 1; i < power; i++) {
                pow= pow.Mul(*this);
            }
            return pow;
        }
        return Matrix();
    }


}