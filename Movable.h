#ifndef MOVABLE_H
#define MOVABLE_H
#include <vector>

#include "Point.h"
#include "Speed.h"

/**
 * @class Movable
 * @brief Represents movable objects that can be moved and presented on the map with calculated rotation.
 */
class Movable {
protected:
    /**
     * @brief Point position of the object.
     */
    Point position;
    /**
     * @brief List of next points on the movement trajectory.
     */
    std::vector<Point> nextPoints;
    /**
     * @brief Speed of an object.
     */
    Speed speed;

public:
    /**
     * @brief Moves object accordingly to its position, direction and speed.
     */
    virtual void move();

    /**
     * @brief Calculates rotation of the object.
     * @return Rotation of the object.
     */
    float getRotation();

    /**
     * @brief Getter of the upcoming Point positions of an object.
     * @return Next Point positions on the way of the object, that object is going to move through.
     */
    std::vector<Point> getNextPoints() const;

    /**
     * @brief Getter of the Point position.
     * @return Point position of a movable object.
     */
    Point getPosition() const;

};

#endif //MOVABLE_H
