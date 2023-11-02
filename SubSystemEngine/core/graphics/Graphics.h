#pragma once
#include <SFML/Graphics.hpp>

class Graphics
{
public:
    Graphics();
    ~Graphics();

    void Init(int screenWidth, int screenHeight, const std::string& windowTitle);
    void UpdateSubsystem();
    void CloseWindow();

    static Graphics& GetInstance();
    sf::RenderWindow& GetWindow();

private:
    sf::RenderWindow window;
    // Add any other graphics-related variables or objects here
};