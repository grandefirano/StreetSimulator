
#ifndef STREETSIMULATORSFMLVIEW_H
#define STREETSIMULATORSFMLVIEW_H
#include <vector>

#include "Pedestrian.h"
#include "StreetSimulatorView.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Texture.hpp"

namespace sf {
    class VertexArray;
}

/**
 * @class StreetSimulatorSFMLView
 * @brief Subclass of the base StreetSimulatorView class, which implements all its view presentation functionalities with use of SFML library.
 */
class StreetSimulatorSFMLView : public StreetSimulatorView {
public:
    /**
     * @brief Constructor sets window, its desired framerate and load textures.
     * @param window SFML Window instance to present the application layout.
     */
    StreetSimulatorSFMLView(sf::RenderWindow *window);

    /**
     * @brief Clears screen from all the rendered objects.
     */
    void clear() override;
    /**
    * @brief Load, parse and store all elements of the roads on the map.
    * @param mapRoads All the roads of the map.
    */
    void loadRoads(const std::vector<RoadOption> &mapRoads) override;
    /**
    * @brief Draw all the stored map roads.
    */
    void drawRoads() override;
    /**
    * @brief Draw all the cars on the map.
    * @param cars Cars to be drawn on the map.
    */
    void drawCars(const std::vector<Car> &cars) override;
    /**
    * @brief Draws the background of the map.
    * @param xFieldSize Horizontal size of the map.
    * @param yFieldSize Vertical size of the map.
    */
    void drawBackground(int xFieldSize, int yFieldSize) override;
   /**
    * @brief Draw all the signs on the map.
    * @param signs Signs to be drawn on the map.
    */
    void drawSigns(const std::vector<Sign> &signs) override;
    /**
    * @brief Draw all the lights on the map.
    * @param lights Lights to be drawn on the map.
    */
    void drawLights(const std::vector<Light> &lights) override;
   /**
   * @brief Draw all the crossings on the map.
   * @param crossings Crossings to be drawn on the map.
   */
    void drawCrossings(const std::vector<Crossing> &crossings) override;
   /**
   * @brief Draw all the pedestrians on the map.
   * @param pedestrians Pedestrians to be drawn on the map.
   */
    void drawPedestrians(const std::vector<Pedestrian> &pedestrians) override;
   /**
   * @brief Render the map with all the drawn elements.
   */
    void render() override;
private:
    sf::RenderWindow *window;
    std::vector<std::vector<sf::Vertex>> vertexRoads;
    std::vector<sf::VertexArray> thickRoads;
    sf::Texture redLightTexture;
    sf::Texture greenLightTexture;
    sf::Texture carTexture;
    sf::Texture asphaltTexture;
    sf::Texture grassTexture;
    sf::Texture noPrioritySignTexture;
    sf::Texture prioritySignTexture;
    sf::Texture crossingTexture;
    sf::Texture pedestrianTexture;
    void loadTextures();
};

#endif //STREETSIMULATORSFMLVIEW_H
