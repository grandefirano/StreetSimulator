
#ifndef PRIORITYINTERSECTION_H
#define PRIORITYINTERSECTION_H
#include "Intersection.h"
#include "WorldMapManager.h"

class PriorityIntersection : public Intersection {
public:
    PriorityIntersection(WorldMapManager *worldMapManager);
    bool canGo(Car &currentCar, Direction currentDirection, std::vector<Car> collidingCars) override;

private:
    WorldMapManager *worldMapManager;
    bool compareOnPriority(Car &currentCar, Car &car, const Direction &currentDirection);
    bool compareWithoutPriority(Car &currentCar, Car &car, const Direction &currentDirection);
};


#endif //PRIORITYINTERSECTION_H
