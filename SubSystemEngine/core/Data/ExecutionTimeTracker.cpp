#include "ExecutionTimeTracker.h"

void ExecutionTimeTracker::StartTimer() {
    startTime = std::chrono::high_resolution_clock::now();
}

void ExecutionTimeTracker::StopTimer() {
    endTime = std::chrono::high_resolution_clock::now();
    elapsedTime = std::chrono::duration<float>(endTime - startTime).count();
    frames++;
}

long long ExecutionTimeTracker::GetElapsedTimeMicroseconds() const {
    return std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
}

void ExecutionTimeTracker::PrintElapsedTime(const std::string& functionName) const {
    std::cout << functionName << " took " << GetElapsedTimeMicroseconds() << " microseconds" << std::endl;
}

void ExecutionTimeTracker::GetAndPrintFrameRate() const {
    //return frames / elapsedTime;
    std::cout << "\rFrame Rate: " << static_cast<int>(frames / elapsedTime) << std::endl;
}