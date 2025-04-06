
#ifndef PRIORITYINTERSECTION_H
#define PRIORITYINTERSECTION_H
#include "Intersection.h"
#include "WorldMapManager.h"

class PriorityIntersection : public Intersection {
public:
    PriorityIntersection(WorldMapManager *worldMapManager,EdgeCollisionDetector *_edgeCollisionDetector);
    bool canGo(const Car &currentCar,const Direction &currentDirection,const std::vector<Car> &collidingCars) override;

private:
    WorldMapManager *worldMapManager;
    bool compareOnPriority(const Car &currentCar,const Car &otherCar, const Direction &currentDirection);
    bool compareWithoutPriority(const Car &currentCar,const Car &otherCar, const Direction &currentDirection);
};


#endif //PRIORITYINTERSECTION_H
