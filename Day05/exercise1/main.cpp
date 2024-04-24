#include <iostream>
#include <thread>
#include <vector>
#include <numeric>
#include <chrono>

void partial_sum(const std::vector<int>& data, int start, int end, long long& result) {
    result = std::accumulate(data.begin() + start, data.begin() + end, 0LL);
}

int main() {
    // 创建一个含有 10000 个元素的数组
    std::vector<int> data(10000, 1);

    // 定义结果变量和线程
    int num_threads = 4;
    std::vector<long long> results(num_threads, 0);
    std::vector<std::thread> threads(num_threads);

    // 开始计时
    auto start_time = std::chrono::high_resolution_clock::now();

    // 启动多个线程进行求和
    int chunk_size = data.size() / num_threads;

    for (int i = 0; i < num_threads; ++i) {
        int start = i * chunk_size;
        int end = (i == num_threads - 1) ? data.size() : (start + chunk_size);
        threads[i] = std::thread(partial_sum, std::cref(data), start, end, std::ref(results[i]));
    }

    // 等待所有线程完成
    for (auto& th : threads) {
        th.join();
    }

    // 汇总结果
    long long total_sum = std::accumulate(results.begin(), results.end(), 0LL);

    // 结束计时
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end_time - start_time;

    // 输出结果
    std::cout << "总数: " << total_sum << std::endl;
    std::cout << "时间使用: " << duration.count() << " ms" << std::endl;

    return 0;
}

