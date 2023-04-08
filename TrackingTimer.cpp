#include "TrackingTimer.h"

void TrackingTimer::stop(void)
{
    end_ = steady_clock::now();
    CalcElapsedTime();
    task_.AddTotalElapsedTime(elapsedTime_);
}

void TrackingTimer::CalcElapsedTime(void)
{
    duration<uint16_t> elapsedTime = duration_cast<duration<uint16_t>>(end_ - start_);
    elapsedTime_ = elapsedTime.count();
}