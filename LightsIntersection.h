
#ifndef LIGHTSINTERSECTION_H
#define LIGHTSINTERSECTION_H
#include "Car.h"
#include "Intersection.h"
#include "LightsManager.h"

class LightsIntersection : public Intersection {
public:
    LightsIntersection(LightsManager *_lightsManager);

    bool canGo(Car &currentCar, Direction currentDirection, std::vector<Car> collidingCars) override;

private:
    LightsManager *lightsManager;

    bool compareLightsPriority(Car currentCar, Car car, Direction &currentDirection);
};

#endif //LIGHTSINTERSECTION_H
