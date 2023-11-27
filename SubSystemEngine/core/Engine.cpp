#include "Engine.h"

Engine::Engine() {}

Engine::~Engine() 
{
}

void Engine::initialize() {
    // Initialize window, input, physics, and graphics
    Window::getInstance().initialize();
    input.Initialize();
    physics.initialize();
    graphics.initialize();


    
    player.initialize(physics.getWorld(), sf::Vector2f(0, 0), 50);
    ground.initialize(physics.getWorld(), sf::Vector2f(0, 0), 50);
    // Add the player's shape to the graphics system's drawables
    graphics.addDrawable(player.getShape());
    graphics.addDrawable(ground.getShape());
   
}

void Engine::update() {
    while (Window::getInstance().getWindow().isOpen() && EventHandler::getInstance().IsRunning()) {
        
        if (!Window::getInstance().getWindow().isOpen()) {
            std::cout << "Window is closed!" << std::endl;
            break; // Break out of the loop if the window is closed
        }
        input.Update();
        

        physics.update();
        player.update();
        //ground.update();
        graphics.update();
        EventHandler::getInstance().ProcessEvents();
    }
}
