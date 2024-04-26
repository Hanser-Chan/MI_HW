//
// Created by HanserChan on 2024/4/24.
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


    private:
        ThreadJoin(ThreadJoin&& tj) = delete;
        ThreadJoin& operator = (ThreadJoin&& tj) = delete;

        ThreadJoin(const ThreadJoin&) = delete;
        ThreadJoin& operator = (const ThreadJoin&) = delete;
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

        template<class Function, class... Args>
        std::future<typename std::result_of<Function(Args...)>::type> add(Function&&, Args&&...);


    private:
        ThreadPool(ThreadPool&&) = delete;
        ThreadPool& operator= (ThreadPool&&) = delete;
        ThreadPool(const ThreadPool&) = delete;
        ThreadPool& operator= (const ThreadPool&) = delete;

    private:
        std::atomic<bool> m_stop;
        std::mutex m_mtx;
        std::condition_variable m_cond;

        std::queue<fun> m_fun;
        std::vector<std::thread> m_threads;
        cjj::ThreadJoin m_tj;


    };


    template <class Function, class... Args>
    std::future<typename std::result_of<Function(Args...)>::type>
    cjj::ThreadPool::add(Function&& fcn, Args&&... args)
    {
        typedef typename std::result_of<Function(Args...)>::type return_type;
        typedef std::packaged_task<return_type()> task;

        auto t = std::make_shared<task>(std::bind(std::forward<Function>(fcn), std::forward<Args>(args)...));
        auto ret = t->get_future();
        {
            std::lock_guard<std::mutex> lg(m_mtx);
            if (m_stop.load(std::memory_order_acquire))
                throw std::runtime_error("thread pool has stopped");
            m_fun.emplace([t]{(*t)(); });
        }
        m_cond.notify_one();
        return ret;
    }




}


#endif //THREAD_POOL_THREAD_POOL_H
