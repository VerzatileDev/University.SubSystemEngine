#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Entity.h"
#include "Window.h"

class Graphics {
public:
    Graphics();
    ~Graphics();

    void initialize();
    void update(Entity& player);
    sf::RenderWindow& getWindow();

    void handleResize();  // New function to handle window resizing

private:
    sf::RenderWindow window;
    std::vector<Entity> entities;
};