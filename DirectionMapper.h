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

class DirectionMapper {
public:
    static Direction parseToDirection(FieldValue fieldValue) {
        if (fieldValue== FV_DOWN) return D_DOWN;
        if (fieldValue== FV_UP) return D_UP;
        if (fieldValue== FV_RIGHT) return D_RIGHT;
        if (fieldValue== FV_LEFT) return D_LEFT;
        throw DirectionException();
    }

    static DirectionDelta parseToFrontDirectionDelta(Direction direction) {
        switch (direction) {
            case D_UP: return DirectionDelta(0, -1);
            case D_DOWN: return DirectionDelta(0, 1);
            case D_LEFT: return DirectionDelta(-1, 0);
            case D_RIGHT: return DirectionDelta(1, 0);
            default: throw std::invalid_argument("Invalid direction");
        }
    }

    static DirectionDelta parseToRightDirectionDelta(Direction direction) {
        switch (direction) {
            case D_UP: return DirectionDelta(1, 0);
            case D_DOWN: return DirectionDelta(-1, 0);
            case D_LEFT: return DirectionDelta(0, -1);
            case D_RIGHT: return DirectionDelta(0, 1);
            default: throw std::invalid_argument("Invalid direction");
        }
    }


    static RelativeDirection parseToRelativeDirection(Direction currentDirection, Direction nextDirection) {
        switch (currentDirection) {
            case D_UP:
                switch (nextDirection) {
                    case D_UP: return REL_STRAIGHT;
                    case D_RIGHT: return REL_RIGHT;
                    case D_LEFT: return REL_LEFT;
                    default: throw std::invalid_argument("Invalid return direction");
                }
            case D_DOWN:
                switch (nextDirection) {
                    case D_DOWN: return REL_STRAIGHT;
                    case D_RIGHT: return REL_LEFT;
                    case D_LEFT: return REL_RIGHT;
                    default: throw std::invalid_argument("Invalid return direction");
                }
            case D_LEFT:
                switch (nextDirection) {
                    case D_LEFT: return REL_STRAIGHT;
                    case D_UP: return REL_RIGHT;
                    case D_DOWN: return REL_LEFT;
                    default: throw std::invalid_argument("Invalid return direction");
                }
            case D_RIGHT:
                switch (nextDirection) {
                    case D_RIGHT: return REL_STRAIGHT;
                    case D_DOWN: return REL_RIGHT;
                    case D_UP: return REL_LEFT;
                    default: throw std::invalid_argument("Invalid return direction");
                }
        }
    }
};

#endif //DIRECTIONMAPPER_H
