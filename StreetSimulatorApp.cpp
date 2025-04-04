
#include <iostream>
#include <array>
#include <optional>
#include <valarray>
#include <SFML/Graphics.hpp>

#include "StreetSimulatorApp.h"
#include "StreetSimulatorPresenter.h"
#include "StreetSimulatorSFMLView.h"
#include "StreetSimulatorView.h"

StreetSimulatorApp::StreetSimulatorApp() {
    auto window = new sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "StreetSimulator");

    StreetSimulatorView *view = new StreetSimulatorSFMLView(window);
    StreetSimulatorPresenter *presenter = new StreetSimulatorPresenter(view);

    while (window->isOpen()) {
        while (const std::optional event = window->pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window->close();
            }
        }
        presenter->nextFrame();
    }
}
