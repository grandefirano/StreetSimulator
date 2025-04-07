
#ifndef GRIDTYPE_H
#define GRIDTYPE_H

#include <string>

/**
 * @brief Number of rows of the world map grid
 */
static constexpr int GRID_ROWS = 23;
/**
 * @brief Number of columns of the world map grid
 */
static constexpr int GRID_COLUMNS = 25;
/**
 * @brief Grid type that is representation of the 2-dimensional array of the world map grid
 */
using GridType = std::array<std::array<std::string, GRID_COLUMNS>, GRID_ROWS>;

#endif //GRIDTYPE_H
