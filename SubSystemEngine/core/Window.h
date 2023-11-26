#pragma once
#include <SFML/Graphics.hpp>

class Window
{
public:
    static Window& getInstance();

    void initialize();
    void clear();
    void display();
    sf::RenderWindow& getWindow();

    void setFullscreen(bool fullscreen);  // New function to toggle fullscreen
    void setWindowSize(sf::Vector2u size);  // New function to set window size

private:
    Window();
    ~Window();

    sf::RenderWindow window;
    sf::Vector2u windowSize;
};