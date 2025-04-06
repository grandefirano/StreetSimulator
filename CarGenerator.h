#ifndef CARGENERATOR_H
#define CARGENERATOR_H
#include <vector>

#include "Car.h"


class CarGenerator {
public:
    CarGenerator(RoadGenerator *_roadGenerator, CollisionDetector *_collisionDetector);

    std::vector<Car> generateCars();

private:
    RoadGenerator *roadGenerator;
    CollisionDetector *collisionDetector;
};


#endif //CARGENERATOR_H
