
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
    auto *provider = new WorldMapGridProvider("road1.txt");
    auto grid = provider->provideGrid();
    auto *lightsManager = new LightsManager(grid);
    auto *roadGenerator = new RoadGenerator(grid);
    auto *collisionDetector = new CollisionDetector(provider,lightsManager);
    StreetSimulatorPresenter *presenter = new StreetSimulatorPresenter(view,roadGenerator,lightsManager,collisionDetector);

    while (window->isOpen()) {
        while (const std::optional event = window->pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window->close();
            }
        }
        presenter->nextFrame();
    }
}
