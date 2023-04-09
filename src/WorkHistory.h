#include <chrono>
#include <string>
#include <vector>

#ifndef _TRAKINGTASK_
#define _TRAKINGTASK_
#include "TrackingTask.h"
#endif

using namespace std::chrono;

using TaskRecord = struct {
    std::time_t  timestamp;
    std::string     taskName;
    int      status; 
};

class WorkHistory
{
public:
    WorkHistory(void) {};
    std::vector<TaskRecord>& GetHistory(void) { return history_; };
    void AddRecord(TaskRecord record) { history_.push_back(record); };
private:
    std::vector<TaskRecord> history_;
};