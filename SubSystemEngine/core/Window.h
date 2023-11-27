#pragma once
#include <SFML/Graphics.hpp>

class Window {
public:
    Window();
    ~Window();
    static Window& getInstance();

    void initialize();
    void clear();
    void display();
    sf::RenderWindow& getWindow();

    void setFullscreen(bool fullscreen);
    void setWindowSize(sf::Vector2u size);

private:
    sf::RenderWindow window;
    sf::Vector2u windowSize;
};