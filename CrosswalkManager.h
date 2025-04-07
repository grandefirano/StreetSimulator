#ifndef CROSSWALKMANAGER_H
#define CROSSWALKMANAGER_H
#include <vector>

#include "Pedestrian.h"
#include "WorldMapManager.h"

/**
 * @class CrosswalkManager
 * @brief Manager of the crossings, responsible for generating pedestrians randomly next to the crossing, storing them and exposing the list of pedestrians for outside use.
 */
class CrosswalkManager {
public:
    /**
     * @brief Constructor of CrosswalkManager.
     * @param _worldMapManager World map manager to receive fields where pedestrians can be spawned and to read field values internally.
     */
    CrosswalkManager(WorldMapManager *_worldMapManager);

    /**
     * @brief Getter for the list of all pedestrians.
     * @return List of all the pedestrians on the map.
     */
    std::vector<Pedestrian> getPedestrians();

    /**
     * @brief Doing actions for the pedestrians for the next frame of time, which includes moving, generating and removing them.
     */
    void nextFrame();
private:
    int count;
    WorldMapManager *worldMapManager;
    std::vector<Field> spawns;
    std::vector<Pedestrian> pedestrians;
    void generatePedestrianRandomly();
    
};


#endif //CROSSWALKMANAGER_H
