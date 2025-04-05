
#ifndef GRIDTYPE_H
#define GRIDTYPE_H

static constexpr int GRID_ROWS = 23;
static constexpr int GRID_COLUMNS = 25;

using GridType = std::array<std::array<std::string, GRID_COLUMNS>, GRID_ROWS>;

#endif //GRIDTYPE_H
