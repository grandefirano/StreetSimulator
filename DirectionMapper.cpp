#include "DirectionMapper.h"


Direction DirectionMapper::parseToDirection(const FieldValue fieldValue) {
    if (fieldValue== FV_DOWN) return D_DOWN;
    if (fieldValue== FV_UP) return D_UP;
    if (fieldValue== FV_RIGHT) return D_RIGHT;
    if (fieldValue== FV_LEFT) return D_LEFT;
    throw DirectionException();
}

DirectionDelta DirectionMapper::parseToFrontDirectionDelta(const Direction &direction) {
    switch (direction) {
        case D_UP: return DirectionDelta(0, -1);
        case D_DOWN: return DirectionDelta(0, 1);
        case D_LEFT: return DirectionDelta(-1, 0);
        case D_RIGHT: return DirectionDelta(1, 0);
        default: throw std::invalid_argument("Invalid direction");
    }
}

DirectionDelta DirectionMapper::parseToRightDirectionDelta(const Direction &direction) {
    switch (direction) {
        case D_UP: return DirectionDelta(1, 0);
        case D_DOWN: return DirectionDelta(-1, 0);
        case D_LEFT: return DirectionDelta(0, -1);
        case D_RIGHT: return DirectionDelta(0, 1);
        default: throw std::invalid_argument("Invalid direction");
    }
}

RelativeDirection DirectionMapper::parseToRelativeDirection(const Direction &currentDirection, const Direction &nextDirection) {
    switch (currentDirection) {
        case D_UP:
            switch (nextDirection) {
                case D_UP: return REL_STRAIGHT;
                case D_RIGHT: return REL_RIGHT;
                case D_LEFT: return REL_LEFT;
                default: throw std::invalid_argument("Invalid relative direction");
            }
        case D_DOWN:
            switch (nextDirection) {
                case D_DOWN: return REL_STRAIGHT;
                case D_RIGHT: return REL_LEFT;
                case D_LEFT: return REL_RIGHT;
                default: throw std::invalid_argument("Invalid relative direction");
            }
        case D_LEFT:
            switch (nextDirection) {
                case D_LEFT: return REL_STRAIGHT;
                case D_UP: return REL_RIGHT;
                case D_DOWN: return REL_LEFT;
                default: throw std::invalid_argument("Invalid relative direction");
            }
        case D_RIGHT:
            switch (nextDirection) {
                case D_RIGHT: return REL_STRAIGHT;
                case D_DOWN: return REL_RIGHT;
                case D_UP: return REL_LEFT;
                default: throw std::invalid_argument("Invalid relative direction");
            }
        default: throw std::invalid_argument("Invalid current direction");
    }
}