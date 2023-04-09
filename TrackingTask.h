#include <string>
#include <stdint.h>

#ifndef _WORKHISTORY_
#define _WORKHISTORY_
#include "WorkHistory.h"
#endif

class TrackingTask
{
public:
    enum class TaskStatus {
        UNTOUCHED,
        START,
        WORKING,
        BREAK,
        COMPLETED,     
    }

    TrackingTask(std::string taskName, std::string taskDescription, WorkHistory& history);

    std::string& GetTaskName(void) { return taskName_; };
    int GetTaskStatus(void) { return status_; };
    std::string& GetTaskDescription(void) { return taskDescription_; };
    void AddTotalElapsedTime(uint16_t time) { totalElapsedTime_ += time; };
    uint16_t GetTotalElapsedTime(void) { return totalElapsedTime_; };
    void SetTaskStatus(int status) { status_ = status; };

    WorkHistory& history_;
    
private:
    std::string taskName_;
    std::string taskDescription_;
    int  status_;
    uint16_t totalElapsedTime_;   // 累計経過時間
    uint16_t estimatedWorkTime_minute_;  // 推定作業時間 分
    uint16_t estimatedWorkTime_hour_;    // 推定作業時間 時
};