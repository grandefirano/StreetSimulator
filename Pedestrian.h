
#ifndef PEDESTRIAN_H
#define PEDESTRIAN_H
#include "Field.h"
#include "Movable.h"

/**
 * @class Pedestrian
 * @brief Represents Pedestrian, subtype of Movable, which walks on the crosswalk area.
 */
class Pedestrian : public Movable {
public:
    /**
     * @brief Constructor of Pedestrian.
     * @param allPoints All point of pedestrian's trajectory.
     * @param _speed Speed of the pedestrian.
     * @param field Generation, starting position of the pedestrian route.
     */
    Pedestrian(const std::vector<Point> &allPoints,const Speed &_speed, const Field &field);

    /**
     * @brief Getter of the field position.
     * @return Field position.
     */
    Field getField() const;
};

#endif //PEDESTRIAN_H
