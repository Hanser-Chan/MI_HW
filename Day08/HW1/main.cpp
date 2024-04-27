#include <iostream>
#include "Process.h"

int main() {

    std::vector<Process> processes = {
            {1, 0, 5},
            {2, 3, 8},
            {3, 6, 2},
            {4, 1, 4},
    };


    FCFS_Scheduler fcfsScheduler(processes);
    double fcfs_averageTurnAroundTime = fcfsScheduler.schedule();
    std::cout << "\n先来先服务: 平均周转: " << fcfs_averageTurnAroundTime << std::endl;

//    std::cout << "\n先来先服务:" << std::endl;
//    for (const auto& process : processes) {
//        std::cout << "进程 " << process.Pid << ": " << process.TurnAroundTime << std::endl;
//    }


    SJF_Scheduler sjfScheduler(processes);
    double sjf_averageTurnAroundTime = sjfScheduler.schedule();
    // 输出平均周转时间
    std::cout << "\n短作业优先: 平均周转: " << sjf_averageTurnAroundTime << std::endl;

    return 0;

}
