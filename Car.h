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

class Car : public Movable {
public:
    Car(
        int id,
        RoadGenerator *roadGenerator,
        CollisionDetector *_collisionDetector,
        Field field,
        Speed maxSpeed,
        int patience
    );

    void move() override;

    Point getPosition() const;

    Field getField() const;

    Speed getSpeed() const;

    Direction getNextDirection() const;

    std::vector<Point> getNextPoints() const;

    void checkCollision(const std::vector<Car> &cars, const std::vector<Pedestrian> &pedestrians);

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
