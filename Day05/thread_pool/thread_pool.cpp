//
// Created by HanserChan on 2024/4/24.
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

cjj::ThreadPool::ThreadPool(int n)
        : m_stop(false)
        , m_tj(m_threads)
{
    int nthreads = n;
    if (nthreads <= 0)
    {
        nthreads = std::thread::hardware_concurrency(); //检查支持的线程数
        nthreads = (nthreads == 0 ? 2 : nthreads);
    }
}

cjj::ThreadPool::~ThreadPool() {
    stop();
    m_cond.notify_all();    //通知所有等待的线程, 解阻塞
}
