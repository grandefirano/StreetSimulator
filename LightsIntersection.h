
#ifndef LIGHTSINTERSECTION_H
#define LIGHTSINTERSECTION_H
#include "Car.h"
#include "Intersection.h"
#include "LightsManager.h"

class LightsIntersection : public Intersection {
public:
    LightsIntersection(LightsManager *_lightsManager,EdgeCollisionDetector *_edgeCollisionDetector);

    bool canGo(const Car &currentCar,const  Direction &currentDirection,const  std::vector<Car> &collidingCars) override;

private:
    LightsManager *lightsManager;

    bool compareLightsPriority(const Car &currentCar, const Car &car,const Direction &currentDirection);
};

#endif //LIGHTSINTERSECTION_H
