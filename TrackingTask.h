#include <string>
#include <stdint.h>

class TrackingTask
{
public:
    TrackingTask(std::string taskName, std::string taskDescription)
            : taskName_(taskName), taskDescription_(taskDescription) {} ;

    std::string& GetTaskName(void) { return taskName_; };
    std::string& GetTaskDescription(void) { return taskDescription_; };
    void AddTotalElapsedTime(uint16_t time) { totalElapsedTime_ += time; };
    uint16_t GetTotalElapsedTime(void) { return totalElapsedTime_; };
private:
    std::string taskName_;
    std::string taskDescription_;
    uint16_t totalElapsedTime_;   // 累計経過時間
    uint16_t estimatedWorkTime_minute_;  // 推定作業時間 分
    uint16_t estimatedWorkTime_hour_;    // 推定作業時間 時
};