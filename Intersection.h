
#ifndef INTERSECTION_H
#define INTERSECTION_H
#include "Car.h"
#include "EdgeCollisionDetector.h"

class Intersection {
public:
    virtual bool canGo(const Car &currentCar, const Direction &currentDirection,const std::vector<Car> &collidingCars) =0;
protected:
    EdgeCollisionDetector *edgeCollisionDetector;
    enum Entrance {ENTR_STRAIGHT,ENTR_LEFT,ENTR_RIGHT};
    Intersection(EdgeCollisionDetector *_edgeCollisionDetector);
    Field getIntersectionEntrance(const Field &field, const Direction &direction,const Entrance &entrance);
    std::vector<Field> getIntersectionFields(const Field &field, const Direction &direction);
};

#endif //INTERSECTION_H
