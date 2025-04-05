
#ifndef INTERSECTION_H
#define INTERSECTION_H
#include "Car.h"

class Intersection {
public:
    virtual bool canGo(Car &currentCar, Direction currentDirection, std::vector<Car> collidingCars) =0;
protected:
    enum Entrance {ENTR_STRAIGHT,ENTR_LEFT,ENTR_RIGHT};
    Field getIntersectionEntrance(Field field, const Direction &direction, Entrance entrance);
    std::vector<Field> getIntersectionFields(Field field, const Direction &direction);
};

#endif //INTERSECTION_H
