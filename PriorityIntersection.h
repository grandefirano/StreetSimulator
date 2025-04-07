
#ifndef PRIORITYINTERSECTION_H
#define PRIORITYINTERSECTION_H
#include "Intersection.h"
#include "WorldMapManager.h"
/**
 *@class PriorityIntersection
 * @brief Subclass of the Intersection, which detects if car can enter intersection with priority signs.
 */
class PriorityIntersection : public Intersection {
public:
    /**
     * @brief Constructor of PriorityIntersection.
     * @param worldMapManager WorldMapManager to take fieldValues.
     * @param _edgeCollisionDetector Edge collision detector to detect collisions between cars.
     */
    PriorityIntersection(WorldMapManager *worldMapManager,EdgeCollisionDetector *_edgeCollisionDetector);
    /**
     * @brief Detects if car can enter the intersection with priority signs at given time without colliding with other objects.
     * @param currentCar Current car which priority is checked.
     * @param currentDirection Current direction of the car.
     * @param collidingCars List of other cars.
     * @return True if car has priority based partially on priority signs and can enter the intersection at this moment, false if it cannot.
     */
    bool canGo(const Car &currentCar,const Direction &currentDirection,const std::vector<Car> &collidingCars) override;

private:
    WorldMapManager *worldMapManager;
    bool compareOnPriority(const Car &currentCar,const Car &otherCar, const Direction &currentDirection);
    bool compareWithoutPriority(const Car &currentCar,const Car &otherCar, const Direction &currentDirection);
};


#endif //PRIORITYINTERSECTION_H
