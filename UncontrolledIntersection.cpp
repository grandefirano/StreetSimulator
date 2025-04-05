
#include "UncontrolledIntersection.h"

#include <iostream>

#include "Car.h"
#include "DirectionMapper.h"
#include "EdgeCollisionHelper.h"
#include "VectorHelper.h"

bool UncontrolledIntersection::canGo(Car &currentCar, Direction currentDirection,
                                     std::vector<Car> collidingCars) {
    bool hasCollision = false;
    for (auto &car: collidingCars) {
        auto isEdgeCollision = checkEdgeCollision(car.getNextPoints(), currentCar.getNextPoints(), 31 / 3);
        if (isEdgeCollision) {
            if (!compareEqualPriority(currentCar, car, currentDirection)) {
                hasCollision = true;
            }
        }
    }
    return !hasCollision;
}

bool UncontrolledIntersection::compareEqualPriority(Car &currentCar, Car &car, const Direction &currentDirection) {
    auto field = currentCar.getField();
    auto onTheRight = getIntersectionEntrance(field, currentDirection, ENTR_RIGHT);
    auto inFront = getIntersectionEntrance(field, currentDirection, ENTR_STRAIGHT);
    auto intersection = getIntersectionFields(field, currentDirection);

    auto relativeDirection = DirectionMapper::parseToRelativeDirection(currentDirection, currentCar.getNextDirection());
    if (contains<Field>(intersection, car.getField())) {
        return false;
    }
    if (relativeDirection == REL_RIGHT) {
        return true;
    }
    if (relativeDirection == REL_STRAIGHT) {
        if (car.getField() == onTheRight) {
            return false;
        } else {
            return true;
        }
    }
    if (relativeDirection == REL_LEFT) {
        auto otherCarField = car.getField();
        if (otherCarField == onTheRight) {
            return false;
        } else if (otherCarField == inFront) {
            return false;
        } else {
            return true;
        }
    }
    return true;
}
