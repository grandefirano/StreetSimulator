//
// Created by User on 2025-03-09.
//

#include "RoadGenerator.h"

#include <cmath>
#include <array>
#include <iostream>
#include <string>

#include "FieldValue.h"
#include "Point.h"

#include "GlobalConstants.h"

//TODO jk maybe move to WorldMapManager
inline FieldValue takeFieldValue(const int x, const int y, const GridType &grid) {
    if (y < grid.size() && x < grid[y].size()) {
        return mapToFieldValue(grid[y][x]);
    }
    throw std::invalid_argument("Field is out of range");
}

std::vector<Point> generateQuarterCircle(double cx, double cy, double radius, double startAngle, double endAngle,
                                         int numSegments) {
    std::vector<Point> arcPoints;

    for (int i = 0; i <= numSegments; i++) {
        double theta = startAngle + ((endAngle - startAngle) * (i / (double) numSegments));
        double x = cx + radius * std::cos(theta);
        double y = cy + radius * std::sin(theta);
        arcPoints.push_back({x, y});
    }
    return arcPoints;
}

std::vector<Point> generateVerticalLine(double x, double startY, double endY, int numPoints) {
    std::vector<Point> linePoints;

    double step = (endY - startY) / (numPoints - 1);

    for (int i = 0; i < numPoints; i++) {
        double y = startY + i * step;
        linePoints.push_back({x, y});
    }
    return linePoints;
}

std::vector<Field> findIntersectionOuts(int x, int y, GridType grid) {
    auto value = takeFieldValue(x,y,grid);
    std::vector<Field> fields;
    Field exit1;
    Field exit2;
    Field exit3;
    if (value == FV_UP) {
        if (takeFieldValue(x, y - 3, grid) == FV_UP) {
            exit1 = Field(x, y - 3);
        }
        if (takeFieldValue(x - 2, y - 2, grid)==FV_LEFT) {
            exit2 = Field(x - 2, y - 2);
        }
        if (takeFieldValue(x + 1, y - 1, grid) == FV_RIGHT) {
            exit3 = Field(x + 1, y - 1);
        }
    } else if (value == FV_DOWN) {
        if (takeFieldValue(x, y + 3, grid) == FV_DOWN) {
            exit1 = Field(x, y + 3);
        }
        if (takeFieldValue(x + 2, y + 2, grid) == FV_RIGHT) {
            exit2 = Field(x + 2, y + 2);
        }
        if (takeFieldValue(x - 1, y + 1, grid) == FV_LEFT) {
            exit3 = Field(x - 1, y + 1);
        }
    } else if (value == FV_LEFT) {
        if (takeFieldValue(x - 3, y, grid) == FV_LEFT) {
            exit1 = Field(x - 3, y);
        }
        if (takeFieldValue(x - 2, y + 2, grid) == FV_DOWN) {
            exit2 = Field(x - 2, y + 2);
        }
        if (takeFieldValue(x - 1, y - 1, grid) == FV_UP) {
            exit3 = Field(x - 1, y - 1);
        }
    } else if (value == FV_RIGHT) {
        takeFieldValue(x + 1, y, grid);
        if (takeFieldValue(x + 3, y, grid) == FV_RIGHT) {
            exit1 = Field(x + 3, y);
        }
        if (takeFieldValue(x + 2, y - 2, grid) == FV_UP) {
            exit2 = Field(x + 2, y - 2);
        }
        if (takeFieldValue(x + 1, y + 1, grid) == FV_DOWN) {
            exit3 = Field(x + 1, y + 1);
        }
    }
    fields.push_back(exit1);
    fields.push_back(exit2);
    fields.push_back(exit3);
    return fields;
}

std::vector<Point> generateHorizontalLine(double y, double startX, double endX, int numPoints) {
    std::vector<Point> linePoints;

    double step = (endX - startX) / (numPoints - 1); // Calculate step size

    for (int i = 0; i < numPoints; i++) {
        double x = startX + i * step;
        linePoints.push_back({x, y});
    }
    return linePoints;
}

