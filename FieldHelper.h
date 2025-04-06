
#ifndef FIELDHELPER_H
#define FIELDHELPER_H

#include "DirectionMapper.h"
#include "GlobalConstants.h"
#include "Point.h"
#include "Field.h"
#include "Direction.h"
#include <math.h>

inline Field mapToField(const Point &point) {
    int x = std::ceil(point.x / FIELD_SCALE - 0.5);
    int y = std::ceil(point.y / FIELD_SCALE - 0.5);
    return Field(x, y);
}

inline Point getCenterPoint(const Field &field) {
    int x = (field.x + 0.5) * FIELD_SCALE;
    int y = (field.y + 0.5) * FIELD_SCALE;
    return Point(x, y);
}

inline Field getOneFrontOneRight(const Field &field, const Direction &direction) {
    auto frontDirection = DirectionMapper::parseToFrontDirectionDelta(direction);
    auto rightDirection = DirectionMapper::parseToRightDirectionDelta(direction);
    return Field(field.x + frontDirection.x + rightDirection.x, field.y + frontDirection.y + rightDirection.y);
}

inline Field getOneFront(const Field &field, const Direction &direction) {
    auto frontDirection = DirectionMapper::parseToFrontDirectionDelta(direction);
    return Field(field.x + frontDirection.x, field.y + frontDirection.y);
}

inline Field getOneRight(const Field &field, const Direction &direction) {
    auto rightDirection = DirectionMapper::parseToRightDirectionDelta(direction);
    return Field(field.x + rightDirection.x, field.y + rightDirection.y);
}

#endif //FIELDHELPER_H
