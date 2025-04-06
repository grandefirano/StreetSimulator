
#include <iostream>
#include <array>
#include <optional>
#include <valarray>
#include <SFML/Graphics.hpp>

#include "StreetSimulatorApp.h"

#include "CrosswalkManager.h"
#include "LightsIntersection.h"
#include "PriorityIntersection.h"
#include "StreetSimulatorPresenter.h"
#include "StreetSimulatorSFMLView.h"
#include "StreetSimulatorView.h"
#include "UncontrolledIntersection.h"
#include "WorldMapGridProvider.h"

StreetSimulatorApp::StreetSimulatorApp() {
    auto window = new sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "StreetSimulator");

    StreetSimulatorView *view = new StreetSimulatorSFMLView(window);
    auto *worldGridProvider = new WorldMapGridProvider("road1.txt");
    auto grid = worldGridProvider->provideGrid();
    auto *lightsManager = new LightsManager(grid);
    auto *roadGenerator = new RoadGenerator(grid);
    auto *worldMapManager = new WorldMapManager(worldGridProvider);
    auto *collisionDetector = new CollisionDetector(lightsManager,worldMapManager);
    auto *crosswalkManager = new CrosswalkManager(worldMapManager);
    StreetSimulatorPresenter *presenter = new StreetSimulatorPresenter(view,roadGenerator,lightsManager,collisionDetector,worldMapManager,crosswalkManager);

    while (window->isOpen()) {
        while (const std::optional event = window->pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window->close();
            }
        }
        presenter->nextFrame();
    }
}
