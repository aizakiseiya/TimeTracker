#include <string>
#include <iostream>
#include <unistd.h>

#include "TrackingTask.h"
#include "TrackingTimer.h"

int main()
{
    std::string taskName = "トラッキングツール作成";
    std::string description = "タスクにかかる時間をトラッキングするツールを作成します";

    // タスクを生成
    TrackingTask task(taskName, description);

    // タイマ生成
    TrackingTimer timer;

    timer.start();
    sleep(5);
    timer.stop();

    // 開始から停止までの経過時間を表示
    std::cout << timer.GetElapsedTime()     << std::endl;

    std::cout << task.GetTaskName()         << std::endl;
    std::cout << task.GetTaskDescription()  << std::endl;

    return 0;
}