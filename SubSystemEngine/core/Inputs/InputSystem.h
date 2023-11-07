#pragma once

// Included Libraries
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

// System Libraries
#include <unordered_map>
#include <iostream>
#include <chrono>

// Included Files
#include "../core/Event.h"
#include "../core/EventHandler.h"
#include "../graphics/Graphics.h"

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
	// References to other subsystems Stores locally from Instantiator
	EventHandler& eventHandler; // Stores Local Reference to EventHandler Object
	Graphics& graphics; // Stores Local Reference to Graphics Object

	// Keyboard Related Variables
	std::unordered_map<sf::Keyboard::Key, std::string> keyCodeMap; // Stores KeyCodes and Strings
	std::string ConvertSFMLKeyCodeToString(sf::Keyboard::Key keyCode); // Convert SFML KeyCodes to Strings
	std::unordered_map<sf::Keyboard::Key, std::string> GenerateKeyCodeMap(); // Write KeyCodes to map
	std::unordered_map<sf::Keyboard::Key, bool> keyState; // Stores KeyCodes and State
};