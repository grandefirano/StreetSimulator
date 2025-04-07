#include "StreetSimulatorPresenter.h"

#include <vector>
#include "Car.h"
#include "CarGenerator.h"
#include "CrosswalkManager.h"
#include "VectorHelper.h"
#include "WorldMapManager.h"


StreetSimulatorPresenter::StreetSimulatorPresenter(
    StreetSimulatorView *_view,
    RoadGenerator *_roadGenerator,
    LightsManager *_lightsManager,
    WorldMapManager *_worldMapManager,
    CrosswalkManager *_crosswalkManager,
    CarGenerator *_carGenerator
) {
    view = _view;
    lightsManager = _lightsManager;
    crosswalkManager = _crosswalkManager;
    initPresenter(_worldMapManager, _roadGenerator, _carGenerator);
}

void StreetSimulatorPresenter::initPresenter(
    WorldMapManager *worldMapManager,
    RoadGenerator *roadGenerator,
    CarGenerator *carGenerator
    ) {
    cars = carGenerator->generateCars();
    signs = worldMapManager->provideSigns();
    crossings = worldMapManager->provideCrossings();
    auto mapRoads = roadGenerator->createRoads();
    view->loadRoads(mapRoads);
}

void StreetSimulatorPresenter::nextFrame() {
    lightsManager->setTime(timeCount);
    crosswalkManager->nextFrame();
    auto pedestrians = crosswalkManager->getPedestrians();
    for (auto &car: cars) {
        auto others = withoutElement<Car>(car, cars);
        car.checkCollision(others, pedestrians);
        car.move();
    }
    view->clear();
    view->drawBackground(GRID_COLUMNS, GRID_ROWS);
    view->drawRoads();
    view->drawCrossings(crossings);
    view->drawLights(lightsManager->getAllLights());
    view->drawSigns(signs);
    view->drawPedestrians(pedestrians);
    view->drawCars(cars);
    view->render();
    timeCount++;
}
