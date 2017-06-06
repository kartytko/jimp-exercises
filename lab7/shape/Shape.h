//
// Created by ela on 24.04.17.
//

#ifndef JIMP_EXERCISES_SHAPE_H
#define JIMP_EXERCISES_SHAPE_H

#include <iostream>
class Ksztalt{
public:
    virtual void rysuj()=0;

};

class Trojkat:public Ksztalt{
public:
    virtual void rysuj();
};

class Kwadrat:public Ksztalt{
public:
    virtual void rysuj();
};

class Kolo:public Ksztalt{
public:
    virtual void rysuj();
};


#endif //JIMP_EXERCISES_SHAPE_H
