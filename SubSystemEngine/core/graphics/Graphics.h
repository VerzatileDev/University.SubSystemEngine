#pragma once

// Included Libraries
#include <chrono> // Time

// Included Files
#include <SFML/Graphics.hpp>

class Graphics
{
public:
    Graphics();
    ~Graphics();

    void Init(int screenWidth, int screenHeight, const std::string& windowTitle);
    void UpdateSubsystem();
    void CloseWindow();
    sf::RenderWindow& GetWindow();
    float GetDeltaTime();

private:
    sf::RenderWindow window;
    std::chrono::high_resolution_clock::time_point timeThen;
    float deltaTime;
};