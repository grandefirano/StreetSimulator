
#ifndef FIELDHELPER_H
#define FIELDHELPER_H

#include "DirectionMapper.h"
#include "GlobalConstants.h"
#include "Point.h"
#include "Field.h"
#include "Direction.h"
#include <math.h>

inline Field mapToField(Point point) {
    int x = std::ceil(point.x / M_SCALE - 0.5);
    int y = std::ceil(point.y / M_SCALE - 0.5);
    return Field(x, y);
}

inline Point getCenterPoint(Field field) {
    int x = (field.x + 0.5) * M_SCALE;
    int y = (field.y + 0.5) * M_SCALE;
    return Point(x, y);
}

inline Field getOneFrontOneRight(Field field, const Direction &direction) {
    auto frontDirection = DirectionMapper::parseToFrontDirectionDelta(direction);
    auto rightDirection = DirectionMapper::parseToRightDirectionDelta(direction);
    return Field(field.x + frontDirection.x + rightDirection.x, field.y + frontDirection.y + rightDirection.y);
}

inline Field getOneFront(Field field, const Direction &direction) {
    auto frontDirection = DirectionMapper::parseToFrontDirectionDelta(direction);
    return Field(field.x + frontDirection.x, field.y + frontDirection.y);
}

inline Field getOneRight(Field field, const Direction &direction) {
    auto rightDirection = DirectionMapper::parseToRightDirectionDelta(direction);
    return Field(field.x + rightDirection.x, field.y + rightDirection.y);
}

#endif //FIELDHELPER_H
