#pragma once
#include <chrono>
#include <string>
#include <iostream>

class ExecutionTimeTracker {
public:
    // Elapsed Time
    void StartTimer();
    void StopTimer();
    // Calculations
    long long GetElapsedTimeMicroseconds() const;
    void GetAndPrintFrameRate(const std::string& subsystemName) const; // Return Frame Rate by dividing 1 second by the elapsed time
    // Print
    void PrintElapsedTime(const std::string& functionName) const;
private:
    // Elapsed Time
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> endTime;
    // Frame Rate
    double elapsedTime = 0.0;
    int frames = 0;
};