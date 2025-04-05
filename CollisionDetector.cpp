
#include "CollisionDetector.h"

#include <vector>

#include "Car.h"
#include "DirectionMapper.h"
#include "FieldHelper.h"
#include "FieldValue.h"
#include "Intersection.h"
#include "LightsIntersection.h"
#include "UncontrolledIntersection.h"

CollisionDetector::CollisionDetector(WorldMapGridProvider *worldMapGridProvider,LightsManager *_lightsManager) {
    grid = worldMapGridProvider->provideGrid();
    lightsManager = _lightsManager;
}

bool CollisionDetector::checkIntersectionCollision(Car &car, std::vector<Car> &cars) {
    bool hasCollision = false;
    try {
        auto currentDirection = DirectionMapper::parseToDirection(takeFieldValue(car.getField(), grid));
        if (takeFieldValue(getOneFront(car.getField(), currentDirection), grid)== FV_INTERSECTION) {
            Intersection *intersection;
            auto rightField = getOneRight(car.getField(), currentDirection);
            if (takeFieldValue(rightField,grid)==FV_LIGHT) {

                intersection = new LightsIntersection(lightsManager);
            } else {
                intersection = new UncontrolledIntersection();
            }
            hasCollision = !intersection->canGo(car, currentDirection, cars);
        }
    } catch (DirectionException directionException) {
        // the car is on the intersection
        return false;
    }
    return hasCollision;
}
