
#ifndef WORLDMAPMANAGER_H
#define WORLDMAPMANAGER_H
#include <vector>

#include "Crossing.h"
#include "FieldValue.h"
#include "Sign.h"
#include "WorldMapGridProvider.h"

/**
 * @class WorldMapManager
 * @brief Provides world map elements and value of the specified field.
 */
class WorldMapManager {
public:
    /**
     * @brief Constructor of WorldMapManager.
     * @param _worldMapGridProvider WorldMapGridProvider for providing map.
     */
    WorldMapManager(WorldMapGridProvider *_worldMapGridProvider);

    /**
     * @brief Provides all the signs of the map.
     * @return All signs of the world map.
     */
    std::vector<Sign> provideSigns();

    /**
     * @brief Provides all the crossing elements of the map.
     * @return All the crossing elements of the map.
     */
    std::vector<Crossing> provideCrossings();
    /**
    * @brief Provides all the pedestrian spawn elements of the map.
    * @return All the pedestrian spawn elements of the map.
    */
    std::vector<Field> providePedestrianSpawns();

    /**
     * @brief Takes field value from the grid for given field.
     * @param field Field which value is read.
     * @return Value of the given field.
     */
    FieldValue takeFieldValue(const Field &field);
private:
    WorldMapGridProvider *worldMapGridProvider;
};


#endif //WORLDMAPMANAGER_H
