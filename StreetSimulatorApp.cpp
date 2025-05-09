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

const auto GRID_MAP_FILENAME = "road1.txt";
const auto APP_WINDOW_TITLE = "StreetSimulator";

StreetSimulatorApp::StreetSimulatorApp() {
    //injecting dependencies to classes manually, written in a manner that dependency injection can be easily applied in a future
    auto window = new sf::RenderWindow(sf::VideoMode({1920u, 1080u}), APP_WINDOW_TITLE);
    StreetSimulatorView *view = new StreetSimulatorSFMLView(window);

    auto *worldGridProvider = new WorldMapGridProvider(GRID_MAP_FILENAME);
    auto *lightsManager = new LightsManager(worldGridProvider);
    auto *roadGenerator = new RoadGenerator(worldGridProvider);
    auto *worldMapManager = new WorldMapManager(worldGridProvider);
    auto *edgeCollisionDetector = new EdgeCollisionDetector();
    auto *collisionDetector = new CollisionDetector(lightsManager, worldMapManager,edgeCollisionDetector);
    auto *crosswalkManager = new CrosswalkManager(worldMapManager);
    auto *carGenerator = new CarGenerator(roadGenerator, collisionDetector);
    StreetSimulatorPresenter *presenter = new StreetSimulatorPresenter(view, roadGenerator, lightsManager, worldMapManager, crosswalkManager, carGenerator);

    while (window->isOpen()) {
        while (const std::optional event = window->pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window->close();
            }
        }
        presenter->nextFrame();
    }
}
