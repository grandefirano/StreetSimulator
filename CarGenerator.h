#ifndef CARGENERATOR_H
#define CARGENERATOR_H
#include <vector>

#include "Car.h"

/**
* @class CarGenerator
* @brief Class responsible for generating list of cars.
*/
class CarGenerator {
public:
    /**
     * @brief Constructs a CarGenerator object.
     * @param _roadGenerator A road generator to be used by generated cars.
     * @param _collisionDetector A collision detector to be used by generated cars.
     */
    CarGenerator(RoadGenerator *_roadGenerator, CollisionDetector *_collisionDetector);

    /**
     * @brief Generate list of cars with various and valid positions on the world map grid.
     * @return List of generated cars.
     */
    std::vector<Car> generateCars() const;

private:
    RoadGenerator *roadGenerator;
    CollisionDetector *collisionDetector;
};


#endif //CARGENERATOR_H
