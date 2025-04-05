#ifndef MOVABLE_H
#define MOVABLE_H
#include "Point.h"
#include "Speed.h"

class Movable {
protected:
    Point position;
    std::vector<Point> nextPoints;
    Speed speed;

public:
    virtual void move();
};

#endif //MOVABLE_H
