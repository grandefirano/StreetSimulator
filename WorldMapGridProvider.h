//
// Created by User on 2025-03-07.
//

#ifndef WORLDMAPGRIDPROVIDER_H
#define WORLDMAPGRIDPROVIDER_H

#include <array>
#include <string>

#include "GridType.h"

class WorldMapGridProvider {
public:
    GridType provideGrid();
    WorldMapGridProvider(const std::string &filename);

private:
    GridType grid;
    void readGridFromFile(const std::string &filename);
};

#endif //WORLDMAPGRIDPROVIDER_H
