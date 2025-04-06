#ifndef CROSSWALKMANAGER_H
#define CROSSWALKMANAGER_H
#include <vector>

#include "Pedestrian.h"
#include "WorldMapManager.h"


class CrosswalkManager {
private:
    int count;
    WorldMapManager *worldMapManager;
    std::vector<Field> spawns;
    std::vector<Pedestrian> pedestrians;
    void generatePedestrianRandomly();

public:
    std::vector<Pedestrian> getPedestrians();

    CrosswalkManager(WorldMapManager *_worldMapManager);

    void nextFrame();
};


#endif //CROSSWALKMANAGER_H
