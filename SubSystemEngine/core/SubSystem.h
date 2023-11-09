#pragma once

#include "Data/ExecutionTimeTracker.h"

class SubSystem
{
public:
    virtual void Initialize() = 0;
    virtual void Update() = 0;

    void EnableFrameRateTracking(bool enable) {
        showFrameRate = enable;
    }

    bool IsFrameRateTrackingEnabled() const {
        return showFrameRate;
    }

protected:
    ExecutionTimeTracker timer;

private:
    bool showFrameRate = false;
};