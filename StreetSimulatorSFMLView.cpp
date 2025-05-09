#include "StreetSimulatorSFMLView.h"

#include <cmath>
#include <iostream>

#include "GlobalConstants.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/VertexArray.hpp"

constexpr auto X_OFFSET = 500;
constexpr auto Y_OFFSET = 100;

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
    if (!noPrioritySignTexture.loadFromFile("textures/no_priority_sign.jpg")) {
        std::cerr << "Error loading no priority sign texture";
    }
    if (!prioritySignTexture.loadFromFile("textures/priority_sign.png")) {
        std::cerr << "Error loading priority sign texture";
    }
    if (!crossingTexture.loadFromFile("textures/crossing_img.png")) {
        std::cerr << "Error loading priority crossing texture";
    }
    if (!pedestrianTexture.loadFromFile("textures/pedestrian.png")) {
        std::cerr << "Error loading priority pedestrian texture";
    }
}

sf::VertexArray createThickLineStrip(const std::vector<sf::Vector2f> &points, const float thickness, const sf::Color color) {
    sf::VertexArray thickLine(sf::PrimitiveType::TriangleStrip);
    float halfThickness = thickness / 2.0f;

    for (int i = 0; i < points.size(); i++) {
        sf::Vector2f p1 = points[i];
        sf::Vector2f p2 = (i < points.size() - 1) ? points[i + 1] : points[i];
        sf::Vector2f direction = p2 - p1;
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        if (length == 0) continue;
        sf::Vector2f unitDir = direction / length;
        sf::Vector2f normal(-unitDir.y, unitDir.x);
        normal *= halfThickness;

        sf::Vector2f frontOffset = unitDir * halfThickness;
        sf::Vector2f backOffset = -unitDir * halfThickness;

        if (i == 0) {
            p1 += backOffset;
        }
        if (i == points.size() - 1) {
            p2 += frontOffset;
        }
        thickLine.append(sf::Vertex(p1 - normal, color));
        thickLine.append(sf::Vertex(p1 + normal, color));
    }

    return thickLine;
}

void StreetSimulatorSFMLView::loadRoads(const std::vector<RoadOption> &mapRoads) {
    for (int z = 0; z < mapRoads.size(); z++) {
        std::vector<sf::Vertex> road;
        std::vector<sf::Vector2f> vectorRoad;
        auto points = mapRoads[z].points;
        for (int i = 0; i < points.size(); ++i) {
            road.push_back(
                sf::Vertex(sf::Vector2f(points[i].x + X_OFFSET, points[i].y + Y_OFFSET), sf::Color(80, 80, 80)));
            vectorRoad.push_back(sf::Vector2f(points[i].x + X_OFFSET, points[i].y + Y_OFFSET));
        }
        vertexRoads.push_back(road);
        thickRoads.push_back(createThickLineStrip(vectorRoad, 20, sf::Color::Black));
    }
}

void StreetSimulatorSFMLView::drawRoads() {
    if (!thickRoads.empty()) {
        for (const auto &road: thickRoads) {
            window->draw(road);
        }
    }
    if (!vertexRoads.empty()) {
        for (const auto &road: vertexRoads) {
            window->draw(road.data(), road.size(), sf::PrimitiveType::LineStrip);
        }
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
            auto vectorBackground = sf::Vector2f((x - 0.5) * FIELD_SCALE + X_OFFSET, (y - 0.5) * FIELD_SCALE + Y_OFFSET);
            sf::Sprite sprite(grassTexture);
            sprite.setPosition(vectorBackground);
            window->draw(sprite);
        }
    }
}

void StreetSimulatorSFMLView::drawCars(const std::vector<Car> &cars) {
    for (auto car: cars) {
        auto carPosition = car.getPosition();
        auto vectorCar = sf::Vector2f(carPosition.x + X_OFFSET, carPosition.y + Y_OFFSET);
        sf::Sprite sprite(carTexture);
        sprite.setOrigin(sf::Vector2f(carTexture.getSize().x / 2, carTexture.getSize().y / 2));
        sprite.setRotation(sf::degrees(car.getRotation()));
        sprite.setPosition(vectorCar);
        window->draw(sprite);
    }
}

void StreetSimulatorSFMLView::render() {
    window->display();
}

void StreetSimulatorSFMLView::drawLights(const std::vector<Light> &lights) {
    for (const auto &light: lights) {
        sf::Vector2u textureSize = redLightTexture.getSize();
        auto vectorLight = sf::Vector2f(light.field.x * FIELD_SCALE + X_OFFSET - textureSize.x / 2,
                                        light.field.y * FIELD_SCALE + Y_OFFSET - textureSize.y / 2);
        sf::Sprite sprite(redLightTexture);
        sprite.setPosition(vectorLight);
        if (light.isGreen) {
            sprite.setTexture(greenLightTexture);
        } else {
            sprite.setTexture(redLightTexture);
        }
        window->draw(sprite);
    }
}

void StreetSimulatorSFMLView::drawSigns(const std::vector<Sign> &signs) {
    sf::Texture texture;
    for (const auto &sign: signs) {
        if (sign.type == PRIORITY) {
            texture = prioritySignTexture;
        }
        if (sign.type == NO_PRIORITY) {
            texture = noPrioritySignTexture;
        }
        sf::Vector2u textureSize = texture.getSize();
        auto vectorSign = sf::Vector2f(sign.field.x * FIELD_SCALE + X_OFFSET - textureSize.x / 2,
                                        sign.field.y * FIELD_SCALE + Y_OFFSET - textureSize.y / 2);
        sf::Sprite sprite(texture);
        sprite.setPosition(vectorSign);
        sprite.setTexture(texture);
        window->draw(sprite);
    }
}

void StreetSimulatorSFMLView::drawCrossings(const std::vector<Crossing> &crossings) {
    for (const auto &crossing : crossings) {
        sf::Vector2u textureSize = crossingTexture.getSize();
        auto vectorCrossing = sf::Vector2f(crossing.field.x * FIELD_SCALE + X_OFFSET,
                                        crossing.field.y * FIELD_SCALE + Y_OFFSET);
        sf::Sprite sprite(crossingTexture);
        sprite.setPosition(vectorCrossing);
        sprite.setOrigin(sf::Vector2f(textureSize.x /2 , textureSize.y /2));
        if (crossing.isHorizontal) {
            sprite.setRotation(sf::degrees(90));
        }
        sprite.setTexture(crossingTexture);
        window->draw(sprite);
    }
}

void StreetSimulatorSFMLView::drawPedestrians(const std::vector<Pedestrian> &pedestrians) {
    for (auto pedestrian: pedestrians) {
        sf::Vector2u textureSize = pedestrianTexture.getSize();
        auto vectorPedestrian = sf::Vector2f(pedestrian.getPosition().x -0.5 *FIELD_SCALE+ X_OFFSET,pedestrian.getPosition().y-0.5 *FIELD_SCALE+ Y_OFFSET);
        sf::Sprite sprite(pedestrianTexture);
        sprite.setPosition(vectorPedestrian);
        sprite.setOrigin(sf::Vector2f(textureSize.x /2 , textureSize.y /2));
        sprite.setRotation(sf::degrees(pedestrian.getRotation()));
        sprite.setTexture(pedestrianTexture);
        window->draw(sprite);
    }
}

