
#include "StreetSimulatorPresenter.h"

#include <vector>
#include <algorithm>

StreetSimulatorPresenter::StreetSimulatorPresenter(
    StreetSimulatorView *_view,
    RoadGenerator *_roadGenerator
) {
    view = _view;
    roadGenerator = _roadGenerator;
    initPresenter();
}

void StreetSimulatorPresenter::initPresenter() {
    auto mapRoads = roadGenerator->createRoads();

    view->loadRoads(mapRoads);
}

void StreetSimulatorPresenter::nextFrame() {

    view->clear();
    //TODO jk refactor to pass size
    view->drawBackground(19,19);
    view->drawRoads();
    view->render();
    timeCount++;
}
