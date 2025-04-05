//
// Created by User on 2025-04-05.
//

#ifndef WORLDMAPGENERATOR_H
#define WORLDMAPGENERATOR_H
#include <vector>

#include "Sign.h"
#include "WorldMapGridProvider.h"


class WorldMapGenerator {
public:
    std::vector<Sign> createSigns();
    WorldMapGenerator(WorldMapGridProvider *_worldMapGridProvider);
private:
    WorldMapGridProvider *worldMapGridProvider;
};


#endif //WORLDMAPGENERATOR_H
