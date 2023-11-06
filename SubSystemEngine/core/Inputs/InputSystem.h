#pragma once
#include "nlohmann/json.hpp"
//using json = nlohmann::json;
#include <fstream>
// Included Libraries
#include <SFML/Window/Event.hpp>
#include <iostream>

// Included Files
#include "../core/Event.h"
#include "../core/EventHandler.h"
#include "../graphics/Graphics.h"

class InputSystem
{
public:
	InputSystem(Graphics& graphics, EventHandler& eventHandler);
	~InputSystem();
	void PollEvents();

private:
	EventHandler& eventHandler;
	Graphics& graphics; // Stores Local Reference to Graphics Object
};