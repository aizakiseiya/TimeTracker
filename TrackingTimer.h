#include <chrono>
#include <stdint.h>

#include "TrackingTask.h" 

using namespace std::chrono;

class TrackingTimer
{
public:
    TrackingTimer(TrackingTask& task) 
            : task_(task) {} ;
    void start(void) { start_ = steady_clock::now(); };
    void stop(void);
    void CalcElapsedTime(void);
    uint16_t GetElapsedTime(void) { return elapsedTime_; };

private:
    TrackingTask& task_;
    steady_clock::time_point start_;
    steady_clock::time_point end_;
    uint16_t elapsedTime_;
};