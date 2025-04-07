//
// Created by User on 2025-03-23.
//

#ifndef DIRECTIONMAPPER_H
#define DIRECTIONMAPPER_H
#include <stdexcept>

#include "FieldValue.h"
#include "Direction.h"
#include "DirectionException.h"
#include "DirectionDelta.h"
#include "RelativeDirection.h"

/**
 * @class DirectionMapper
 * @brief Takes care of mapping from and to Direction objects.
 */
class DirectionMapper {
public:
    /**
     *@brief Mapper from FieldValue to Direction.
     * @param fieldValue Value of the field to be mapped to direction.
     * @return Direction of that field.
     */
    static Direction parseToDirection(const FieldValue fieldValue);

    /**
     *@brief Mapper from Direction to front DirectionDelta.
     * @param direction Direction to be mapped to direction delta.
     * @return Front DirectionDelta that represents given direction.
     */
    static DirectionDelta parseToFrontDirectionDelta(const Direction &direction);

    /**
    *@brief Mapper from Direction to right DirectionDelta.
    * @param direction Direction to be mapped to direction delta.
    * @return DirectionDelta that represents right direction (90 degrees right turn) from given direction.
    */
    static DirectionDelta parseToRightDirectionDelta(const Direction &direction);

    /**
     *@brief Mapper from Direction to RelativeDirection.
     * @param currentDirection Current direction of the object.
     * @param nextDirection Direction that is compared to the current direction.
     * @return Relative direction of the next direction calculated based on the current direction.
     */
    static RelativeDirection
    parseToRelativeDirection(const Direction &currentDirection, const Direction &nextDirection);
};

#endif //DIRECTIONMAPPER_H
