
#include "CrosswalkManager.h"

#include <iostream>

#include "DirectionDelta.h"
#include "FieldHelper.h"
#include "GlobalConstants.h"
#include "WorldMapManager.h"

bool shouldGeneratePedestrian(int count) {
    return count % 103 == 0;
}

CrosswalkManager::CrosswalkManager(WorldMapManager *_worldMapManager) {
    worldMapManager = _worldMapManager;
    spawns = worldMapManager->createPedestrianSpawns();
}

void CrosswalkManager::nextFrame() {
    for (int i = 0; i < pedestrians.size(); i++) {
        if (pedestrians[i].getNextPoints().size()<3) {
            pedestrians.erase(pedestrians.begin()+i);
        }
        pedestrians[i].move();
    }
    if (shouldGeneratePedestrian(count)) {
        generatePedestrianRandomly();
        count = 0;
    }
    count++;
}

std::vector<Point> generateVerticalLineBetweenFields(Field startField, Field endField, int numPoints) {
    std::vector<Point> linePoints;
    auto startPoint = getCenterPoint(startField);
    auto endPoint = getCenterPoint(endField);
    double step = (endPoint.y - startPoint.y) / (numPoints - 1);

    for (int i = 0; i < numPoints; i++) {
        double y = startPoint.y + i * step;
        linePoints.push_back({startPoint.x, y});
    }
    return linePoints;
}

std::vector<Point> generateHorizontalLineBetweenFields(Field startField, Field endField, int numPoints) {
    std::vector<Point> linePoints;
    auto startPoint = getCenterPoint(startField);
    auto endPoint = getCenterPoint(endField);
    double step = (endPoint.x - startPoint.x) / (numPoints - 1);

    for (int i = 0; i < numPoints; i++) {
        double x = startPoint.x + i * step;
        linePoints.push_back({x, startPoint.y});
    }
    return linePoints;
}

void CrosswalkManager::generatePedestrianRandomly() {

    if (spawns.size() != 0) {
        srand((unsigned) time(nullptr));
        //choose random place of pedestrian being generated
        int chosenSpawn = rand() % spawns.size();
        //choose random speed of pedestrian
        int chosenSpeed = rand() % 2;
        Speed speed = FAST;
        if (chosenSpeed == 0) {
            speed = SLOW;
        }
        auto spawn = spawns[chosenSpawn];
        //create path for pedestrian
        auto pathFieldLength = 3;
        auto numberOfPoints = 12*BASE_NUMBER_OF_POINTS;
        std::vector<Point> allPoints;
        if (worldMapManager->takeFieldValue(Field(spawn.x,spawn.y+1))==FV_CROSSING) {
            allPoints = generateVerticalLineBetweenFields(spawn,Field(spawn.x,spawn.y+pathFieldLength),numberOfPoints);
        } else if (worldMapManager->takeFieldValue(Field(spawn.x,spawn.y-1))==FV_CROSSING) {
            allPoints = generateVerticalLineBetweenFields(spawn,Field(spawn.x,spawn.y-pathFieldLength),numberOfPoints);
        }else if (worldMapManager->takeFieldValue(Field(spawn.x+1,spawn.y))==FV_CROSSING) {
            allPoints = generateHorizontalLineBetweenFields(spawn,Field(spawn.x+pathFieldLength,spawn.y),numberOfPoints);
        }else if (worldMapManager->takeFieldValue(Field(spawn.x-1,spawn.y))==FV_CROSSING) {
            allPoints = generateHorizontalLineBetweenFields(spawn,Field(spawn.x-pathFieldLength,spawn.y),numberOfPoints);
        }

        pedestrians.push_back(Pedestrian(allPoints,speed,spawn));
    }
}

std::vector<Pedestrian> CrosswalkManager::getPedestrians() {
    return pedestrians;
}
