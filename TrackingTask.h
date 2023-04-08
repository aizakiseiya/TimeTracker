#include <string>

class TrackingTask
{
public:
    TrackingTask(std::string taskName, std::string taskDescription)
            : taskName_(taskName), taskDescription_(taskDescription) {} ;

    std::string& GetTaskName(void) { return taskName_; };
    std::string& GetTaskDescription(void) { return taskDescription_; };
private:
    std::string taskName_;
    std::string taskDescription_;
};