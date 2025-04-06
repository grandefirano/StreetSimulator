
#ifndef PEDESTRIAN_H
#define PEDESTRIAN_H
#include "Field.h"
#include "Movable.h"

class Pedestrian : public Movable {
public:
    Pedestrian(const std::vector<Point> &allPoints,const Speed &_speed, const Field &field);
    Field getField() const;
    Point getPosition() const;
    std::vector<Point> getNextPoints() const;
};

#endif //PEDESTRIAN_H
