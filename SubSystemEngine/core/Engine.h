#pragma once

// Included Libraries
#include <iostream>

// Included Files
#include "graphics/Graphics.h"
#include "Inputs/InputSystem.h"
#include "Eventhandler.h"

class Engine
{
public:
	Engine(); // Setup Engine for Use
	~Engine(); // Use Case when Out of Scope
	void Init(); // Initialize subsystems
	void Run(); // Engine Core Loop
	void CleanUP(); // Cleanup subsystems

private:
	InputSystem* inputSystem; // Pointer to InputSystem Object
	Graphics graphics;
	EventHandler eventHandler;
};