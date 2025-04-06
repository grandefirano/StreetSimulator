
#ifndef EDGECOLLISIONDETECTOR_H
#define EDGECOLLISIONDETECTOR_H
#include <vector>

#include "Point.h"

/**
 * @class EdgeCollisionDetector
 * @brief Class that detects the collisions between objects based on the proximity between trajectories.
 */
class EdgeCollisionDetector {
public:
    /**
     *@brief Checks if two trajectories overlaps, have collision.
     * @param points1 Points of the first trajectory.
     * @param points2 Points of the second trajectory.
     * @param threshold Limit of distance, below which its considered as a collision.
     * @return True if there is an edge collision, false if there is not.
     */
    bool checkEdgeCollision(const std::vector<Point> &points1, const std::vector<Point> &points2, double threshold);
private:
    double distance(const Point &point1, const Point &point2);
};

#endif //EDGECOLLISIONDETECTOR_H
