
#include "Pedestrian.h"

#include "FieldHelper.h"

Pedestrian::Pedestrian(const std::vector<Point> &allPoints, const Speed &_speed, const Field &field) {
    nextPoints = allPoints;
    speed = _speed;
    position = getCenterPoint(field);
}

Field Pedestrian::getField() const {
    return mapToField(position);
}


