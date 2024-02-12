#pragma once

#include "Graphics/Graphics.h"
#include "Physics/Physics.h"
#include "Handling/Event.h"
#include "Handling/EventHandler.h"
#include "Entities/Player.h"
#include "Entities/Ground.h"
#include "Graphics/Display/Window.h"
#include "Inputs/InputSystem.h"
#include "Physics/ContactListener.h"

class Engine
{
public:
    Engine();
    ~Engine();
    void initialize();
    void update();

private:
    Graphics graphics;
    Physics physics;
    Player& player = Player::getInstance();
    Ground ground;
    InputSystem input;
    ContactListener* playerContactListener;
    ExecutionTimeTracker timer;
};