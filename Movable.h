#ifndef MOVABLE_H
#define MOVABLE_H
#include <vector>

#include "Point.h"
#include "Speed.h"

class Movable {
protected:
    Point position;
    std::vector<Point> nextPoints;
    Speed speed;

public:
    virtual void move();
    float getRotation();
};

#endif //MOVABLE_H
