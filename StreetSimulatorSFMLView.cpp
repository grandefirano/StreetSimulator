#include "StreetSimulatorSFMLView.h"

#include <cmath>
#include <iostream>

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/VertexArray.hpp"

const auto X_START = 500;
const auto Y_START = 100;
//TODO only one scale
const auto SCALE = 31;

void StreetSimulatorSFMLView::loadTextures() {
    if (!redLightTexture.loadFromFile("textures/ic-red-light.png")) {
        std::cerr << "Error loading red light texture";
    }
    if (!greenLightTexture.loadFromFile("textures/ic-green-light.png")) {
        std::cerr << "Error loading green light texture";
    }
    if (!carTexture.loadFromFile("textures/car_top_1.png")) {
        std::cerr << "Error loading car 1 texture";
    }
    if (!grassTexture.loadFromFile("textures/grass.jpg")) {
        std::cerr << "Error loading grass texture";
    }
}

StreetSimulatorSFMLView::StreetSimulatorSFMLView(sf::RenderWindow *_window) {
    window = _window;
    window->setFramerateLimit(60);
    loadTextures();
}

void StreetSimulatorSFMLView::clear() {
    window->clear();
}

void StreetSimulatorSFMLView::drawBackground(const int xFieldSize, const int yFieldSize) {
    for (int y = 0; y < yFieldSize; y++) {
        for (int x = 0; x < xFieldSize; x++) {
            auto vectorBackground = sf::Vector2f((x - 0.5) * SCALE + X_START, (y - 0.5) * SCALE + Y_START);
            sf::Sprite sprite(grassTexture);
            sprite.setPosition(vectorBackground);
            window->draw(sprite);
        }
    }
}

void StreetSimulatorSFMLView::render() {
    window->display();
}
