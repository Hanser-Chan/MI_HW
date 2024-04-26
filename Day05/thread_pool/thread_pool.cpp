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

    for (int i = 0; i != nthreads; ++i) {
        m_threads.push_back(std::thread([this] {
            while (!m_stop.load(std::memory_order_acquire)) {
                fun funs;
                {
                    std::unique_lock<std::mutex> ulk(this->m_mtx);
                    this->m_cond.wait(ulk, [this] {
                        return m_stop.load(std::memory_order_acquire) || !this->m_fun.empty();
                    });
                    if (m_stop.load(std::memory_order_acquire))
                        return;
                    funs = std::move(this->m_fun.front());
                    this->m_fun.pop();
                }
                funs();
            }
        }));
    }

}




cjj::ThreadPool::~ThreadPool(){
    stop();
    m_cond.notify_all();    //通知所有等待的线程, 解阻塞
}