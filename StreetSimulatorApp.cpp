
#include <iostream>
#include <array>
#include <optional>
#include <valarray>
#include <SFML/Graphics.hpp>

#include "StreetSimulatorApp.h"
#include "StreetSimulatorPresenter.h"
#include "StreetSimulatorSFMLView.h"
#include "StreetSimulatorView.h"
#include "WorldMapGridProvider.h"

StreetSimulatorApp::StreetSimulatorApp() {
    auto window = new sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "StreetSimulator");

    StreetSimulatorView *view = new StreetSimulatorSFMLView(window);
    auto *worldGridProvider = new WorldMapGridProvider("road1.txt");
    auto grid = worldGridProvider->provideGrid();
    auto *lightsManager = new LightsManager(grid);
    auto *roadGenerator = new RoadGenerator(grid);
    auto *collisionDetector = new CollisionDetector(worldGridProvider,lightsManager);
    auto *worldMapGenerator = new WorldMapGenerator(worldGridProvider);
    StreetSimulatorPresenter *presenter = new StreetSimulatorPresenter(view,roadGenerator,lightsManager,collisionDetector,worldMapGenerator);

    while (window->isOpen()) {
        while (const std::optional event = window->pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window->close();
            }
        }
        presenter->nextFrame();
    }
}
