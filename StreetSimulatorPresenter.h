#ifndef STREETSIMULATORPRESENTER_H
#define STREETSIMULATORPRESENTER_H
#include "CarGenerator.h"
#include "CrosswalkManager.h"
#include "StreetSimulatorView.h"
#include "RoadGenerator.h"
#include "WorldMapManager.h"

/**
 * @class StreetSimulatorPresenter
 * @brief Core class of the MVP architecture of the application, responsible for managing the Models and View.
 */
class StreetSimulatorPresenter {
public:
    /**
     * @brief Constructor of StreetSimulatorPresenter
     * @param _view View of the application.
     * @param _roadGenerator Generator of roads.
     * @param _lightsManager Manager of all the traffic lights.
     * @param _worldMapManager World map manager.
     * @param _crosswalkManager Manager of all pedestrian crossings.
     * @param _carGenerator Generators of cars on the map.
     */
    StreetSimulatorPresenter(
        StreetSimulatorView *_view,
        RoadGenerator *_roadGenerator,
        LightsManager *_lightsManager,
        WorldMapManager *_worldMapManager,
        CrosswalkManager *_crosswalkManager,
        CarGenerator *_carGenerator
    );

    /**
     *
     * @brief Calls model and view actions for the next frame to  do calculations, update the state and redraw the view.
     */
    void nextFrame();
private:
    StreetSimulatorView *view;
    LightsManager *lightsManager;
    CrosswalkManager *crosswalkManager;
    int timeCount = 0;
    std::vector<Car> cars;
    std::vector<Sign> signs;
    std::vector<Crossing> crossings;

    void initPresenter(WorldMapManager *worldMapManager, RoadGenerator *roadGenerator, CarGenerator *carGenerator);
};


#endif //STREETSIMULATORPRESENTER_H
