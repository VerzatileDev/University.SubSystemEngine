#include "Engine.h"

// Inside Engine.cpp
Engine::Engine() : isRunning(true), player(physics.getWorld(), sf::Vector2f(400, 300), 50) {}

Engine::~Engine() {}

void Engine::initialize()
{
    Window::getInstance().initialize();
    physics.initialize();
    graphics.initialize();
}

void Engine::update() {
    while (Window::getInstance().getWindow().isOpen() && isRunning) {
        sf::Event event;
        while (Window::getInstance().getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                Window::getInstance().getWindow().close();
            }
        }

        physics.update();
        graphics.update(player);
    }
}

void Engine::stop() {
    isRunning = false;
}