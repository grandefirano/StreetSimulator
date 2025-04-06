
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

/**
 * @class CollisionDetector
 * @brief Responsible for detecting the collision between objects based on the movement paths of them and movement priority of them.
 */
class CollisionDetector {
public:
    /**
     * @brief Constructor of CollisionDetector.
     * @param _lightsManager LightsManager for an intersection with lights.
     * @param _worldMapManager WorldMapManager for reading values of fields.
     * @param _edgeCollisionDetector EdgeCollisionDetector for detecting if paths overlaps.
     */
    CollisionDetector(LightsManager *_lightsManager, WorldMapManager *_worldMapManager,EdgeCollisionDetector *_edgeCollisionDetector);

    /**
     * @brief Checks if car has collision with other cars from the list and need to give way to them.
     * @param currentCar Current car which priority of way is compared to the list of cars.
     * @param cars List of other cars, excluding the current car.
     * @return Flag of collision of a current car with any other car, where this car doesn't have priority and need to give way.
     */
    bool checkIntersectionCollision(const Car &currentCar, const std::vector<Car> &cars);

    /**
     * @brief Checks if car has collision with pedestrians from the list, when it is approaching the crossing.
     * @param currentCar Current car which collision is being established.
     * @param pedestrians List of all pedestrians.
     * @return Flag of collision of a current car with any of pedestrians.
     */
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
