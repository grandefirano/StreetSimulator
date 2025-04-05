
#ifndef EDGECOLLISIONHELPER_H
#define EDGECOLLISIONHELPER_H
#include<math.h>
#include "Point.h"

// Compute euclidean distance
inline double distance(const Point &p1, const Point &p2) {
    return std::hypot(p1.x - p2.x, p1.y - p2.y);
}

inline bool checkEdgeCollision(const std::vector<Point> &curve1, const std::vector<Point> &curve2, double thickness) {
    double threshold = 2 * thickness;

    for (const auto &p1: curve1) {
        for (const auto &p2: curve2) {
            if (distance(p1, p2) < threshold)
                return true;
        }
    }
    return false;
}

#endif //EDGECOLLISIONHELPER_H
