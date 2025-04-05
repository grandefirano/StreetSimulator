
#ifndef STREETSIMULATORVIEW_H
#define STREETSIMULATORVIEW_H
#include <vector>

#include "Car.h"
#include "RoadGenerator.h"
#include "Light.h"

class StreetSimulatorView {
public:
    virtual void clear()=0;

    virtual void drawBackground(int xFieldSize, int yFieldSize)=0;

    virtual void loadRoads(std::vector<RoadOption> mapRoads)=0;

    virtual void drawRoads()=0;

    virtual void drawCars(std::vector<Car> cars)=0;

    virtual void drawLights(std::vector<Light> lights)=0;

    virtual void render()=0;
};

#endif //STREETSIMULATORVIEW_H