std::vector<Point> generateVerticalLineFieldDown(int x, int y) {
    auto x1 = (x) * M_SCALE;
    auto startY = (y - 0.5) * M_SCALE;
    auto endY = (y + 0.5) * M_SCALE;
    return generateVerticalLine(x1, startY, endY, M_POINTS);
}

std::vector<Point> generateVerticalLineFieldDownLong(int x, int y) {
    auto x1 = (x) * M_SCALE;
    auto startY = (y - 0.5) * M_SCALE;
    auto endY = (y + 1.5) * M_SCALE;
    return generateVerticalLine(x1, startY, endY, M_POINTS*2);
}

std::vector<Point> generateVerticalLineFieldUp(int x, int y) {
    auto x1 = (x) * M_SCALE;
    auto startY = (y + 0.5) * M_SCALE;
    auto endY = (y - 0.5) * M_SCALE;
    return generateVerticalLine(x1, startY, endY, M_POINTS);
}

std::vector<Point> generateVerticalLineFieldUpLong(int x, int y) {
    auto x1 = (x) * M_SCALE;
    auto startY = (y + 0.5) * M_SCALE;
    auto endY = (y - 1.5) * M_SCALE;
    return generateVerticalLine(x1, startY, endY, M_POINTS*2);
}

std::vector<Point> generateHorizontalLineFieldRight(int x, int y) {
    auto y1 = (y) * M_SCALE;
    auto startX = (x - 0.5) * M_SCALE;
    auto endX = (x + 0.5) * M_SCALE;
    return generateHorizontalLine(y1, startX, endX, M_POINTS);
}

std::vector<Point> generateHorizontalLineFieldRightLong(int x, int y) {
    auto y1 = (y) * M_SCALE;
    auto startX = (x - 0.5) * M_SCALE;
    auto endX = (x + 1.5) * M_SCALE;
    return generateHorizontalLine(y1, startX, endX, M_POINTS*2);
}

std::vector<Point> generateHorizontalLineFieldLeft(int x, int y) {
    auto y1 = (y) * M_SCALE;
    auto startX = (x + 0.5) * M_SCALE;
    auto endX = (x - 0.5) * M_SCALE;
    return generateHorizontalLine(y1, startX, endX, M_POINTS);
}

std::vector<Point> generateHorizontalLineFieldLeftLong(int x, int y) {
    auto y1 = (y) * M_SCALE;
    auto startX = (x + 0.5) * M_SCALE;
    auto endX = (x - 1.5) * M_SCALE;
    return generateHorizontalLine(y1, startX, endX, M_POINTS*2);
}

std::vector<RoadOption> RoadGenerator::generateIntersectionDown(int x, int y) {
    std::vector<RoadOption> points;
    std::vector<Point> quarter1 = generateQuarterCircle((x - 0.5) * M_SCALE, (y - 0.5) * M_SCALE, M_SCALE * 0.5, 0,
                                                        M_PI / 2,
                                                        M_POINTS);
    std::vector<Point> quarter2 = generateQuarterCircle((x + 1.5) * M_SCALE, (y - 0.5) * M_SCALE, M_SCALE * 1.5, M_PI,
                                                        M_PI / 2, M_POINTS*2);
    if (takeFieldValue(x + 2, y+1, grid)==FV_RIGHT) {
        points.push_back(RoadOption(quarter2, D_RIGHT));
    }
    if (takeFieldValue(x -1, y, grid)==FV_LEFT) {
        points.push_back(RoadOption(quarter1, D_LEFT));
    }
    if (takeFieldValue(x, y+2, grid)==FV_DOWN) {
        points.push_back(RoadOption(generateVerticalLineFieldDownLong(x, y), D_DOWN));
    }
    return points;
}

