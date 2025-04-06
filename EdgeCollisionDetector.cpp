
#include "EdgeCollisionDetector.h"
#include<math.h>

bool EdgeCollisionDetector::checkEdgeCollision(const std::vector<Point> &points1, const std::vector<Point> &points2, double threshold) {
    for (const auto &point1: points1) {
        for (const auto &point2: points2) {
            if (distance(point1, point2) < threshold)
                return true;
        }
    }
    return false;
}

// Compute euclidean distance
double EdgeCollisionDetector::distance(const Point &point1, const Point &point2) {
    return std::hypot(point1.x - point2.x, point1.y - point2.y);
}

