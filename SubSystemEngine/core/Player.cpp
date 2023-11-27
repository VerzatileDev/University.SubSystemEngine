#include "Player.h"


Player& Player::getInstance()
{
    static Player instance;
    return instance;
}

Player::Player() : body(nullptr), physicsRef(physicsInstance)
{
}

Player::Player(Physics& physics) : body(nullptr), physicsRef(physics) { std::cout << "Player constructor called" << std::endl; }

Player::~Player() {
    // Managed By Physics and Graphics destructors
}

void Player::initialize(b2World& world, const sf::Vector2f& position, float size) {
    shape.setSize(sf::Vector2f(size, size));
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(25, 25);
    shape.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 100);
    
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(WINDOW_WIDTH / (2 * PIXELS_PER_METER), (WINDOW_HEIGHT - 100) / PIXELS_PER_METER);
    body = world.CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(25 / PIXELS_PER_METER, 25 / PIXELS_PER_METER);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.5f;
    fixtureDef.restitution = 0.0f;
    body->CreateFixture(&fixtureDef);

    body->SetUserData(this);
}

void Player::update() {
    if (body) {
        b2Vec2 position = body->GetPosition();
        shape.setPosition(position.x * PIXELS_PER_METER, position.y * PIXELS_PER_METER);
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::RectangleShape& Player::getShape() {
    return shape;
}

void Player::moveLeft()
{
    physicsInstance.applyForceToCenter(body, b2Vec2(-20.0f, 0.0f));
    std::cout << "Player moveLeft called" << std::endl;
}

void Player::moveRight()
{
    physicsInstance.applyForceToCenter(body, b2Vec2(20.0f, 0.0f));
}

void Player::jump()
{
    physicsInstance.applyLinearImpulse(body, b2Vec2(0.0f, -20.0f));
}

void Player::stopMoving()
{
    b2Vec2 vel = body->GetLinearVelocity();
    vel.x = 0.0f;
    body->SetLinearVelocity(vel);
}