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
    graphics.Init(800, 600, "SubSystemEngine ID: 9032499"); // Initialize Window
    inputSystem = new InputSystem(graphics, eventHandler); // Initialize InputSystem and Pass References to current Graphics and EventHandler to it for use in PollEvents() and AddEvent().
}

void Engine::Run()
{
    while (eventHandler.IsRunning())
    {
        
        inputSystem->PollEvents(); // Get Keyboard Input and assing Events to the Event Queue
        graphics.UpdateSubsystem();
        

        eventHandler.ProcessEvents(); // Handle Every Event in the Event Queue
    }
    CleanUP();
}

void Engine::CleanUP()
{
    eventHandler.ClearEvents();
    if (inputSystem) {
        delete inputSystem;
        inputSystem = nullptr; // Set to nullptr to avoid dangling pointer
    }
}