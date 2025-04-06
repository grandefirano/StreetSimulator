#include "CarGenerator.h"

CarGenerator::CarGenerator(RoadGenerator *_roadGenerator, CollisionDetector *_collisionDetector) {
    roadGenerator = _roadGenerator;
    collisionDetector = _collisionDetector;
}

std::vector<Car> CarGenerator::generateCars() {
    Car carBottom = Car(1, roadGenerator, collisionDetector, Field(13, 11), NORMAL, 101);
    Car carTop = Car(6, roadGenerator, collisionDetector, Field(12, 4), NORMAL, 101);
    Car carLeft = Car(2, roadGenerator, collisionDetector, Field(9, 9), NORMAL, 102);
    Car carRight = Car(3, roadGenerator, collisionDetector, Field(16, 8), NORMAL, 103);
    Car carNormal = Car(4, roadGenerator, collisionDetector, Field(21, 4), NORMAL, 60);
    Car carFast = Car(5, roadGenerator, collisionDetector, Field(21, 7), SLOW, 120);
    std::vector<Car> cars;
    cars.push_back(carLeft);
    cars.push_back(carBottom);
    cars.push_back(carRight);
    cars.push_back(carNormal);
    cars.push_back(carFast);
    return cars;
}
