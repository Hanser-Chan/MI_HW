//
// Created by 85262 on 2024/4/24.
//

#ifndef THREAD_POOL_THREAD_POOL_H
#define THREAD_POOL_THREAD_POOL_H

#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <functional>
#include <future>
#include <queue>
#include <type_traits>
#include <utility>
#include <vector>

using std::vector;

namespace cjj{

    class ThreadJoin{
    public:
        explicit ThreadJoin(vector<std::thread> &threadX);
        ~ThreadJoin();

    private:
        vector<std::thread>& threadX;
    };



    class ThreadPool{
    public:
        typedef std::function<void()> fun;  //封装所有有关函数
        explicit ThreadPool(int n = 0);

        ~ThreadPool();

        void stop()
        {
            m_stop.store(true, std::memory_order_release); //原子地以 true替换当前值。按照 order 的值影响内存。
        }


    private:
        std::atomic<bool> m_stop;
        std::mutex m_mtx;
        std::condition_variable m_cond;

        std::queue<fun> m_fun;
        std::vector<std::thread> m_threads;
        cjj::ThreadJoin m_tj;

    };







}


#endif //THREAD_POOL_THREAD_POOL_H
