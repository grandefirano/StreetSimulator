
#include "CrosswalkManager.h"


std::vector<Pedestrian> CrosswalkManager::getPedestrians() {
    return pedestrians;
}

void CrosswalkManager::nextFrame() {
    for (auto pedestrian : pedestrians) {
        pedestrian.move();
    }
}

void CrosswalkManager::generatePedestrianRandomly() {

}


