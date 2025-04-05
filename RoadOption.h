
#ifndef ROADOPTION_H
#define ROADOPTION_H

#include <vector>
#include "Point.h"
#include "Direction.h"

struct RoadOption {
    std::vector<Point> points;
    Direction direction;
};

#endif //ROADOPTION_H
