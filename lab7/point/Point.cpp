//
// Created by ela on 24.04.17.
//


#include <cmath>
#include <iostream>
#include "Point.h"

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;




Point::Point():x_(0),y_(0){
    std::cout << "Konstruktor bezparametrowy POINT" << endl;
}

Point::Point(double x, double y){
    std::cout << "Konstruktor parametrowy POINT" << endl;
    x_ = x;
    y_ = y;
}

 Point::~Point(){
    std::cout << "Destruktor POINT! ";
    std::cout << endl;
}

double Point::Distance(const Point &other) const{
    std::cout<<"Wynik  "<<sqrt(pow(x_-other.x_,2)+pow(y_-other.y_,2))<<endl;
    return sqrt(pow(x_-other.x_,2)+pow(y_-other.y_,2));
}

ostream &operator<<(ostream &os, const Point &point) {
    os << "x_: " << point.x_ << " y_: " << point.y_;
    return os;
}


Point3D::Point3D():z_(0) {
    std::cout << "Konstruktor bezparametrowy POINT3D" << endl;
}

Point3D::Point3D(double x, double y, double z):Point(x,y) {
    z_=z;
    std::cout << "Konstruktor parametrowy POINT3D" << endl;
}

Point3D::~Point3D() {
    std::cout << "Destruktor POINT3D"<<endl;
}

double Point3D::distance(const Point3D &other) {
    return sqrt(pow(x_-other.x_,2)+pow(y_-other.y_,2)+pow(z_-other.z_,2));
}
