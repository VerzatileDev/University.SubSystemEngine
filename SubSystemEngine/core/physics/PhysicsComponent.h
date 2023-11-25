#pragma once

#include "../Component.h"
#include <Box2D/Box2D.h>

class PhysicsComponent : public Component
{
public:
    PhysicsComponent();
    ~PhysicsComponent();
    void Update() override;

private:
    
};