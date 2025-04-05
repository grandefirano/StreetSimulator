#include "WorldMapGenerator.h"

#include "FieldValue.h"

std::vector<Sign> WorldMapGenerator::createSigns() {
    auto grid = worldMapGridProvider->provideGrid();
    std::vector<Sign> signs;
    for (int y = 0; y < grid.size(); y++) {
        for (int x = 0; x < grid[y].size(); x++) {
            auto fieldValue = takeFieldValue(x, y, grid);
            if (fieldValue == FV_PRIORITY_SIGN) {
                signs.push_back(Sign(Field(x, y), PRIORITY));
            }
            if (fieldValue == FV_NO_PRIORITY_SIGN) {
                signs.push_back(Sign(Field(x, y), NO_PRIORITY));
            }
        }
    }
    return signs;
}

WorldMapGenerator::WorldMapGenerator(WorldMapGridProvider *_worldMapGridProvider) {
    worldMapGridProvider = _worldMapGridProvider;
}
