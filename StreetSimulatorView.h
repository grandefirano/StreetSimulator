
#ifndef STREETSIMULATORVIEW_H
#define STREETSIMULATORVIEW_H
#include <vector>

#include "Car.h"
#include "Crossing.h"
#include "RoadGenerator.h"
#include "Light.h"
#include "Sign.h"

/**
 *@class StreetSimulatorView
 * @brief Base View Interface of the MVP architecture pattern to handle View presentation.
 */
class StreetSimulatorView {
public:
    /**
     * @brief Clears screen from all the rendered objects.
     */
    virtual void clear()=0;

    /**
     * @brief Draws the background of the map.
     * @param xFieldSize Horizontal size of the map.
     * @param yFieldSize Vertical size of the map.
     */
    virtual void drawBackground(int xFieldSize, int yFieldSize)=0;

    /**
     * @brief Load, parse and store all elements of the roads on the map.
     * @param mapRoads All the roads of the map.
     */
    virtual void loadRoads(const std::vector<RoadOption> &mapRoads)=0;

    /**
     * @brief Draw all the stored map roads.
     */
    virtual void drawRoads()=0;

    /**
     * @brief Draw all the cars on the map.
     * @param cars Cars to be drawn on the map.
     */
    virtual void drawCars(const std::vector<Car> &cars)=0;

    /**
     * @brief Draw all the lights on the map.
     * @param lights Lights to be drawn on the map.
     */
    virtual void drawLights(const std::vector<Light> &lights)=0;

    /**
     * @brief Draw all the signs on the map.
     * @param signs Signs to be drawn on the map.
     */
    virtual void drawSigns(const std::vector<Sign> &signs)=0;

    /**
     * @brief Draw all the crossings on the map.
     * @param crossings Crossings to be drawn on the map.
     */
    virtual void drawCrossings(const std::vector<Crossing> &crossings)=0;

    /**
     * @brief Draw all the pedestrians on the map.
     * @param pedestrians Pedestrians to be drawn on the map.
     */
    virtual void drawPedestrians(const std::vector<Pedestrian> &pedestrians)=0;

    /**
     * @brief Render the map with all the drawn elements.
     */
    virtual void render()=0;
};

#endif //STREETSIMULATORVIEW_H
