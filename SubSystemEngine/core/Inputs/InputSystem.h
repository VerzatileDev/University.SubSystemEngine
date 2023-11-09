#pragma once

// System libraries
#include <unordered_map>
#include <iostream>
#include <bitset>

// Included Libraries
#include <SFML/Window/Keyboard.hpp>

// Included Files
#include "../Event.h"
#include "../graphics/Window.h"
#include "../core/SubSystem.h"
#include "../EventHandler.h"

class InputSystem : public SubSystem {
public:
    void Initialize() override;
    void Update() override;
    void PollEvents();
    void Cleanup();

    // Keyboard Related Functions
    void UpdateKeyState(sf::Keyboard::Key keyCode, bool isPressed);
    bool IsKeyDown(sf::Keyboard::Key keyCode);

private:
    std::unordered_map<sf::Keyboard::Key, std::string> keyCodeMap;
    std::string ConvertSFMLKeyCodeToString(sf::Keyboard::Key keyCode);
    std::unordered_map<sf::Keyboard::Key, std::string> GenerateKeyCodeMap();
    std::bitset<sf::Keyboard::KeyCount> keyState;
};