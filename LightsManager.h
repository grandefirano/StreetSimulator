
#ifndef LIGHTSMANAGER_H
#define LIGHTSMANAGER_H

#include "Light.h"
#include "RoadGenerator.h"

class LightsManager {
public:
    LightsManager(WorldMapGridProvider *_worldMapGridProvider);
    bool isGreenLight(const Field &field);
    std::vector<Light> getAllLights();
    void setTime(int time);
private:
    void findIntersectionLights(const GridType &grid);
    std::vector<Field> group1;
    std::vector<Field> group2;
    int time;
};



#endif //LIGHTSMANAGER_H
