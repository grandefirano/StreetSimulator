//
// Created by User on 2025-03-09.
//

#ifndef ROADGENERATOR_H
#define ROADGENERATOR_H

#include <vector>

#include "Field.h"
#include "GridType.h"
#include "RoadOption.h"
#include "WorldMapGridProvider.h"

/**
 * @class RoadGenerator
 * @brief Responsible for creating all roads of world map and road trajectories for cars.
 */
class RoadGenerator {
public:
   /**
    * @brief Constructor of RoadGenerator.
    * @param _worldMapGridProvider WorldMapGridProvider for providing the grid.
    */
   RoadGenerator(WorldMapGridProvider *_worldMapGridProvider);

   /**
    * @brief Creates all world map roads.
    * @return List of all world map road options.
    */
   std::vector<RoadOption> createRoads();

   /**
    * @brief Creates all road possibilities that car can take at its position on the roads map.
    * @param field Current field position.
    * @param direction Current direction.
    * @return List of road options that car can choose to go.
    */
   std::vector<RoadOption> createRoadPossibilities(const Field &field, const Direction &direction);

private:
   GridType grid;
   std::vector<RoadOption> generateIntersectionDown(int x, int y);

   std::vector<RoadOption> generateIntersectionUp(int x, int y);

   std::vector<RoadOption> generateIntersectionLeft(int x, int y);

   std::vector<RoadOption> generateIntersectionRight(int x, int y);

};

#endif //ROADGENERATOR_H
