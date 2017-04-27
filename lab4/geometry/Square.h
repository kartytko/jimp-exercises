//
// Created by kartytko on 23.03.17.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

namespace geometry{
    class Point{
        public:
            Point();
            Point(double x, double y);
            ~Point();

            double GetX() const;
            double GetY() const;

            double Distance(const Point &other) const;

        private:
            double x_;
            double y_;
    };

    class Square{
        public:
            Square();
            Square(Point p1, Point p2, Point p3, Point p4);
            ~Square();

            double Circumference();
            double Area();
        private:
            Point p1_;
            Point p2_;
            Point p3_;
            Point p4_;
    };
}


#endif //JIMP_EXERCISES_SQUARE_H
