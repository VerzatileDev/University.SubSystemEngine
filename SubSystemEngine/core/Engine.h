#ifndef ENGINE_H
#define ENGINE_H

#include "graphics/Graphics.h"
#include "Inputs/KeyboardInput.h"
#include "Eventhandler.h"
#include <iostream>

class Engine
{
public:
	Engine(); // Initialize Engine Components
	~Engine(); // Cleanup

	void Init(); // Initialize subsystems
	void Run(); // Engine Core Loop
	bool running; // Engine State

private:
	Graphics graphics;
	EventHandler eventHandler;
	void HandleEvents();
};

#endif