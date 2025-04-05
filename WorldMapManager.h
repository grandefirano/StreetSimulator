
#ifndef WORLDMAPMANAGER_H
#define WORLDMAPMANAGER_H
#include <vector>

#include "FieldValue.h"
#include "Sign.h"
#include "WorldMapGridProvider.h"


class WorldMapManager {
public:
    std::vector<Sign> createSigns();
    FieldValue takeFieldValue(int x, int y, GridType &grid);
    FieldValue takeFieldValue(Field field);
    WorldMapManager(WorldMapGridProvider *_worldMapGridProvider);
private:
    WorldMapGridProvider *worldMapGridProvider;
};


#endif //WORLDMAPMANAGER_H
