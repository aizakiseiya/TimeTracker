#ifndef _TRAKINGTASK_
#define _TRAKINGTASK_
#include "TrackingTask.h"
#endif

TrackingTask::TrackingTask(std::string taskName, std::string taskDescription, WorkHistory& history)
                : taskName_(taskName), taskDescription_(taskDescription), history_(history) 
{  
    status_ = TaskStatus::UNTOUCHED;
}