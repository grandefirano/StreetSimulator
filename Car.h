//
// Created by User on 2025-03-11.
//

#ifndef CAR_H
#define CAR_H
#include "RoadGenerator.h"
#include "CollisionDetector.h"
#include "Speed.h"

class Car {
public:
    explicit Car(int id, RoadGenerator *roadGenerator, CollisionDetector *_collisionDetector, Field field, Speed maxSpeed,
                 int patience);

    void move();

    Point getPosition();

    Field getField();

    float getRotation();

    Speed getSpeed();

    Direction getNextDirection();

    std::vector<Point> getNextPoints();

    void checkCollision(std::vector<Car> cars);

    bool operator==(const Car &other) const;

private:
    int id;
    RoadGenerator *roadGenerator;
    CollisionDetector *collisionDetector;
    Point position;
    Field field;
    std::vector<Point> nextPoints;
    Direction direction;
    Speed maxSpeed;
    Speed speed;
    int patience;
    int waitingTime;

    void chooseNextRoad();

    void checkSpeedCollision(std::vector<Car> cars);

};


#endif //CAR_H
