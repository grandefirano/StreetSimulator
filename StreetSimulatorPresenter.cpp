
#include "StreetSimulatorPresenter.h"

#include <vector>
#include <algorithm>
#include "Car.h"

std::vector<Car> getOtherCars(Car &car, std::vector<Car> &cars) {
    auto others = cars;
    std::remove(others.begin(),others.end(),car);
    others.pop_back();
    return others;
}

std::vector<Car> generateCars(RoadGenerator *generator) {
    Car carBottom = Car(1, generator, Field(8, 11), NORMAL, 101);
    Car carLeft = Car(2, generator, Field(4, 9), NORMAL, 102);
    Car carRight = Car(3, generator, Field(11, 8), NORMAL, 103);
    Car car1 = carLeft;
    Car car2 = carBottom;
    Car car3 = carRight;
    std::vector<Car> cars;
    cars.push_back(car1);
    cars.push_back(car2);
    cars.push_back(car3);

    Car carNormal = Car(4, generator, Field(16, 4), NORMAL, 60);
    Car carFast = Car(5, generator, Field(16, 7), SLOW, 120);
    cars.push_back(carNormal);
    cars.push_back(carFast);
    return cars;
}

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
    cars = generateCars(roadGenerator);

    view->loadRoads(mapRoads);
}

void StreetSimulatorPresenter::nextFrame() {

    for (auto &car: cars) {
        //TODO create remove by value
        auto others = getOtherCars(car, cars);
        car.checkCollision(others);
        car.move();
    }
    view->clear();
    //TODO jk refactor to pass size
    view->drawBackground(19,19);
    view->drawRoads();
    view->drawCars(cars);
    view->render();
    timeCount++;
}
