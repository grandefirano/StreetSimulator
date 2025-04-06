#ifndef STREETSIMULATORPRESENTER_H
#define STREETSIMULATORPRESENTER_H
#include "CrosswalkManager.h"
#include "StreetSimulatorView.h"
#include "RoadGenerator.h"
#include "WorldMapManager.h"

class StreetSimulatorPresenter {
private:
    StreetSimulatorView *view;
    RoadGenerator *roadGenerator;
    LightsManager *lightsManager;
    CrosswalkManager *crosswalkManager;
    CollisionDetector *collisionDetector;
    int timeCount = 0;
    std::vector<Car> cars;
    std::vector<Sign> signs;
    std::vector<Crossing> crossings;

    void initPresenter(
    WorldMapManager *worldMapManager
    );

public:
    StreetSimulatorPresenter(
        StreetSimulatorView *_view,
        RoadGenerator *_roadGenerator,
        LightsManager *_lightsManager,
        CollisionDetector *_collisionDetector,
        WorldMapManager *_worldMapManager,
        CrosswalkManager *_crosswalkManager
    );

    void nextFrame();
};


#endif //STREETSIMULATORPRESENTER_H
