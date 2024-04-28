# 生成火焰图

> 提供3个实现方案
>
> 1. Day05 哲学家进餐
> 2. 找到wireshark的进程
> 3. 死循环进程

## 命令

![52e0c829b93cb9f402aea4abde677c37.png](https://img2.imgtp.com/2024/04/28/Jr6nVZKX.png)



## phi

可以看到有`std::thread`和`std::chrono`内部函数正在运行，最高的那一条，应该是定义的等待时间`std::chrono::seconds(1)`

![perf.png](https://img2.imgtp.com/2024/04/28/De4tJWPE.png)





## endless_loop

循环内不停赋值，可以看到一直在start初始化

![f84ab1dbaab3c441df6d661a257706b0.png](https://img2.imgtp.com/2024/04/28/EOAjgT9u.png)



## wireshark

这是wireshark软件内部函数调用

![perf.png](https://img2.imgtp.com/2024/04/28/Zz1vTRRB.png)