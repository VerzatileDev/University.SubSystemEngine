#pragma once

/// <summary>
/// Base class for all components See Entity.h for more information
/// </summary>
class Component
{
public:
    virtual ~Component() = default;
    virtual void Update() = 0;
};