#include "CollisionDetector.h"

#include <vector>

#include "Car.h"
#include "DirectionMapper.h"
#include "FieldHelper.h"
#include "FieldValue.h"
#include "Intersection.h"
#include "LightsIntersection.h"
#include "PriorityIntersection.h"
#include "UncontrolledIntersection.h"

CollisionDetector::CollisionDetector(LightsManager *_lightsManager, WorldMapManager *_worldMapManager,EdgeCollisionDetector *_edgeCollisionDetector) {
    worldMapManager = _worldMapManager;
    lightsManager = _lightsManager;
    edgeCollisionDetector = _edgeCollisionDetector;
    lightsIntersection = new LightsIntersection(lightsManager,_edgeCollisionDetector);
    uncontrolledIntersection = new UncontrolledIntersection(_edgeCollisionDetector);
    priorityIntersection = new PriorityIntersection(worldMapManager,_edgeCollisionDetector);
}

bool CollisionDetector::checkIntersectionCollision(const Car &currentCar, const std::vector<Car> &cars) {
    bool hasCollision = false;
    try {
        auto currentDirection = DirectionMapper::parseToDirection(worldMapManager->takeFieldValue(currentCar.getField()));
        if (worldMapManager->takeFieldValue(getOneFront(currentCar.getField(), currentDirection)) == FV_INTERSECTION) {
            Intersection *intersection;
            auto rightFieldValue = worldMapManager->takeFieldValue(getOneRight(currentCar.getField(), currentDirection));
            if (rightFieldValue == FV_LIGHT) {
                intersection = lightsIntersection;
            } else if (rightFieldValue == FV_PRIORITY_SIGN || rightFieldValue == FV_NO_PRIORITY_SIGN) {
                intersection = priorityIntersection;
            } else {
                intersection = uncontrolledIntersection;
            }
            hasCollision = !intersection->canGo(currentCar, currentDirection, cars);
        }
    } catch (DirectionException directionException) {
        // the car is on the intersection
        return false;
    }
    return hasCollision;
}

bool CollisionDetector::checkPedestrianCollision(const Car &currentCar, const std::vector<Pedestrian> &pedestrians) {
    bool hasCollision = false;
    try {
        auto currentDirection = DirectionMapper::parseToDirection(
            worldMapManager->takeFieldValue(currentCar.getField()));
        auto frontFieldValue = worldMapManager->takeFieldValue(getOneFront(currentCar.getField(), currentDirection));
        auto isBeforeCrosswalk = frontFieldValue == FV_CROSSING;
        if (isBeforeCrosswalk) {
            for (auto &pedestrian: pedestrians) {
                auto isEdgeCollision = edgeCollisionDetector->checkEdgeCollision(
                    pedestrian.getNextPoints(),
                    currentCar.getNextPoints(),
                    FIELD_SCALE
                );
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
