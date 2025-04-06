//
// Created by User on 2025-03-11.
//

#include "Car.h"

#include <iostream>
#include <random>

#include "FieldHelper.h"
#include "Pedestrian.h"

Car::Car(
    int id,
    RoadGenerator *roadGenerator,
    CollisionDetector *_collisionDetector,
    Field field,
    Speed maxSpeed,
    int patience
): id(id),
   roadGenerator(roadGenerator),
   collisionDetector(_collisionDetector),
   field(field),
   maxSpeed(maxSpeed),
   patience(patience) {
    position = getCenterPoint(field);
    speed = maxSpeed;
    nextPoints = {};
    chooseNextRoad();
}

void Car::chooseNextRoad() {
    auto possibilities = roadGenerator->createRoadPossibilities(field, direction);
    if (possibilities.size() != 0) {
        srand((unsigned) time(nullptr));
        int chosenPath = rand() % possibilities.size();
        auto possibility = possibilities[chosenPath];
        direction = possibility.direction;
        for (auto points: possibility.points) {
            nextPoints.push_back(points);
        }
    }
}

void Car::checkCollision(const std::vector<Car> &cars, const std::vector<Pedestrian> &pedestrians) {
    checkSpeedCollision(cars);
    if (collisionDetector->checkPedestrianCollision(*this,pedestrians)) {
        speed = STOP;
    }
    if (collisionDetector->checkIntersectionCollision(*this, cars)) {
        speed = STOP;
        waitingTime++;
        if (waitingTime > patience) {
            nextPoints.clear();
            chooseNextRoad();
            waitingTime = 0;
        }
    }
}

void Car::checkSpeedCollision(const std::vector<Car> &cars) {
    auto newSpeed = maxSpeed;
    for (auto car: cars) {
        for (auto upcomingPoint: nextPoints) {
            if (car.getPosition() == upcomingPoint) {
                if (car.getSpeed()<=this->speed) {
                    newSpeed = car.getSpeed();
                }
            }
        }
    }
    speed = newSpeed;
}

void Car::move() {
    Movable::move();
    auto newPositionField = mapToField(position);
    if (newPositionField.x != field.x || newPositionField.y != field.y) {
        field = newPositionField;
        chooseNextRoad();
    }
}

Field Car::getField() const {
    return field;
}

Direction Car::getNextDirection() const {
    return direction;
}

Point Car::getPosition() const {
    return position;
}

Speed Car::getSpeed() const {
    return speed;
}

std::vector<Point> Car::getNextPoints() const {
    return nextPoints;
}

bool Car::operator==(const Car &other) const {
    return this->id == other.id;
}
