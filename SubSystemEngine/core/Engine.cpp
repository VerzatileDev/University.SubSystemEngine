#include "Engine.h"

Engine::Engine()
{
    Initialize(); // Initialize SubSystem Components
    Update(); // Start Engine Core Loop of SubSystem Components
}

Engine::~Engine()
{}

void Engine::Initialize()
{
    inputSystem.Initialize();
    graphics.Initialize();
    physics.Initialize();

    Entity* player = new Entity("Player1");
    entityFactory.CreateSquare(player, 50.0f, sf::Color::Green, 100.0f, 100.0f);
    EntityManager::getInstance().AddEntity(player);
}

void Engine::Update()
{
    while (EventHandler::getInstance().IsRunning()) {
        inputSystem.Update();
        graphics.Update();
        physics.Update();

        EventHandler::getInstance().ProcessEvents();
    }
}