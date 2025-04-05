#ifndef STREETSIMULATORPRESENTER_H
#define STREETSIMULATORPRESENTER_H
#include "StreetSimulatorView.h"
#include "RoadGenerator.h"
#include "WorldMapGenerator.h"

class StreetSimulatorPresenter {
private:
    StreetSimulatorView *view;
    RoadGenerator *roadGenerator;
    LightsManager *lightsManager;
    CollisionDetector *collisionDetector;
    int timeCount = 0;
    std::vector<Car> cars;
    std::vector<Sign> signs;

    void initPresenter(
    WorldMapGenerator *worldMapGenerator
    );

public:
    StreetSimulatorPresenter(
        StreetSimulatorView *_view,
        RoadGenerator *_roadGenerator,
        LightsManager *_lightsManager,
        CollisionDetector *_collisionDetector,
        WorldMapGenerator *_worldMapGenerator
    );

    void nextFrame();
};


#endif //STREETSIMULATORPRESENTER_H
