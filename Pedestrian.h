
#ifndef PEDESTRIAN_H
#define PEDESTRIAN_H
#include "Field.h"
#include "Movable.h"

class Pedestrian : public Movable {
public:
    Pedestrian(std::vector<Point> allPoints, Speed speed, Field field);
    Field getField();
    Point getPosition();
    std::vector<Point> getNextPoints();
};

#endif //PEDESTRIAN_H
