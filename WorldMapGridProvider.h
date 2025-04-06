//
// Created by User on 2025-03-07.
//

#ifndef WORLDMAPGRIDPROVIDER_H
#define WORLDMAPGRIDPROVIDER_H

#include <array>
#include <string>

#include "GridType.h"

/**
 * @class WorldMapGridProvider
 * @brief Provides a grid of the world map from file.
 */
class WorldMapGridProvider {
public:
    /**
     * @brief Constructor of WorldMapGridProvider.
     * @param filename Name of the file that stores in a text format structure of all the world map grid with its field types
     */
    WorldMapGridProvider(const std::string &filename);

    /**
     * @brief Provides full grid of the world map.
     * @return World map grid two-dimensional array.
     */
    GridType provideGrid();

private:
    GridType grid;
    void readGridFromFile(const std::string &filename);
};

#endif //WORLDMAPGRIDPROVIDER_H
