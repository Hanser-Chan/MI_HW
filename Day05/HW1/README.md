# 说明
> 由于macOS内置CMake会自动结束线程，转移至windows可以正常输出
> 
> 吃5次情况具体输出可参考`output.pdf`,吃1次如下图

![philo.png](https://img2.imgtp.com/2024/04/24/eWf45LAl.png)

## 算法实现

每个线程会执行抢占执行`上锁`,所以在拿起筷子这里只考虑一个人的行为即可。

并且限制每个人用餐的次数(这样能避免一个线程抢占到死),
再给每个人分配用餐时间1毫秒的用餐时间，用餐后立即将筷子放下，即`解锁`.
```cpp
while (true){
        cishu++;
        if (cishu > 5) break;
        cout << format("哲学家{}在思考\n",id);

        chop[right_chop].lock();
        cout << format("哲学家{}拿起了右边的筷子{}\n",id,right_chop);

        chop[left_chop].lock();
        cout << format("哲学家{}拿起了左边的筷子{}\n",id,left_chop);

        cout << format("哲学家{}吃个饭先,已经吃了{}次\n",id,cishu);
        std::this_thread::sleep_for(std::chrono::microseconds(1));

        chop[right_chop].unlock();
        chop[left_chop].unlock();

        cout << format("哲学家{}吃爽了，放下了左边{}筷子和右边{}筷子\n",id,left_chop,right_chop);
    }
```

## 优化代码

使用`std::vector`存储不同的线程,再由循环统一结束执行。可以省去很多的定义代码部分。
```c++
std::vector<std::thread> philo;

    for (int i = 1; i <= PHI; ++i) {
        philo.push_back(std::thread(eat,i));
    }

    for (auto& ph:philo) {
        ph.join();
    }
```