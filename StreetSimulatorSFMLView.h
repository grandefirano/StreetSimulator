
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

class StreetSimulatorSFMLView : public StreetSimulatorView {
public:
    StreetSimulatorSFMLView(sf::RenderWindow *window);
    void clear() override;
    void loadRoads(const std::vector<RoadOption> &mapRoads) override;
    void drawRoads() override;
    void drawCars(const std::vector<Car> &cars) override;
    void drawBackground(int xFieldSize, int yFieldSize) override;
    void drawSigns(const std::vector<Sign> &signs) override;
    void drawLights(const std::vector<Light> &lights) override;
    void drawCrossings(const std::vector<Crossing> &crossings) override;
    void drawPedestrians(const std::vector<Pedestrian> &pedestrians) override;
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
