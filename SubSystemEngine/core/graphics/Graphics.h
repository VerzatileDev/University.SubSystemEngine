#pragma once

// Included Files
#include "../core/SubSystem.h"
#include "Window.h"

// Included Libraries
#include <SFML/Graphics.hpp>

class Graphics : public SubSystem
{
public:
    void Initialize() override; // Override Base, Initialize Graphics with window Reference
    void Update() override;

private:
    sf::RenderWindow window;
};