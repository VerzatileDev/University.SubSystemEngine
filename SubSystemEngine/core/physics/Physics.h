#pragma once
// Included Files
#include "../core/SubSystem.h"

class Physics : public SubSystem
{
public:
    void Initialize() override; // Override Base, Initialize Graphics with window Reference
    void Update() override;
};