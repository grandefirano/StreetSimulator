
#ifndef FIELD_H
#define FIELD_H

/**
 * @class Field
 * @brief Represents the field (x,y) coordinates position on the world map grid.
 */
struct Field {
    /**
     * @brief Horizontal axis coordinate.
     */
    int x;
    /**
    * @brief Vertical axis coordinate.
    */
    int y;

    /**
     * @brief Comparator that checks equality between fields.
     * @param other Compared field.
     * @return True if fields are equal to each other, false if they are not.
     */
    bool operator==(const Field &other) const {
        return (x==other.x)&&(y==other.y);
    };
};

#endif //FIELD_H
