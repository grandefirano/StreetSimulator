//
// Created by User on 2025-03-11.
//

#include "Car.h"

#include <iostream>
#include <random>

#include "FieldHelper.h"
#include "GlobalConstants.h"

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
   speed(maxSpeed),
patience(patience),
collisionDetector(_collisionDetector) {
    position = getCenterPoint(field);
    nextPoints = {};
    chooseNextRoad();
}

std::vector<Point> Car::getNextPoints() {
    return nextPoints;
}

void Car::checkCollision(std::vector<Car> cars) {
    checkSpeedCollision(cars);
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


float Car::getRotation() {
    auto currentPoint = nextPoints.at(0);
    auto nextPoint = nextPoints.at(2);
    return atan2(nextPoint.y - currentPoint.y, nextPoint.x - currentPoint.x) * 180 / PI;
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
    if (speed == STOP) {
    } else if (speed == SLOW) {
        position = nextPoints.front();
        nextPoints.erase(nextPoints.begin());
    } else if (speed == NORMAL) {
        position = nextPoints.front();
        nextPoints.erase(nextPoints.begin(), nextPoints.begin() + 2);
    } else if (speed == FAST) {
        position = nextPoints.front();
        nextPoints.erase(nextPoints.begin(), nextPoints.begin() + 3);
    }
    if (nextPoints.size() == 0) {
        std::cout << "No upcoming points for the car" << std::endl;
    }
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
