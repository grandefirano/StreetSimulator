
#ifndef LIGHTSMANAGER_H
#define LIGHTSMANAGER_H

#include "Light.h"
#include "RoadGenerator.h"

/**
 * @class LightsManager
 * @brief Takes care of changing lights colors based on timer, manages and exposes all the traffic lights on the world map.
 */
class LightsManager {
public:
    /**
     * @brief Constructor of LightsManager.
     * @param _worldMapGridProvider Provider of a world map grid.
     */
    LightsManager(WorldMapGridProvider *_worldMapGridProvider);

    /**
     * @brief Checks if the light of the traffic light at given field position is green.
     * @param field Position of the traffic light.
     * @return True if it is green, false if it is not.
     */
    bool isGreenLight(const Field &field);

    /**
     * @brief Getter of all the lights on the world map.
     * @return List of all lights.
     */
    std::vector<Light> getAllLights();

    /**
     * @brief Setter of a world time, based on which color of light will be predicted.
     * @param time Current world time.
     */
    void setTime(int time);
private:
    void findIntersectionLights(const GridType &grid);
    std::vector<Field> group1;
    std::vector<Field> group2;
    int time;
};



#endif //LIGHTSMANAGER_H
