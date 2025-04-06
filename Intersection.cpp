//
// Created by User on 2025-03-23.
//

#include "Intersection.h"

#include "DirectionMapper.h"

Intersection::Intersection(EdgeCollisionDetector *_edgeCollisionDetector) {
    edgeCollisionDetector = _edgeCollisionDetector;
}

Field Intersection::getIntersectionEntrance(const Field &field, const Direction &direction, const Entrance &entrance) {
    int rightFactor;
    int frontFactor;
    switch (entrance) {
        case ENTR_STRAIGHT:
            rightFactor = -1;
        frontFactor = 3;
        break;
        case ENTR_RIGHT:
            rightFactor = 1;
        frontFactor = 2;
        break;
        case ENTR_LEFT:
            rightFactor = -2;
        frontFactor = 1;
        break;
        default:
            throw std::invalid_argument("Invalid entrance");
    }
    auto frontDirection = DirectionMapper::parseToFrontDirectionDelta(direction);
    auto rightDirection = DirectionMapper::parseToRightDirectionDelta(direction);
    return Field(
        field.x + frontFactor * frontDirection.x + rightFactor * rightDirection.x,
        field.y + frontFactor * frontDirection.y + rightFactor * rightDirection.y
    );
}

std::vector<Field> Intersection::getIntersectionFields(const Field &field, const Direction &direction) {
    std::vector<Field> intersection;
    auto frontDirection = DirectionMapper::parseToFrontDirectionDelta(direction);
    auto rightDirection = DirectionMapper::parseToRightDirectionDelta(direction);
    intersection.push_back(Field(
        field.x + 1 * frontDirection.x + 0 * rightDirection.x,
        field.y + 1 * frontDirection.y + 0 * rightDirection.y
    ));

    intersection.push_back(Field(
        field.x + 1 * frontDirection.x - 1 * rightDirection.x,
        field.y + 1 * frontDirection.y - 1 * rightDirection.y
    ));

    intersection.push_back(Field(
        field.x + 2 * frontDirection.x + 0 * rightDirection.x,
        field.y + 2 * frontDirection.y + 0 * rightDirection.y
    ));
    intersection.push_back(Field(
        field.x + 2 * frontDirection.x - 1 * rightDirection.x,
        field.y + 2 * frontDirection.y - 1 * rightDirection.y
    ));
    return intersection;
}

