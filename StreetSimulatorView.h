
#ifndef STREETSIMULATORVIEW_H
#define STREETSIMULATORVIEW_H
#include <vector>

#include "Car.h"
#include "Crossing.h"
#include "RoadGenerator.h"
#include "Light.h"
#include "Sign.h"

class StreetSimulatorView {
public:
    virtual void clear()=0;

    virtual void drawBackground(int xFieldSize, int yFieldSize)=0;

    virtual void loadRoads(const std::vector<RoadOption> &mapRoads)=0;

    virtual void drawRoads()=0;

    virtual void drawCars(const std::vector<Car> &cars)=0;

    virtual void drawLights(const std::vector<Light> &lights)=0;

    virtual void drawSigns(const std::vector<Sign> &signs)=0;

    virtual void drawCrossings(const std::vector<Crossing> &crossings)=0;
    virtual void drawPedestrians(const std::vector<Pedestrian> &pedestrians)=0;

    virtual void render()=0;
};

#endif //STREETSIMULATORVIEW_H
