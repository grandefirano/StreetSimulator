
#ifndef INTERSECTION_H
#define INTERSECTION_H
#include "Car.h"
#include "EdgeCollisionDetector.h"

/**
 *@class Intersection
 * @brief Base intersection parent class that detect if a car have priority on it.
 */
class Intersection {
public:
    /**
     * @brief Detects if car can enter the intersection at given time without colliding with other objects.
     * @param currentCar Current car which priority is checked.
     * @param currentDirection Current direction of the car.
     * @param collidingCars List of other cars.
     * @return True if car has priority and can enter the intersection at this moment, false if it cannot.
     */
    virtual bool canGo(const Car &currentCar, const Direction &currentDirection,const std::vector<Car> &collidingCars) =0;
protected:
    /**
     * @brief Edge collision detector to be used by subclasses to check overlaping of trajectories.
     */
    EdgeCollisionDetector *edgeCollisionDetector;

    /**
     * @brief Represents other entrances of the intersection for an approaching car.
     */
    enum Entrance {ENTR_STRAIGHT,ENTR_LEFT,ENTR_RIGHT};

    /**
     * @brief Constructor if Intersection.
     * @param _edgeCollisionDetector Edge collision detector for subclasses.
     */
    Intersection(EdgeCollisionDetector *_edgeCollisionDetector);

    /**
     * @brief Finds fields of intersection relatively positioned entrance.
     * @param field Current field of a car.
     * @param direction Current direction of a car.
     * @param entrance Entrance which field is to be found.
     * @return Field of the entrance.
     */
    Field getIntersectionEntrance(const Field &field, const Direction &direction,const Entrance &entrance);

    /**
     * @brief Finds all the fields of the upcoming intersection.
     * @param field Current field.
     * @param direction Current direction.
     * @return List of fields of the intersection.
     */
    std::vector<Field> getIntersectionFields(const Field &field, const Direction &direction);
};

#endif //INTERSECTION_H
