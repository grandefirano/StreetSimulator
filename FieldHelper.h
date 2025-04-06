
#ifndef FIELDHELPER_H
#define FIELDHELPER_H

#include "DirectionMapper.h"
#include "GlobalConstants.h"
#include "Point.h"
#include "Field.h"
#include "Direction.h"
#include <math.h>

/**
 * @brief Mapper from Point to Field.
 * @param point Point to be mapped to Field.
 * @return Field that wraps the given Point on the map.
 */
inline Field mapToField(const Point &point) {
    int x = std::ceil(point.x / FIELD_SCALE - 0.5);
    int y = std::ceil(point.y / FIELD_SCALE - 0.5);
    return Field(x, y);
}

/**
 * @brief Mapper from Field to center Point of that field.
 * @param field Field to be mapped to the Point.
 * @return Point that is in the center of the given Field.
 */
inline Point getCenterPoint(const Field &field) {
    int x = (field.x + 0.5) * FIELD_SCALE;
    int y = (field.y + 0.5) * FIELD_SCALE;
    return Point(x, y);
}

/**
 * @brief Helper function to get field relatively positioned on the front-right to the current field based on current direction.
 * @param field Current field.
 * @param direction Current direction, which axis is used to calculate relative position of the other field.
 * @return Field diagonally on the relative front-right position.
 */
inline Field getOneFrontOneRight(const Field &field, const Direction &direction) {
    auto frontDirection = DirectionMapper::parseToFrontDirectionDelta(direction);
    auto rightDirection = DirectionMapper::parseToRightDirectionDelta(direction);
    return Field(field.x + frontDirection.x + rightDirection.x, field.y + frontDirection.y + rightDirection.y);
}
/**
 * @brief Helper function to get field relatively positioned on the front to the current field based on current direction.
 * @param field Current field.
 * @param direction Current direction, which axis is used to calculate relative position of the other field.
 * @return Field on the relative front position.
 */
inline Field getOneFront(const Field &field, const Direction &direction) {
    auto frontDirection = DirectionMapper::parseToFrontDirectionDelta(direction);
    return Field(field.x + frontDirection.x, field.y + frontDirection.y);
}

/**
 * @brief Helper function to get field relatively positioned on the right to the current field based on current direction.
 * @param field Current field.
 * @param direction Current direction, which axis is used to calculate relative position of the other field.
 * @return Field on the relative right position.
 */
inline Field getOneRight(const Field &field, const Direction &direction) {
    auto rightDirection = DirectionMapper::parseToRightDirectionDelta(direction);
    return Field(field.x + rightDirection.x, field.y + rightDirection.y);
}

#endif //FIELDHELPER_H
