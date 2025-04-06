
#include "LightsIntersection.h"

#include "FieldHelper.h"
#include "VectorHelper.h"

LightsIntersection::LightsIntersection(LightsManager *_lightsManager,EdgeCollisionDetector *_edgeCollisionDetector):Intersection(_edgeCollisionDetector), lightsManager(_lightsManager) {
}

bool LightsIntersection::canGo(const Car &currentCar,const Direction &currentDirection,const std::vector<Car> &collidingCars) {
    bool hasCollision = false;
    auto rightField = getOneRight(currentCar.getField(), currentDirection);
    for (auto car: collidingCars) {
        auto isEdgeCollision = edgeCollisionDetector->checkEdgeCollision(car.getNextPoints(), currentCar.getNextPoints(), FIELD_SCALE / 3);
        if (lightsManager->isGreenLight(rightField)) {
            if (isEdgeCollision) {
                if (!compareLightsPriority(currentCar, car, currentDirection)) {
                    hasCollision = true;
                }
            }
        } else {
            hasCollision = true;
        }
    }
    return !hasCollision;
}

bool LightsIntersection::compareLightsPriority(const Car &currentCar, const Car &car,const Direction &currentDirection) {
    auto inFront = getIntersectionEntrance(currentCar.getField(), currentDirection, ENTR_STRAIGHT);
    auto intersection = getIntersectionFields(currentCar.getField(), currentDirection);

    auto relativeDirection = DirectionMapper::parseToRelativeDirection(currentDirection, currentCar.getNextDirection());
    if (contains<Field>(intersection, car.getField())) {
        return false;
    }
    if (relativeDirection == REL_RIGHT) {
        return true;
    }
    if (relativeDirection == REL_STRAIGHT) {
        return true;
    }
    if (relativeDirection == REL_LEFT) {
        auto otherCarField = car.getField();
        if (otherCarField == inFront) {
            return false;
        } else {
            return true;
        }
    }
    return false;
}
