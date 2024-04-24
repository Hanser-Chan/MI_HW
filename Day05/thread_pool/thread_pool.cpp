//
// Created by 85262 on 2024/4/24.
//

#include "thread_pool.h"

cjj::ThreadJoin::ThreadJoin(vector<std::thread> &threadX) : threadX(threadX) {}

cjj::ThreadJoin::~ThreadJoin(){
    for (auto& th : threadX) {
        if (th.joinable()){
            th.join();
        }
    }
}

cjj::ThreadPool::~ThreadPool() {
    stop();
    m_cond.notify_all();    //通知所有等待的线程
}
