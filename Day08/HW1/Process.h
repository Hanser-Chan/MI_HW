//
// Created by HanserChan on 2024/4/27.
//

#ifndef HW1_PROCESS_H
#define HW1_PROCESS_H

#include <vector>
#include <algorithm>
#include <queue>

class Process{
public:
    int Pid;                //pid
    double ArrivalTime;        //到达时间
    double RunningTime;        //运行时间
    double RemainTime;         //剩余运行时间
    int Priority;           //优先级
    double TurnAroundTime;     //流转时间

    Process(int pid, double arrivalTime, double runningTime, int priority = 0);
};

class Scheduler{

public:
    explicit Scheduler(const std::vector<Process> &processes);
    virtual double schedule() = 0;

protected:
    std::vector<Process> Processes;
    double av_TurnAroundTime;
};


//实现先来先服务算法

class FCFS_Scheduler : public Scheduler{
public:
    explicit FCFS_Scheduler(const std::vector<Process> &processes);

    double schedule() override;
};



//用于比较优先级
struct CompareProcesses {
    bool operator()(const Process& p1, const Process& p2) {

        if (p1.RemainTime == p2.RemainTime)
            return p1.ArrivalTime > p2.ArrivalTime;
        // 剩余时间短的进程具有更高的优先级
        return p1.RemainTime > p2.RemainTime;
    }
};


class SJF_Scheduler : public Scheduler{
public:
    explicit SJF_Scheduler(const std::vector<Process> &processes);

    double schedule() override;
protected:
    std::priority_queue<Process, std::vector<Process>, CompareProcesses> SJFQueue;
};



#endif //HW1_PROCESS_H
