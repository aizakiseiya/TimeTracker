#include <string>
#include <iostream>

#include "TrackingTask.h"

int main()
{
    std::string taskName = "トラッキングツール作成";
    std::string description = "タスクにかかる時間をトラッキングするツールを作成します";

    TrackingTask task(taskName, description);

    std::cout << task.GetTaskName()         << std::endl;
    std::cout << task.GetTaskDescription()  << std::endl;

    return 0;
}