std::vector<RoadOption> RoadGenerator::generateIntersectionUp(int x, int y) {
    std::vector<RoadOption> points;
    std::vector<Point> quarter1 = generateQuarterCircle((x - 1.5) * M_SCALE, (y + 0.5) * M_SCALE, M_SCALE * 1.5,
                                                        2 * M_PI,
                                                        3 * M_PI / 2, M_POINTS*2);

    std::vector<Point> quarter2 = generateQuarterCircle((x + 0.5) * M_SCALE, (y + 0.5) * M_SCALE, M_SCALE * 0.5, M_PI,
                                                        3 * M_PI / 2, M_POINTS);
    if (takeFieldValue(x + 1, y, grid)==FV_RIGHT) {
        points.push_back(RoadOption(quarter2, D_RIGHT));
    }
    if (takeFieldValue(x - 2, y-1, grid)==FV_LEFT) {
        points.push_back(RoadOption(quarter1, D_LEFT));
    }
    if (takeFieldValue(x, y-2, grid)==FV_UP) {
        points.push_back(RoadOption(generateVerticalLineFieldUpLong(x, y), D_UP));
    }
    return points;
}

std::vector<RoadOption> RoadGenerator::generateIntersectionLeft(int x, int y) {
    std::vector<RoadOption> points;
    std::vector<Point> quarter1 = generateQuarterCircle((x + 0.5) * M_SCALE, (y - 0.5) * M_SCALE, M_SCALE * 0.5,
                                                        M_PI / 2,
                                                        M_PI, M_POINTS);
    std::vector<Point> quarter2 = generateQuarterCircle((x + 0.5) * M_SCALE, (y + 1.5) * M_SCALE, M_SCALE * 1.5,
                                                        3 * M_PI / 2,
                                                        M_PI, M_POINTS*2);
    if (takeFieldValue(x, y-1, grid)==FV_UP) {
        points.push_back(RoadOption(quarter1, D_UP));
    }
    if (takeFieldValue(x-1, y+2, grid)==FV_DOWN) {
        points.push_back(RoadOption(quarter2, D_DOWN));
    }
    if (takeFieldValue(x-2,y, grid)==FV_LEFT) {
        points.push_back(RoadOption(generateHorizontalLineFieldLeftLong(x, y), D_LEFT));
    }
    return points;
}

std::vector<RoadOption> RoadGenerator::generateIntersectionRight(int x, int y) {
    std::vector<RoadOption> points;
    std::vector<Point> quarter1 = generateQuarterCircle((x - 0.5) * M_SCALE, (y + 0.5) * M_SCALE, M_SCALE * 0.5,
                                                        3 * M_PI / 2,
                                                        2 * M_PI, M_POINTS);
    std::vector<Point> quarter2 = generateQuarterCircle((x - 0.5) * M_SCALE, (y - 1.5) * M_SCALE, M_SCALE * 1.5,
                                                        M_PI / 2, 0,
                                                        M_POINTS*2);
    if (takeFieldValue(x, y+1, grid)==FV_DOWN) {
        points.push_back(RoadOption(quarter1, D_DOWN));
    }
    if (takeFieldValue(x+1, y-2, grid)==FV_UP) {
        points.push_back(RoadOption(quarter2, D_UP));
    }
    if (takeFieldValue(x+2, y, grid)==FV_RIGHT) {
        points.push_back(RoadOption(generateHorizontalLineFieldRightLong(x, y), D_RIGHT));
    }
    return points;
}

