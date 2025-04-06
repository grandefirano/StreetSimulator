
#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H
#include "LightsManager.h"
#include "WorldMapManager.h"

class Car;
class UncontrolledIntersection;
class LightsIntersection;
class PriorityIntersection;

class CollisionDetector {
public:
    CollisionDetector(LightsManager *_lightsManager, WorldMapManager *_worldMapManager);
    bool checkIntersectionCollision(Car &car,std::vector<Car> &cars);
private:
    LightsManager *lightsManager;
    WorldMapManager *worldMapManager;
    LightsIntersection *lightsIntersection;
    UncontrolledIntersection *uncontrolledIntersection;
    PriorityIntersection *priorityIntersection;
};

#endif //COLLISIONDETECTOR_H
