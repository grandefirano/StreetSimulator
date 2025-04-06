
#ifndef WORLDMAPMANAGER_H
#define WORLDMAPMANAGER_H
#include <vector>

#include "Crossing.h"
#include "FieldValue.h"
#include "Sign.h"
#include "WorldMapGridProvider.h"


class WorldMapManager {
public:
    WorldMapManager(WorldMapGridProvider *_worldMapGridProvider);
    std::vector<Sign> createSigns();
    std::vector<Crossing> createCrossings();
    std::vector<Field> createPedestrianSpawns();
    FieldValue takeFieldValue(const Field &field);
private:
    WorldMapGridProvider *worldMapGridProvider;
};


#endif //WORLDMAPMANAGER_H
