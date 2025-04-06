//
// Created by User on 2025-03-10.
//

#ifndef POINT_H
#define POINT_H

/**
 * @struct Point
 * @brief Point position of (x,y) coordinates on the world map grid, that divides field to the more precise positions accordingly to the scale.
 */
struct Point {
    /**
     * Precise coordinate on the horizontal axis.
     */
    double x;
    /**
    * Precise coordinate on the vertical axis.
    */
    double y;

    /**
     * @brief Comparator of points equality.
     * @return True if points are identical.
     */
    bool operator==(const Point &) const = default;
};

#endif //POINT_H
