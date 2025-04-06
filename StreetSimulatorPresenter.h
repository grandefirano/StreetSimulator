#ifndef STREETSIMULATORPRESENTER_H
#define STREETSIMULATORPRESENTER_H
#include "CarGenerator.h"
#include "CrosswalkManager.h"
#include "StreetSimulatorView.h"
#include "RoadGenerator.h"
#include "WorldMapManager.h"

class StreetSimulatorPresenter {
public:
    StreetSimulatorPresenter(
        StreetSimulatorView *_view,
        RoadGenerator *_roadGenerator,
        LightsManager *_lightsManager,
        WorldMapManager *_worldMapManager,
        CrosswalkManager *_crosswalkManager,
        CarGenerator *_carGenerator
    );

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
