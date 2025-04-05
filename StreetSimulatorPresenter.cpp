#include "StreetSimulatorPresenter.h"

#include <vector>
#include <algorithm>
#include "Car.h"
#include "WorldMapManager.h"

std::vector<Car> getOtherCars(Car &car, std::vector<Car> &cars) {
    auto others = cars;
    std::remove(others.begin(), others.end(), car);
    others.pop_back();
    return others;
}

std::vector<Car> generateCars(RoadGenerator *generator, CollisionDetector *collisionDetector) {
    Car carBottom = Car(1, generator, collisionDetector, Field(13, 11), NORMAL, 101);
    Car carTop = Car(6, generator, collisionDetector, Field(12, 4), NORMAL, 101);
    Car carLeft = Car(2, generator, collisionDetector, Field(9, 9), NORMAL, 102);
    Car carRight = Car(3, generator, collisionDetector, Field(16, 8), NORMAL, 103);
    Car car1 = carLeft;
    Car car2 = carBottom;
    Car car3 = carRight;
    Car car4 = carTop;
    std::vector<Car> cars;
    cars.push_back(car1);
    cars.push_back(car2);
    cars.push_back(car3);
    //cars.push_back(car4);

    Car carNormal = Car(4, generator, collisionDetector, Field(21, 4), NORMAL, 60);
    Car carFast = Car(5, generator, collisionDetector, Field(21, 7), SLOW, 120);
    cars.push_back(carNormal);
    cars.push_back(carFast);
    return cars;
}

StreetSimulatorPresenter::StreetSimulatorPresenter(
    StreetSimulatorView *_view,
    RoadGenerator *_roadGenerator,
    LightsManager *_lightsManager,
    CollisionDetector *_collisionDetector,
    WorldMapManager *_worldMapManager
) {
    view = _view;
    roadGenerator = _roadGenerator;
    lightsManager = _lightsManager;
    collisionDetector = _collisionDetector;
    initPresenter(_worldMapManager);
}

void StreetSimulatorPresenter::initPresenter(WorldMapManager *worldMapManager) {
    auto mapRoads = roadGenerator->createRoads();
    cars = generateCars(roadGenerator, collisionDetector);
    signs = worldMapManager->createSigns();
    crossings = worldMapManager->createCrossings();
    view->loadRoads(mapRoads);
}

void StreetSimulatorPresenter::nextFrame() {
    lightsManager->setTime(timeCount);
    for (auto &car: cars) {
        //TODO create remove by value
        auto others = getOtherCars(car, cars);
        car.checkCollision(others);
        car.move();
    }
    view->clear();
    //TODO jk refactor to pass size
    view->drawBackground(GRID_COLUMNS, GRID_ROWS);
    view->drawRoads();
    view->drawCrossings(crossings);
    view->drawLights(lightsManager->getAllLights());
    view->drawSigns(signs);
    view->drawCars(cars);
    view->render();
    timeCount++;
}
