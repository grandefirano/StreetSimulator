
#include "LightsManager.h"
#include "FieldValue.h"
#include "VectorHelper.h"

std::vector<Light> LightsManager::getAllLights() {
    std::vector<Field> lightFields = group1;
    lightFields.insert(lightFields.end(), group2.begin(), group2.end());
    std::vector<Light> lights;
    for (auto lightField : lightFields) {
        lights.push_back(Light(isGreenLight(lightField),lightField));
    }
    return lights;
}

void LightsManager::setTime(int _time) {
    time = _time;
}

void LightsManager::findIntersectionLights(const GridType &grid) {
    for (int y = 0; y < grid.size(); y++) {
        for (int x = 0; x < grid[y].size(); x++) {
            auto value = grid[y][x];
            if (mapToFieldValue(value) == FV_INTERSECTION) {
                if (
                    mapToFieldValue(grid[y + 1][x]) == FV_INTERSECTION &&
                    mapToFieldValue(grid[y][x + 1]) == FV_INTERSECTION &&
                    mapToFieldValue(grid[y + 1][x + 1]) == FV_INTERSECTION
                ) {
                    if (mapToFieldValue(grid[y + 2][x - 1]) == FV_LIGHT) {
                        group1.push_back(Field(x - 1, y + 2));
                    }
                    if (mapToFieldValue(grid[y - 1][x + 2]) == FV_LIGHT) {
                        group1.push_back(Field(x + 2, y - 1));
                    }
                    if (mapToFieldValue(grid[y - 1][x - 1]) == FV_LIGHT) {
                        group2.push_back(Field(x - 1, y - 1));
                    }
                    if (mapToFieldValue(grid[y + 2][x + 2]) == FV_LIGHT) {
                        group2.push_back(Field(x + 2, y + 2));
                    }
                }
            }
        }
    }
}

bool LightsManager::isGreenLight(const Field &field) {
    auto count = time/20 % 12;
    if (contains(group1,field)) {
        return (count>=6 && count<=9);
    }
    if (contains(group2,field)) {
        return count<=3;
    }
    return false;
}

LightsManager::LightsManager(WorldMapGridProvider *_worldMapGridProvider) {
    findIntersectionLights(_worldMapGridProvider->provideGrid());
}
