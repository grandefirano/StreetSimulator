
#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H
#include "EdgeCollisionDetector.h"
#include "LightsManager.h"
#include "Pedestrian.h"
#include "WorldMapManager.h"

class Car;
class UncontrolledIntersection;
class LightsIntersection;
class PriorityIntersection;

class CollisionDetector {
public:
    CollisionDetector(LightsManager *_lightsManager, WorldMapManager *_worldMapManager,EdgeCollisionDetector *_edgeCollisionDetector);
    bool checkIntersectionCollision(const Car &currentCar, const std::vector<Car> &cars);
    bool checkPedestrianCollision(const Car &currentCar,const std::vector<Pedestrian> &pedestrians);
private:
    LightsManager *lightsManager;
    WorldMapManager *worldMapManager;
    EdgeCollisionDetector *edgeCollisionDetector;
    LightsIntersection *lightsIntersection;
    UncontrolledIntersection *uncontrolledIntersection;
    PriorityIntersection *priorityIntersection;
};

#endif //COLLISIONDETECTOR_H
