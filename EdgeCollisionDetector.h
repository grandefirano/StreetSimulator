
#ifndef EDGECOLLISIONDETECTOR_H
#define EDGECOLLISIONDETECTOR_H
#include "Point.h"

class EdgeCollisionDetector {
public:
    bool checkEdgeCollision(const std::vector<Point> &curve1, const std::vector<Point> &curve2, double thickness);
private:
    double distance(const Point &point1, const Point &point2);
};

#endif //EDGECOLLISIONDETECTOR_H
