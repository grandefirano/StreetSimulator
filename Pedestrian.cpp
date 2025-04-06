
#include "Pedestrian.h"

#include "FieldHelper.h"

Pedestrian::Pedestrian(const std::vector<Point> &allPoints, const Speed &_speed, const Field &field) {
    nextPoints = allPoints;
    speed = _speed;
    position = getCenterPoint(field);
}

std::vector<Point> Pedestrian::getNextPoints() const {
    return nextPoints;
}

Field Pedestrian::getField() const {
    return mapToField(position);
}

Point Pedestrian::getPosition() const {
    return position;
}
