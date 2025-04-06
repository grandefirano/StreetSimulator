
#include "EdgeCollisionDetector.h"
#include<math.h>

bool EdgeCollisionDetector::checkEdgeCollision(const std::vector<Point> &curve1, const std::vector<Point> &curve2, double thickness) {
    double threshold = 2 * thickness;

    for (const auto &p1: curve1) {
        for (const auto &p2: curve2) {
            if (distance(p1, p2) < threshold)
                return true;
        }
    }
    return false;
}

// Compute euclidean distance
double EdgeCollisionDetector::distance(const Point &point1, const Point &point2) {
    return std::hypot(point1.x - point2.x, point1.y - point2.y);
}

