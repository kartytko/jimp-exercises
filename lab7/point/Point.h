//
// Created by ela on 24.04.17.
//

#ifndef JIMP_EXERCISES_POINT_H
#define JIMP_EXERCISES_POINT_H


#include <ostream>

class Point {
public:

        Point();

        Point(double x, double y);
        virtual double Distance(const Point &other) const;
    virtual ~Point();

    friend std::ostream &operator<<(std::ostream &os, const Point &point);

protected:

        double x_, y_;
    };
class Point3D:public Point{
protected:
    double z_;

public:
    Point3D();
    Point3D(double x, double y, double z);
    double distance(const Point3D &other);

    ~Point3D();


};

#endif //JIMP_EXERCISES_POINT_H
