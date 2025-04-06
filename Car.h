//
// Created by User on 2025-03-11.
//

#ifndef CAR_H
#define CAR_H
#include "RoadGenerator.h"
#include "CollisionDetector.h"
#include "Movable.h"
#include "Pedestrian.h"
#include "Speed.h"

/**
 * @class Car
 * @brief Class that represents a car with its characteristics, internal state, position, and functionalities to move and check collisions.
 */
class Car : public Movable {
public:
    /**
     * @brief Default constructor of a Car.
     * @param id Unique identification number of a car.
     * @param roadGenerator Road generator to be used for generating possible roads to be taken by a car.
     * @param _collisionDetector Collision detector to predict the collision with other cars and pedestrians.
     * @param field Initial field location of a car.
     * @param maxSpeed Maximum speed that car can ride, when there is no need to limit the speed.
     * @param patience Number of rounds that driver tries to take the same road when there is unsolvable conflict on the intersection.
     */
    Car(
        int id,
        RoadGenerator *roadGenerator,
        CollisionDetector *_collisionDetector,
        Field field,
        Speed maxSpeed,
        int patience
    );

    /**
     * @brief Moves a car accordingly to its speed and, if needed, choose next road to take by a car.
     */
    void move() override;

    /**
     * @brief Getter of the Point position.
     * @return Point position of a car.
     */
    Point getPosition() const;
    /**
         * @brief Getter of the Field position.
         * @return Field position of a car.
         */
    Field getField() const;

    /**
     * @brief Getter of the current Speed.
     * @return Current speed of a car.
     */
    Speed getSpeed() const;

    /**
     * @brief Getter of the next Direction of a car.
     * @return Direction of a car on the end of its movement.
     */
    Direction getNextDirection() const;

    /**
     * @brief Getter of the upcoming Point positions of a car.
     * @return Next Point positions on the way of the car, that car is going to drive through.
     */
    std::vector<Point> getNextPoints() const;

    /**
     * @brief Checks intersection and speed collisions with other cars and collisions with pedestrians near the crossings.
     * @param cars List of other cars on the map, excluding the current one.
     * @param pedestrians List of all the pedestrians on the map.
     */
    void checkCollision(const std::vector<Car> &cars, const std::vector<Pedestrian> &pedestrians);

    /**
     * @brief Comparator of the cars to establish if they are the same car.
     * @param other Car to be compared with the current one.
     * @return True when the compared cars are equal, false if they are not.
     */
    bool operator==(const Car &other) const;

private:
    int id;
    RoadGenerator *roadGenerator;
    CollisionDetector *collisionDetector;
    Field field;
    Direction direction;
    Speed maxSpeed;
    int patience;
    int waitingTime;

    void chooseNextRoad();

    void checkSpeedCollision(const std::vector<Car> &cars);
};


#endif //CAR_H
