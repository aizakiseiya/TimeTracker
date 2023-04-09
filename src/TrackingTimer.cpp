#include "TrackingTimer.h"

using TrackingTask::TaskStatus = TaskStatus

void TrackingTimer::start(void)
{
    int status = task_.GetTaskStatus();

    if ( status == TaskStatus::UNTOUCHED || status == TaskStatus::BREAK ){
        start_ = steady_clock::now();
        task_.SetTaskStatus(TaskStatus::WORKING);

        TaskRecord record;
        auto now = system_clock::now();
        record.timestamp = system_clock::to_time_t(now);
        record.status = TaskStatus::WORKING;
        record.taskName = task_.GetTaskName();
        task_.history_.AddRecord(record);
    }
}

void TrackingTimer::TaskBreak(void)
{
    stop(TaskStatus::BREAK);
}

void TrackingTimer::TaskComplete(void)
{
    stop(TaskStatus::COMPLETED);
}

void TrackingTimer::stop(int next_status)
{
    if ( next_status == TaskStatus::BREAK || next_status == TaskStatus::COMPLETED){
        int status = task_.GetTaskStatus();
        if ( status == TaskStatus::WORKING ){
            end_ = steady_clock::now();
            CalcElapsedTime();
            task_.AddTotalElapsedTime(elapsedTime_);
            task_.SetTaskStatus(next_status);

            TaskRecord record;
            auto now = system_clock::now();
            record.timestamp = system_clock::to_time_t(now);
            record.status = next_status;
            record.taskName = task_.GetTaskName();
            task_.history_.AddRecord(record);
        }
    }else{
        // error
    }
}


void TrackingTimer::CalcElapsedTime(void)
{
    duration<uint16_t> elapsedTime = duration_cast<duration<uint16_t>>(end_ - start_);
    elapsedTime_ = elapsedTime.count();
}
