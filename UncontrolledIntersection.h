
#ifndef UNCONTROLLEDINTERSECTION_H
#define UNCONTROLLEDINTERSECTION_H
#include <vector>

#include "Intersection.h"
#include "Point.h"

class Car;

class UncontrolledIntersection : public Intersection {
public:
    bool canGo(Car &currentCar, Direction currentDirection, std::vector<Car> collidingCars) override;

private:
    bool compareEqualPriority(Car &currentCar, Car &car, const Direction &currentDirection);
};


#endif //UNCONTROLLEDINTERSECTION_H
