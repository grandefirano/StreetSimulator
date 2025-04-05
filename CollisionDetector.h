
#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H
#include "WorldMapGridProvider.h"
#include "LightsManager.h"

class Car;

class CollisionDetector {
public:
    CollisionDetector(WorldMapGridProvider *worldMapGridProvider,LightsManager *_lightsManager);
    bool checkIntersectionCollision(Car &car,std::vector<Car> &cars);
private:
    LightsManager *lightsManager;
    GridType grid;
};

#endif //COLLISIONDETECTOR_H
