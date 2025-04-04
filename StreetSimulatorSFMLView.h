
#ifndef STREETSIMULATORSFMLVIEW_H
#define STREETSIMULATORSFMLVIEW_H
#include <vector>

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
    void loadRoads(std::vector<RoadOption> mapRoads) override;
    void drawRoads() override;
    void drawCars(std::vector<Car> cars) override;
    void drawBackground(int xFieldSize, int yFieldSize) override;
    void drawSigns(std::vector<Sign> signs) override;
    void drawLights(std::vector<Light> lights) override;
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
    void loadTextures();
};

#endif //STREETSIMULATORSFMLVIEW_H
