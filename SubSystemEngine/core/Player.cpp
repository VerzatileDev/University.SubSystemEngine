#include "Player.h"
#include <iostream>
const float PTM_RATIO = 300.0f;

Player::Player() : body(nullptr), physicsRef(physicsInstance) { // Initialize physicsRef with member variable
}

Player::Player(Physics& physics) : body(nullptr), physicsRef(physics) { std::cout << "Player constructor called" << std::endl; }

Player::~Player() {
    // Managed By Physics and Graphics destructors
}

void Player::initialize(b2World& world, const sf::Vector2f& position, float size) {
    b2BodyDef bodyDef;
    bodyDef.position.Set(position.x + 400, position.y + 300); // HardCoded Conversion
    bodyDef.type = b2_dynamicBody;
    body = world.CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(size / (2.0f ), size / (2.0f ));

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    body->CreateFixture(&fixtureDef);

    shape.setSize(sf::Vector2f(size, size));
    shape.setOrigin(size / 2.0f, size / 2.0f);
}

void Player::update() {
    if (body) {
        b2Vec2 position = body->GetPosition();
        shape.setPosition(position.x , position.y );
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::RectangleShape& Player::getShape() {
    return shape;
}