
#include "Movable.h"

#include <cmath>
#include <iostream>

#include "GlobalConstants.h"
#include "Speed.h"

void Movable::move() {
    if (nextPoints.size() == 0 || speed == STOP) {
        //do nothing
    } else if (speed == SLOW) {
        position = nextPoints.front();
        nextPoints.erase(nextPoints.begin());
    } else if (speed == NORMAL) {
        position = nextPoints.front();
        nextPoints.erase(nextPoints.begin(), nextPoints.begin() + 2);
    } else if (speed == FAST) {
        position = nextPoints.front();
        nextPoints.erase(nextPoints.begin(), nextPoints.begin() + 3);
    }

}

float Movable::getRotation() {
    if (nextPoints.size() <=3) {
        return 0.0f;
    }
    auto currentPoint = nextPoints.at(0);
    auto nextPoint = nextPoints.at(2);
    return atan2(nextPoint.y - currentPoint.y, nextPoint.x - currentPoint.x) * 180 / PI;
}

Point Movable::getPosition() const {
    return position;
}

std::vector<Point> Movable::getNextPoints() const {
    return nextPoints;
}