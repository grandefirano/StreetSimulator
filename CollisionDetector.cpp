#include "CollisionDetector.h"

#include <iostream>
#include <vector>

#include "Car.h"
#include "DirectionMapper.h"
#include "EdgeCollisionHelper.h"
#include "FieldHelper.h"
#include "FieldValue.h"
#include "Intersection.h"
#include "LightsIntersection.h"
#include "PriorityIntersection.h"
#include "UncontrolledIntersection.h"

CollisionDetector::CollisionDetector(LightsManager *_lightsManager, WorldMapManager *_worldMapManager) {
    worldMapManager = _worldMapManager;
    lightsManager = _lightsManager;
    lightsIntersection = new LightsIntersection(lightsManager);
    uncontrolledIntersection = new UncontrolledIntersection();
    priorityIntersection = new PriorityIntersection(worldMapManager);
}

bool CollisionDetector::checkIntersectionCollision(Car &car, std::vector<Car> &cars) {
    bool hasCollision = false;
    try {
        auto currentDirection = DirectionMapper::parseToDirection(worldMapManager->takeFieldValue(car.getField()));
        if (worldMapManager->takeFieldValue(getOneFront(car.getField(), currentDirection)) == FV_INTERSECTION) {
            Intersection *intersection;
            auto rightFieldValue = worldMapManager->takeFieldValue(getOneRight(car.getField(), currentDirection));
            if (rightFieldValue == FV_LIGHT) {
                intersection = lightsIntersection;
            } else if (rightFieldValue == FV_PRIORITY_SIGN || rightFieldValue == FV_NO_PRIORITY_SIGN) {
                intersection = priorityIntersection;
            } else {
                intersection = uncontrolledIntersection;
            }
            hasCollision = !intersection->canGo(car, currentDirection, cars);
        }
    } catch (DirectionException directionException) {
        // the car is on the intersection
        return false;
    }
    return hasCollision;
}

bool CollisionDetector::checkPedestrianCollision(Car &currentCar, std::vector<Pedestrian> &pedestrians) {
    bool hasCollision = false;
    try {
        auto currentDirection = DirectionMapper::parseToDirection(
            worldMapManager->takeFieldValue(currentCar.getField()));
        auto frontFieldValue = worldMapManager->takeFieldValue(getOneFront(currentCar.getField(), currentDirection));
        auto isBeforeCrosswalk = frontFieldValue == FV_CROSSING;
        if (isBeforeCrosswalk) {
            for (auto &pedestrian: pedestrians) {
                auto isEdgeCollision = checkEdgeCollision(pedestrian.getNextPoints(), currentCar.getNextPoints(),
                                                          M_SCALE/2);
                if (isEdgeCollision) {
                    hasCollision = true;
                }
            }
        }
    } catch (DirectionException directionException) {
        // the car is on the intersection
        return false;
    }
    return hasCollision;
}
