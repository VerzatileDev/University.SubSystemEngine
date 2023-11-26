#include "Engine.h"

// Inside Engine.cpp
Engine::Engine() {}

Engine::~Engine() {}

void Engine::initialize()
{
    Window::getInstance().initialize();
    input.Initialize();
    physics.initialize();
    graphics.initialize();

    // Create and add entities to the EntityManager
    Entity* player = new Entity(physics.getWorld(), sf::Vector2f(400, 300), 50);
    EntityManager::getInstance().addEntity(player);
}

void Engine::update() {
    while (Window::getInstance().getWindow().isOpen() && EventHandler::getInstance().IsRunning()) {
        input.Update();
        EventHandler::getInstance().ProcessEvents();

        physics.update();
        graphics.update();
    }
}