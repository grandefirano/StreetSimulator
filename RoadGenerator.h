//
// Created by User on 2025-03-09.
//

#ifndef ROADGENERATOR_H
#define ROADGENERATOR_H

#include <array>
#include <string>
#include <vector>

#include "Point.h"
#include "Field.h"
#include "GridType.h"
#include "RoadOption.h"
#include "WorldMapGridProvider.h"

class RoadGenerator {
public:
   RoadGenerator(WorldMapGridProvider *_worldMapGridProvider);
   std::vector<RoadOption> createRoads();
   std::vector<RoadOption> createRoadPossibilities(Field field,Direction direction);

private:
   GridType grid;
   std::vector<RoadOption> generateIntersectionDown(int x, int y);

   std::vector<RoadOption> generateIntersectionUp(int x, int y);

   std::vector<RoadOption> generateIntersectionLeft(int x, int y);

   std::vector<RoadOption> generateIntersectionRight(int x, int y);

};

#endif //ROADGENERATOR_H
