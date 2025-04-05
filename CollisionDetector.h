
#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H
#include "WorldMapGridProvider.h"
#include "LightsManager.h"
#include "WorldMapManager.h"

class Car;

class CollisionDetector {
public:
    CollisionDetector(LightsManager *_lightsManager, WorldMapManager *_worldMapManager);
    bool checkIntersectionCollision(Car &car,std::vector<Car> &cars);
private:
    LightsManager *lightsManager;
    WorldMapManager *worldMapManager;
};

#endif //COLLISIONDETECTOR_H
