#include "Engine.h"

Engine::Engine() : running(true)
{
	Init(); // Initialize Engine Components
	Run();  // Start Core Loop
}

Engine::~Engine()
{
}

void Engine::Init()
{
    graphics.Init(800, 600, "SFML Window");
}

void Engine::Run()
{
    while (running)
    {
        HandleEvents(); // Set Event for Closing Window through EventHandler
        graphics.UpdateSubsystem();

        eventHandler.ProcessEvents(); // Handle Every Event in the Event Queue
    }
}

void Engine::HandleEvents() {
    sf::Event event;
    while (graphics.GetWindow().pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            Event closingEvent(Event::Closed);
            eventHandler.AddEvent(closingEvent);  // Add event to the queue
        }
    }
}