
#include "Movable.h"

#include <iostream>

#include "Speed.h"

void Movable::move() {
    if (speed == STOP) {
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
    if (nextPoints.size() == 0) {
        std::cout << "No upcoming points" << std::endl;
    }
}
