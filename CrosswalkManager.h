
#ifndef CROSSWALKMANAGER_H
#define CROSSWALKMANAGER_H
#include <vector>

#include "Pedestrian.h"


class CrosswalkManager {
    private:
      std::vector<Pedestrian> pedestrians;
public:
    std::vector<Pedestrian> getPedestrians();
    void generatePedestrianRandomly();
    void nextFrame();
};


#endif //CROSSWALKMANAGER_H
