
#include "WorldMapGridProvider.h"

#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "Field.h"
#include "FieldValue.h"

GridType WorldMapGridProvider::provideGrid() {
    return grid;
}

WorldMapGridProvider::WorldMapGridProvider(const std::string &filename) {
    readGridFromFile(filename);
}

void WorldMapGridProvider::readGridFromFile(const std::string &filename) {
    GridType gridMap{};
    std::ifstream file("road1.txt");

    if (!file) {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    std::string line;
    int rowIdx = 0;

    while (std::getline(file, line) && rowIdx < GRID_ROWS) {
        std::stringstream ss(line);
        for (int colIdx = 0; colIdx < GRID_COLUMNS; ++colIdx) {
            ss >> gridMap[rowIdx][colIdx];
        }
        ++rowIdx;
    }
    grid = gridMap;
}
