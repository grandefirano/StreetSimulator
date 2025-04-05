
#include "Pedestrian.h"

#include "FieldHelper.h"

Pedestrian::Pedestrian(std::vector<Point> allPoints, Speed _speed, Field field) {
    nextPoints = allPoints;
    speed = _speed;
    position = getCenterPoint(field);
}

std::vector<Point> Pedestrian::getNextPoints() {
    return nextPoints;
}

Field Pedestrian::getField() {
    return mapToField(position);
}
