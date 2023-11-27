#pragma once
#include "Data/ExecutionTimeTracker.h"   

class SubSystem
{
public:
    virtual void initialize() = 0;
    virtual void update() = 0;
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
