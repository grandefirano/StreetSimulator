
#ifndef UNCONTROLLEDINTERSECTION_H
#define UNCONTROLLEDINTERSECTION_H
#include <vector>

#include "Intersection.h"

class Car;

class UncontrolledIntersection : public Intersection {
public:
    UncontrolledIntersection(EdgeCollisionDetector *_edgeCollisionDetector);
    bool canGo(const Car &currentCar,const Direction &currentDirection, const std::vector<Car> &collidingCars) override;

private:
    bool compareEqualPriority(const Car &currentCar,const Car &car, const Direction &currentDirection);
};


#endif //UNCONTROLLEDINTERSECTION_H
