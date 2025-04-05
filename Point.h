//
// Created by User on 2025-03-10.
//

#ifndef POINT_H
#define POINT_H

#include <vector>
#include <bits/streambuf_iterator.h>


struct Point {
    double x, y;

    bool operator==(const Point &) const = default;
};

#endif //POINT_H
