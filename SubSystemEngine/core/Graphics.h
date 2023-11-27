#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"

class Graphics {
public:
    Graphics();
    ~Graphics();

    void initialize();
    void update();

    void render();
    void clear();
    void display();

    sf::RenderWindow& getWindow();

    void setView(const sf::View& view);
    void resetView();

    void handleResize();

    void addDrawable(sf::Drawable& drawable);
    void removeDrawable(sf::Drawable& drawable);

    void drawText(const sf::Text& text);
    void drawSprite(const sf::Sprite& sprite);
    void drawShape(const sf::Shape& shape);


    void enableDebugDrawing(bool enable);

private:
    sf::RenderWindow window;
    sf::View view;
    std::vector<sf::Drawable*> drawables;
    bool debugDrawingEnabled;
    sf::RectangleShape square;
};
