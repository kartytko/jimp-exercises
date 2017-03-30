//
// Created by kartytko on 23.03.17.
//

#include "Square.h"
#include <cmath>


namespace geometry{
    Point::Point(){
        x_=0.0;
        y_=0.0;
    }
    Point::~Point(){};
    Point::Point(double x, double y) {
        x_ = x;
        y_ = y;
    }

    double Point::GetX() const{
        return x_;
    }

    double Point::GetY() const{
        return y_;
    }

    double Point::Distance(const Point &other) const{
        return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));
    }

    Square::Square() {}
    Square::Square(Point p1, Point p2, Point p3, Point p4) {
        p1_ = p1;
        p2_ = p2;
        p3_ = p3;
        p4_ = p4;
    }
    Square::~Square() {}

    double Square::Circumference(){
        if(p1_.Distance(p2_)==p3_.Distance(p4_)){
            return 4*p1_.Distance(p2_);
        }else{
            return 0;
        }
    }

    double Square::Area(){
        if(p1_.Distance(p2_)==p3_.Distance(p4_)){
            return p1_.Distance(p2_)*p2_.Distance(p1_);
        }else{
            return 0;
        }
    }


}