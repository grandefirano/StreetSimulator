
#ifndef WORLDMAPMANAGER_H
#define WORLDMAPMANAGER_H
#include <vector>

#include "Crossing.h"
#include "FieldValue.h"
#include "Sign.h"
#include "WorldMapGridProvider.h"


class WorldMapManager {
public:
    std::vector<Sign> createSigns();
    std::vector<Crossing> createCrossings();
    std::vector<Field> createPedestrianSpawns();
    FieldValue takeFieldValue(Field field);
    WorldMapManager(WorldMapGridProvider *_worldMapGridProvider);
private:
    WorldMapGridProvider *worldMapGridProvider;
};


#endif //WORLDMAPMANAGER_H
