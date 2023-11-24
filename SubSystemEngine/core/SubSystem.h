#pragma once

#include "Data/ExecutionTimeTracker.h"

/// <summary>
/// Base Class for SubSystems, such as Graphics, Input, Physics, etc.
/// Contains a timer for tracking the time it takes to execute the Update() function which available for each System
/// </summary>
class SubSystem
{
public:
    virtual void Initialize() = 0;
    virtual void Update() = 0;

    void EnableFrameRateTracking(bool enable) 
    {
        showFrameRate = enable;
    }

    bool IsFrameRateTrackingEnabled() const 
    {
        return showFrameRate;
    }

protected:
    ExecutionTimeTracker timer;

private:
    bool showFrameRate = false;
};