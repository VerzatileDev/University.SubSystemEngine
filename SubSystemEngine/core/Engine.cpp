#include "Engine.h"

// Inside Engine.cpp
Engine::Engine() : player(physics.getWorld(), sf::Vector2f(400, 300), 50) {}

Engine::~Engine() {}

void Engine::initialize()
{
    Window::getInstance().initialize();
    input.Initialize();
    physics.initialize();
    graphics.initialize();
}

void Engine::update() {
    while (Window::getInstance().getWindow().isOpen() && EventHandler::getInstance().IsRunning()) {
        input.Update();
        EventHandler::getInstance().ProcessEvents();

        physics.update();
        graphics.update(player);
    }
}