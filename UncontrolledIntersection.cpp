
#include "UncontrolledIntersection.h"

#include "Car.h"
#include "DirectionMapper.h"
#include "GlobalConstants.h"
#include "VectorHelper.h"

UncontrolledIntersection::UncontrolledIntersection(EdgeCollisionDetector *_edgeCollisionDetector):Intersection(_edgeCollisionDetector) {}

bool UncontrolledIntersection::canGo(
    const Car &currentCar,
    const Direction &currentDirection,
    const std::vector<Car> &collidingCars
    ) {
    bool hasCollision = false;
    for (auto &car: collidingCars) {
        auto isEdgeCollision = edgeCollisionDetector->checkEdgeCollision(car.getNextPoints(), currentCar.getNextPoints(), FIELD_SCALE / 3);
        if (isEdgeCollision) {
            if (!compareEqualPriority(currentCar, car, currentDirection)) {
                hasCollision = true;
            }
        }
    }
    return !hasCollision;
}

bool UncontrolledIntersection::compareEqualPriority(const Car &currentCar,const Car &car, const Direction &currentDirection) {
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
