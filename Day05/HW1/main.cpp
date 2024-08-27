#include <iostream>
#include <mutex>
#include <thread>
#include <format>
#include <vector>

using std::cout,std::format;

const int PHI {5};

std::mutex chop[PHI];

//void eat(int id){
//    int cishu{0};
//
//    int left_chop{id};
//    int right_chop{(id+1) % PHI};
//
//    while (true){
//        cishu++;
//        if (cishu > 5) break;
//        cout << format("哲学家{}在思考\n",id);
//
//        chop[right_chop].lock();
//        cout << format("哲学家{}拿起了右边的筷子{}\n",id,right_chop);
//
//        chop[left_chop].lock();
//        cout << format("哲学家{}拿起了左边的筷子{}\n",id,left_chop);
//
//        cout << format("哲学家{}吃个饭先,已经吃了{}次\n",id,cishu);
//        std::this_thread::sleep_for(std::chrono::microseconds(1));
//
//        chop[right_chop].unlock();
//        chop[left_chop].unlock();
//
//        cout << format("哲学家{}吃爽了，放下了左边{}筷子和右边{}筷子\n",id,left_chop,right_chop);
//    }
//}

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


int main() {

    std::vector<std::thread> philo;

    for (int i = 1; i <= PHI; ++i) {
        philo.push_back(std::thread(eat,i));
    }

    for (auto& ph:philo) {
        ph.join();
    }
    return 0;
}
