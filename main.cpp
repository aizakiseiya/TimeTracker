#include <string>
#include <iostream>
#include <unistd.h>

#ifndef _TRAKINGTASK_
#define _TRAKINGTASK_
#include "TrackingTask.h"
#endif

#ifndef _TRAKINGTIMER_
#define _TRAKINGTIMER_
#include "TrackingTimer.h"
#endif

#ifndef _WORKHISTORY_
#define _WORKHISTORY_
#include "WorkHistory.h"
#endif

int main()
{
    std::string taskName = "トラッキングツール作成";
    std::string description = "タスクにかかる時間をトラッキングするツールを作成します";

    WorkHistory history;
    // タスクを生成
    TrackingTask task(taskName, description, history);

    // タイマ生成
    TrackingTimer timer(task);


    timer.start();
    sleep(1);
    timer.TaskBreak();
    std::cout << timer.GetElapsedTime()     << std::endl;

    timer.start();
    sleep(2);
    timer.TaskBreak();
    std::cout << timer.GetElapsedTime()     << std::endl;

    timer.start();
    sleep(3);
    timer.TaskComplete();
    std::cout << timer.GetElapsedTime()     << std::endl;


    std::cout << task.GetTaskName()         << std::endl;
    std::cout << task.GetTaskDescription()  << std::endl;
    // タスクの累計作業時間を表示
    std::cout << task.GetTotalElapsedTime()      << std::endl;

    for( auto& taskRecord : history.GetHistory() ){
        std::cout << "[Timestamp] "  << taskRecord.timestamp << "   " 
                  << "[Task Name] "  << taskRecord.taskName  << "   " 
                  << "[Status] "     << taskRecord.status    << std::endl;
    }

    return 0;
}