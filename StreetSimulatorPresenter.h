#ifndef STREETSIMULATORPRESENTER_H
#define STREETSIMULATORPRESENTER_H
#include "StreetSimulatorView.h"
#include "RoadGenerator.h"

class StreetSimulatorPresenter {
private:
    StreetSimulatorView *view;
    RoadGenerator *roadGenerator;
    int timeCount = 0;
    std::vector<Car> cars;

    void initPresenter();

public:
    StreetSimulatorPresenter(
        StreetSimulatorView *_view,
        RoadGenerator *_roadGenerator
    );

    void nextFrame();
};


#endif //STREETSIMULATORPRESENTER_H
