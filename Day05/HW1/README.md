# 哲学家进餐问题说明
> 由于macOS会自动结束线程，转移至windows可以正常输出
> 
> 吃5次情况具体输出可参考`output.pdf`,吃1次如下图

![philo.png](https://img2.imgtp.com/2024/04/24/eWf45LAl.png)

## 算法实现

### 牢版本(2024.5)

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

### 新版本(2024.8)

>在复习操作系统的时候，又把这段代码拿出来看了一下。
>

上面的代码会出现一个**典型的问题**——如果都同时5个人**并发**拿筷子，就会产生**死锁**，幸运的是，这个问题在运行时出现，但是这个也是需要解决的。

所以我们可以添加一个拿筷子的时候的`mutex`，这样就不会出现五个人同时拿右边筷子的情况。

那如果只是需要不出现`五个人同时拿右边筷子`的情况，我们可以变更某一个人的拿筷子顺序，所以我们只需要把4号的顺序改成先拿左后拿右即可，就不用再设置一个新的`互斥量`。

```cpp
void eat(int id){
    int cishu{0};
    int left_chop = id;
    int right_chop = (id+1) % PHI;
    while (true){
        cishu++;
        if (cishu > 5) break;
        cout << format("哲学家{}在思考\n", id);
        if (id == 4) {  // 更改最后一位哲学家的拿筷子顺序
            chop[left_chop].lock();
            cout << format("哲学家{}拿起了左边的筷子{}\n", id, left_chop);
            chop[right_chop].lock();
            cout << format("哲学家{}拿起了右边的筷子{}\n", id, right_chop);
        } else {
            chop[right_chop].lock();
            cout << format("哲学家{}拿起了右边的筷子{}\n", id, right_chop);
            chop[left_chop].lock();
            cout << format("哲学家{}拿起了左边的筷子{}\n", id, left_chop);
        }
        cout << format("哲学家{}吃个饭先,已经吃了{}次\n", id, cishu);
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        chop[right_chop].unlock();
        chop[left_chop].unlock();
        cout << format("哲学家{}吃爽了，放下了左边{}筷子和右边{}筷子\n", id, left_chop, right_chop);
    }
}

```



## 管理线程

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