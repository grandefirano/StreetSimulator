
#ifndef LIGHTSINTERSECTION_H
#define LIGHTSINTERSECTION_H
#include "Car.h"
#include "Intersection.h"
#include "LightsManager.h"

/**
 *@class LightsIntersection
 * @brief Subclass of the Intersection, which detects if car can enter intersection with traffic lights.
 */
class LightsIntersection : public Intersection {
public:
    /**
     * @brief Constructor of LightsIntersection.
     * @param _lightsManager LightsManager to read the lights color.
     * @param _edgeCollisionDetector Edge collision detector to detect collisions between cars.
     */
    LightsIntersection(LightsManager *_lightsManager,EdgeCollisionDetector *_edgeCollisionDetector);

    /**
     * @brief Detects if car can enter the intersection with traffic lights at given time without colliding with other objects.
     * @param currentCar Current car which priority is checked.
     * @param currentDirection Current direction of the car.
     * @param collidingCars List of other cars.
     * @return True if car has priority, green light and can enter the intersection at this moment, false if it cannot.
     */
    bool canGo(const Car &currentCar,const  Direction &currentDirection,const  std::vector<Car> &collidingCars) override;

private:
    LightsManager *lightsManager;

    bool compareLightsPriority(const Car &currentCar, const Car &car,const Direction &currentDirection);
};

#endif //LIGHTSINTERSECTION_H
