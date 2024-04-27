//
// Created by HanserChan on 2024/4/27.
//

#include "Process.h"

Process::Process(int pid, double arrivalTime, double runningTime, int priority) :
        Pid(pid), ArrivalTime(arrivalTime), RunningTime(runningTime), Priority(priority) {}

Scheduler::Scheduler(const std::vector<Process> &processes) : Processes(processes) {}

FCFS_Scheduler::FCFS_Scheduler(const std::vector<Process> &processes) : Scheduler(processes) {}

double FCFS_Scheduler::schedule() {
    double currentTime = 0;
    for (auto& process : Processes) {
        // 假设进程按到达时间排序
        currentTime += process.RunningTime;  // 更新当前时间为进程完成时间
        process.TurnAroundTime = currentTime - process.ArrivalTime;
        av_TurnAroundTime += process.TurnAroundTime;
    }
    av_TurnAroundTime /= Processes.size();  // 计算平均周转时间
    return av_TurnAroundTime;
}

SJF_Scheduler::SJF_Scheduler(const std::vector<Process> &processes) : Scheduler(processes) {

    // 初始化时将所有进程的剩余运行时间设置为它们的运行时间
    for (const auto &process: processes) {
        Process p(process.Pid, process.ArrivalTime, process.RunningTime, process.Priority);
        p.RemainTime = process.RunningTime;
        SJFQueue.push(p);
    }
}


double SJF_Scheduler::schedule() {
    double currentTime = 0;

    while (!Processes.empty()){

        //使用一个迭代器找到最短的作业
        auto sj = std::min_element(Processes.begin(),Processes.end(),
                                   [](const Process& a,const Process& b){
                                       return a.RemainTime < b.RemainTime;
        });
        currentTime += sj->RunningTime;
        sj->RemainTime -= sj->RunningTime;
        sj->TurnAroundTime = currentTime - sj->ArrivalTime;

        av_TurnAroundTime += sj->TurnAroundTime;

        if (sj->RemainTime == 0) {
            Processes.erase(sj);
        }

        currentTime += sj->RunningTime;
    }

    av_TurnAroundTime /= Processes.size();


//    double currentTime = 0;
//    int completedProcesses = 0;
//    Process currentProcess = Process(0, 0, 0);
//
//    while (!SJFQueue.empty()) {
//        currentProcess = SJFQueue.top();
//        SJFQueue.pop();
//
//        // 如果当前时间小于进程到达时间，则将当前时间设置为进程到达时间
//        if (currentTime < currentProcess.ArrivalTime) {
//            currentTime = currentProcess.ArrivalTime;
//        }
//
//        currentTime += currentProcess.RemainTime;  // 更新当前时间
//        currentProcess.TurnAroundTime = currentTime - currentProcess.ArrivalTime;  // 计算周转时间
//        av_TurnAroundTime += currentProcess.TurnAroundTime;  // 累加到总周转时间
//        completedProcesses++;  // 完成进程数
//
//        // 更新队列中进程的到达时间，因为有可能有新的进程在当前进程执行期间到达
//        while (!SJFQueue.empty() && SJFQueue.top().ArrivalTime <= currentTime) {
//            Process p = SJFQueue.top();
//            SJFQueue.pop();
//            p.RemainTime = std::max(0.0, p.RemainTime - (currentTime - p.ArrivalTime));  // 更新剩余时间
//            SJFQueue.push(p);
//        }
//    }
//
//    av_TurnAroundTime /= completedProcesses;  // 计算平均周转时间
    return av_TurnAroundTime;
}



