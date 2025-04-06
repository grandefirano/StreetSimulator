
#ifndef ROADOPTION_H
#define ROADOPTION_H

#include <vector>
#include "Point.h"
#include "Direction.h"

/**
 * @struct RoadOption
 * @brief Road element of the world map.
 */
struct RoadOption {
    /**
     * @brief Sequential point positions of that road element accordingly to the direction of movement.
     */
    std::vector<Point> points;
    /**
     * @brief World map direction of movement on the end of the element.
     */
    Direction direction;
};

#endif //ROADOPTION_H