std::vector<RoadOption> RoadGenerator::createRoadPossibilities(Field field, Direction direction) {
    char nextField;
    char fieldValue = takeFieldValue(field.x,field.y,grid);
    switch (fieldValue) {
        case FV_INTERSECTION:
            if (takeFieldValue(field.x,field.y+1,grid) == FV_DOWN && direction == D_DOWN) {
                return std::vector{RoadOption(generateVerticalLineFieldDown(field.x, field.y + 1), D_DOWN)};
            }
            if (takeFieldValue(field.x,field.y-1,grid) == FV_UP && direction == D_UP) {
                return std::vector{RoadOption(generateVerticalLineFieldUp(field.x, field.y - 1), D_UP)};
            }
            if (takeFieldValue(field.x+1,field.y,grid) == FV_RIGHT && direction == D_RIGHT) {
                return std::vector{RoadOption(generateHorizontalLineFieldRight(field.x + 1, field.y), D_RIGHT)};
            }
            if (takeFieldValue(field.x-1,field.y,grid) == FV_LEFT && direction == D_LEFT) {
                return std::vector{RoadOption(generateHorizontalLineFieldLeft(field.x - 1, field.y), D_LEFT)};
            }
            return std::vector<RoadOption>{};
            break;
        case FV_DOWN:
            nextField = takeFieldValue(field.x,field.y+1,grid);
            if (nextField == FV_DOWN) {
                return std::vector{RoadOption(generateVerticalLineFieldDown(field.x, field.y + 1), D_DOWN)};
            } else if (nextField == FV_INTERSECTION) {
                return std::vector{generateIntersectionDown(field.x, field.y + 1)};
            }
            break;
        case FV_UP:
            nextField = takeFieldValue(field.x,field.y-1,grid);
            if (nextField == FV_UP) {
                return std::vector{RoadOption(generateVerticalLineFieldUp(field.x, field.y - 1), D_UP)};
            } else if (nextField == FV_INTERSECTION) {
                return std::vector{generateIntersectionUp(field.x, field.y - 1)};
            }
            break;
        case FV_RIGHT:
            nextField = takeFieldValue(field.x+1,field.y,grid);
            if (nextField == FV_RIGHT) {
                return std::vector{RoadOption(generateHorizontalLineFieldRight(field.x + 1, field.y), D_RIGHT)};
            } else if (nextField == FV_INTERSECTION) {
                return std::vector{generateIntersectionRight(field.x + 1, field.y)};
            }
            break;
        case FV_LEFT:
            nextField = takeFieldValue(field.x-1,field.y,grid);
            if (nextField == FV_LEFT) {
                return std::vector{RoadOption(generateHorizontalLineFieldLeft(field.x - 1, field.y), D_LEFT)};
            } else if (nextField == FV_INTERSECTION) {
                return std::vector{generateIntersectionLeft(field.x - 1, field.y)};
            }
            break;
        default:
            return std::vector<RoadOption>{};
            break;
    }
}

//TODO refactor this
std::vector<RoadOption> RoadGenerator::createRoads() {
    std::vector<RoadOption> points;
    for (int y = 0; y < grid.size(); y++) {
        for (int x = 0; x < grid[y].size(); x++) {
            auto fieldValue = takeFieldValue(x,y,grid);
            if (fieldValue == FV_DOWN) {
                points.push_back(RoadOption(generateVerticalLineFieldDown(x, y), D_DOWN));
            } else if (fieldValue == FV_UP) {
                points.push_back(RoadOption(generateVerticalLineFieldUp(x, y), D_UP));
            } else if (fieldValue == FV_RIGHT) {
                points.push_back(RoadOption(generateHorizontalLineFieldRight(x, y), D_RIGHT));
            } else if (fieldValue == FV_LEFT) {
                points.push_back(RoadOption(generateHorizontalLineFieldLeft(x, y), D_LEFT));
            } else if (fieldValue == FV_INTERSECTION) {
                bool shouldHandleIntersection = (
                    takeFieldValue(x + 1, y, grid) == FV_INTERSECTION &&
                    takeFieldValue(x, y + 1, grid) == FV_INTERSECTION &&
                    takeFieldValue(x + 1, y + 1, grid) == FV_INTERSECTION
                );
                if (shouldHandleIntersection) {
                    if (takeFieldValue(x, y - 1, grid) == FV_DOWN) {
                        auto roads = generateIntersectionDown(x, y);
                        for (auto road: roads) {
                            points.push_back(road);
                        }
                        auto outsDown = findIntersectionOuts(x, y, grid);
                    }
                    if (takeFieldValue(x + 1, y + 2, grid) == FV_UP) {
                        auto roads = generateIntersectionUp(x + 1, y + 1);
                        for (auto road: roads) {
                            points.push_back(road);
                        }
                    }
                    if (takeFieldValue(x + 2, y, grid) == FV_LEFT) {
                        auto roads = generateIntersectionLeft(x + 1, y);
                        for (auto road: roads) {
                            points.push_back(road);
                        }
                    }

                    if (takeFieldValue(x - 1, y + 1, grid) == FV_RIGHT) {
                        auto roads = generateIntersectionRight(x, y + 1);
                        for (auto road: roads) {
                            points.push_back(road);
                        }
                    }
                }
            } else {
            }
        }
    }
    return points;
}

RoadGenerator::RoadGenerator(GridType grid) : grid(grid) {}
