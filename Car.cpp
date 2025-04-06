//
// Created by User on 2025-03-11.
//

#include "Car.h"

#include <iostream>
#include <random>

#include "FieldHelper.h"
#include "GlobalConstants.h"
#include "Pedestrian.h"

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

Car::Car(
    int id,
    RoadGenerator *roadGenerator,
    CollisionDetector *_collisionDetector,
    Field field,
    Speed maxSpeed,
    int patience

): id(id),
   roadGenerator(roadGenerator),
   field(field),
   maxSpeed(maxSpeed),
   patience(patience),
   collisionDetector(_collisionDetector) {
    position = getCenterPoint(field);
    speed = maxSpeed;
    nextPoints = {};
    chooseNextRoad();
}

std::vector<Point> Car::getNextPoints() {
    return nextPoints;
}

void Car::checkCollision(std::vector<Car> cars,std::vector<Pedestrian> pedestrians) {
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

Field Car::getField() {
    return field;
}

Direction Car::getNextDirection() {
    return direction;
}

//TODO should be same as move and cars kept in some container
void Car::checkSpeedCollision(std::vector<Car> cars) {
    auto newSpeed = maxSpeed;
    for (auto car: cars) {
        for (auto upcomingPoint: nextPoints) {
            if (car.getPosition() == upcomingPoint) {
                //TODO add check if the car infront is really slower
                newSpeed = car.getSpeed();
            }
        }
    }
    speed = newSpeed;
}

bool Car::operator==(const Car &other) const {
    return this->id == other.id;
}

void Car::move() {
    Movable::move();
    auto newPositionField = mapToField(position);
    if (newPositionField.x != field.x || newPositionField.y != field.y) {
        field = newPositionField;
        chooseNextRoad();
    }
}

Point Car::getPosition() {
    return position;
}

Speed Car::getSpeed() {
    return speed;
}
