
#ifndef UNCONTROLLEDINTERSECTION_H
#define UNCONTROLLEDINTERSECTION_H
#include <vector>

#include "Intersection.h"

class Car;

/**
 *@class UncontrolledIntersection
 * @brief Subclass of the Intersection, which detects if car can enter uncontrolled intersection.
 */
class UncontrolledIntersection : public Intersection {
public:
    /**
     * @brief Constructor of UncontrolledIntersection.
     * @param _edgeCollisionDetector Edge collision detector to detect collisions between cars.
     */
    UncontrolledIntersection(EdgeCollisionDetector *_edgeCollisionDetector);
    /**
    * @brief Detects if car can enter the uncontrolled intersection at given time without colliding with other objects.
    * @param currentCar Current car which priority is checked.
    * @param currentDirection Current direction of the car.
    * @param collidingCars List of other cars.
    * @return True if car has priority based right hand rule and can enter the intersection at this moment, false if it cannot.
    */
    bool canGo(const Car &currentCar,const Direction &currentDirection, const std::vector<Car> &collidingCars) override;

private:
    bool compareEqualPriority(const Car &currentCar,const Car &car, const Direction &currentDirection);
};


#endif //UNCONTROLLEDINTERSECTION_H
