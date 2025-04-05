
#include "CollisionDetector.h"

#include <iostream>
#include <vector>

#include "Car.h"
#include "DirectionMapper.h"
#include "FieldHelper.h"
#include "FieldValue.h"
#include "Intersection.h"
#include "LightsIntersection.h"
#include "PriorityIntersection.h"
#include "UncontrolledIntersection.h"

CollisionDetector::CollisionDetector(LightsManager *_lightsManager, WorldMapManager *_worldMapManager) {
    worldMapManager = _worldMapManager;
    lightsManager = _lightsManager;
}

bool CollisionDetector::checkIntersectionCollision(Car &car, std::vector<Car> &cars) {
    bool hasCollision = false;
    try {
        auto currentDirection = DirectionMapper::parseToDirection(worldMapManager->takeFieldValue(car.getField()));
        if (worldMapManager->takeFieldValue(getOneFront(car.getField(), currentDirection))== FV_INTERSECTION) {
            Intersection *intersection;
            auto rightFieldValue = worldMapManager->takeFieldValue(getOneRight(car.getField(), currentDirection));
            if (rightFieldValue==FV_LIGHT) {
                intersection = new LightsIntersection(lightsManager);
            } else if (rightFieldValue == FV_PRIORITY_SIGN || rightFieldValue == FV_NO_PRIORITY_SIGN) {
                intersection = new PriorityIntersection(worldMapManager);
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
