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
    Window::getInstance().Initialize(800, 600, "Game Window");
    inputSystem.Initialize();
    graphics.Initialize();
    physics.Initialize();
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