#include <chrono>
#include <stdint.h>

#ifndef _TRAKINGTASK_
#define _TRAKINGTASK_
#include "TrackingTask.h"
#endif

using namespace std::chrono;

class TrackingTimer
{
public:
    TrackingTimer(TrackingTask& task) 
            : task_(task) {} ;
    void start(void);
    void TaskBreak(void);
    void TaskComplete(void);
    void CalcElapsedTime(void);
    uint16_t GetElapsedTime(void) { return elapsedTime_; };

private:
    void stop(int next_status);

    TrackingTask& task_;
    steady_clock::time_point start_;
    steady_clock::time_point end_;
    uint16_t elapsedTime_;
};