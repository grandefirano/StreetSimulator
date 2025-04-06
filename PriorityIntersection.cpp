//
// Created by User on 2025-04-05.
//

#include "PriorityIntersection.h"

#include "DirectionMapper.h"
#include "EdgeCollisionHelper.h"
#include "FieldHelper.h"
#include "VectorHelper.h"

PriorityIntersection::PriorityIntersection(WorldMapManager *_worldMapManager,EdgeCollisionDetector *_edgeCollisionDetector):Intersection(_edgeCollisionDetector) {
    worldMapManager = _worldMapManager;
}

bool PriorityIntersection::canGo(Car &currentCar, Direction currentDirection,
                                 std::vector<Car> collidingCars) {
    bool hasCollision = false;
    auto rightFieldValue = worldMapManager->takeFieldValue(getOneRight(currentCar.getField(), currentDirection));
    auto isOnPriorityRoad = rightFieldValue == FV_PRIORITY_SIGN;
    for (auto &car: collidingCars) {
        auto isEdgeCollision = edgeCollisionDetector->checkEdgeCollision(car.getNextPoints(), currentCar.getNextPoints(), 31 / 3);
        if (isEdgeCollision) {
            auto intersection = getIntersectionFields(currentCar.getField(), currentDirection);
            if (contains<Field>(intersection, car.getField())) {
                return false;
            }
            //it bases on the assumption that priority roads are only straight (the intersection cannot be priority on a turn)
            if (isOnPriorityRoad) {
                //current car is on priority road
                if (!compareOnPriority(currentCar, car, currentDirection)) {
                    hasCollision = true;
                }
            } else {
                //current car isn't on priority road
                if (!compareWithoutPriority(currentCar, car, currentDirection)) {
                    hasCollision = true;
                }
            }
        }
    }
    return !hasCollision;
}

bool PriorityIntersection::compareOnPriority(Car &currentCar, Car &otherCar, const Direction &currentDirection) {
    auto inFront = getIntersectionEntrance(currentCar.getField(), currentDirection, ENTR_STRAIGHT);
    auto relativeDirection = DirectionMapper::parseToRelativeDirection(currentDirection, currentCar.getNextDirection());
    if (relativeDirection == REL_RIGHT) {
        return true;
    }
    if (relativeDirection == REL_STRAIGHT) {
        return true;
    }
    if (relativeDirection == REL_LEFT) {
        auto otherCarField = otherCar.getField();
        if (otherCarField == inFront) {
            return false;
        } else {
            return true;
        }
    }
    return true;
}

bool PriorityIntersection::compareWithoutPriority(Car &currentCar, Car &otherCar, const Direction &currentDirection) {
    auto inFront = getIntersectionEntrance(currentCar.getField(), currentDirection, ENTR_STRAIGHT);
    auto onTheRight = getIntersectionEntrance(currentCar.getField(), currentDirection, ENTR_RIGHT);
    auto onTheLeft = getIntersectionEntrance(currentCar.getField(), currentDirection, ENTR_LEFT);
    auto relativeDirection = DirectionMapper::parseToRelativeDirection(currentDirection, currentCar.getNextDirection());
    auto otherCarField = otherCar.getField();
    if (relativeDirection == REL_RIGHT) {
        if (otherCarField == onTheLeft) {
            return false;
        }
        return true;
    }
    if (relativeDirection == REL_STRAIGHT) {
        if (otherCarField == onTheLeft || otherCarField == onTheRight) {
            return false;
        }
        return true;
    }
    if (relativeDirection == REL_LEFT) {
        if (otherCarField == onTheLeft || otherCarField == onTheRight || otherCarField == inFront) {
            return false;
        } else {
            return true;
        }
    }
    return true;
}
