#include "Engine.h"
#include "Data/ExecutionTimeTracker.h"

Engine::Engine() {}

Engine::~Engine() 
{
    if (!playerContactListener)
    {
		delete playerContactListener;
		playerContactListener = nullptr;
	}
}

void Engine::initialize() {
    // Initialize window, input, physics, and graphics
    Window::getInstance().initialize();
    input.Initialize();
    physics.initialize();
    graphics.initialize();

    player.initialize(physics.getWorld(), sf::Vector2f(0, 0), 50);
    ground.initialize(physics.getWorld(), sf::Vector2f(0, 200), 50);
    // Add the player's shape to the graphics system's drawables

    playerContactListener = new ContactListener();
    EventHandler::getInstance().setContactListener(*playerContactListener);
    physics.getWorld().SetContactListener(playerContactListener);

    graphics.addDrawable(player.getShape());
    graphics.addDrawable(ground.getShape());
   
}

void Engine::update() {
    while (Window::getInstance().getWindow().isOpen() && EventHandler::getInstance().IsRunning()) 
    {
        timer.StartTimer();
        input.Update(); // System
        physics.update(); // System
        player.update(); // Entity
        ground.update(); // Entity
        graphics.update(); // System
        EventHandler::getInstance().ProcessEvents(); // System

        timer.StopTimer();
        timer.GetAndPrintFrameRate("Engine");
    }
}
