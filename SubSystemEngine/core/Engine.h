#pragma once
#include "Graphics.h"
#include "Physics.h"
#include "Entity.h"
#include "Window.h"

class Engine
{
public:
    Engine();
    ~Engine();
    void initialize();
    void update();
    void stop();
private:
    Graphics graphics;
    Physics physics;
    Entity player;
    bool isRunning;
};