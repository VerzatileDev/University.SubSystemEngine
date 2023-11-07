#pragma once

// Included Libraries
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

// System Libraries
#include <unordered_map>
#include <iostream>
#include <chrono>
#include <bitset>

// Included Files
#include "../Event.h"
#include "../EventHandler.h"
#include "../graphics/Graphics.h"
#include "../Data/ExecutionTimeTracker.h"

class InputSystem
{
public:
	InputSystem(Graphics& graphics, EventHandler& eventHandler); // Setup InputSystem for Use (Instantiator)
	~InputSystem(); // Use Case when Out of Scope
	void Cleanup(); // Cleanup Initialized components

	// Keyboard Related Functions
	void PollEvents(); // Poll Events from SFML
	void UpdateKeyState(sf::Keyboard::Key keyCode, bool isPressed); // Update Key State
	bool IsKeyDown(sf::Keyboard::Key keyCode); // Check if Key is Down

private:
	// Local References to Objects
	EventHandler& eventHandler; // Stores Local Reference to includes Graphics Object that is initialized
	Graphics& graphics; // Stores Local Reference to includes Graphics Object that is initialized

	// Time Related Variables and data structures
	ExecutionTimeTracker timer; // Stores Local Reference to ExecutionTimeTracker Object
	bool showFrameRate; // To show FPS in Console

	// Keyboard Related Variables and data structures
	std::unordered_map<sf::Keyboard::Key, std::string> keyCodeMap; // Stores KeyCodes and Strings
	std::string ConvertSFMLKeyCodeToString(sf::Keyboard::Key keyCode); // Convert SFML KeyCodes to Strings
	std::unordered_map<sf::Keyboard::Key, std::string> GenerateKeyCodeMap(); // Write KeyCodes to map
	std::bitset<sf::Keyboard::KeyCount> keyState; // Stores KeyCodes and State
};