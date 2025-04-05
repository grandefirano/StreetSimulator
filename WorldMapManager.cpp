#include "WorldMapManager.h"

#include "FieldValue.h"

std::vector<Sign> WorldMapManager::createSigns() {
    //TODO caching grid
    auto grid = worldMapGridProvider->provideGrid();
    std::vector<Sign> signs;
    for (int y = 0; y < grid.size(); y++) {
        for (int x = 0; x < grid[y].size(); x++) {
            auto fieldValue = takeFieldValue(Field(x,y));
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

FieldValue WorldMapManager::takeFieldValue(Field field) {
    auto grid = worldMapGridProvider->provideGrid();
    if (field.y < grid.size() && field.x < grid[field.y].size()) {
        return mapToFieldValue(grid[field.y][field.x]);
    }
    throw std::invalid_argument("Field is out of range");
}

WorldMapManager::WorldMapManager(WorldMapGridProvider *_worldMapGridProvider) {
    worldMapGridProvider = _worldMapGridProvider;
}
