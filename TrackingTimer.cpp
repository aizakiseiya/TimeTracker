#include "TrackingTimer.h"

double TrackingTimer::GetElapsedTime(void)
{
    duration<double> elapsedTime = duration_cast<duration<double>>(end_ - start_);
    elapsedTime_ = elapsedTime.count();
    return elapsedTime_;
}