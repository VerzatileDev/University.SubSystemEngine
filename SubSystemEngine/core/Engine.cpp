#include "Engine.h"

Engine::Engine()
{
	Init(); // Initialize Engine Components
	Run();  // Start Core Loop
}

Engine::~Engine()
{
    CleanUP();
}

void Engine::Init()
{
    graphics.Init(800, 600, "SubSystemEngine ID: 9032499");
    inputSystem = new InputSystem(graphics, eventHandler);
}

void Engine::Run()
{
    while (eventHandler.IsRunning())
    {
        
        inputSystem->PollEvents(); // Get Keyboard Input
        graphics.UpdateSubsystem();
        

        eventHandler.ProcessEvents(); // Handle Every Event in the Event Queue
    }
    CleanUP();
}

void Engine::WindowClosedCheck() 
{
    sf::Event event;
    while (graphics.GetWindow().pollEvent(event))
        (event.type == sf::Event::Closed) ? eventHandler.AddEvent(Event(Event::Closed)) : void();
}

void Engine::CleanUP()
{
    eventHandler.ClearEvents();
    if (inputSystem) {
        delete inputSystem;
        inputSystem = nullptr;
    }
}