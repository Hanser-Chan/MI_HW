#include <iostream>
#include <mutex>
#include <thread>
#include <format>
#include <vector>

using std::cout,std::format;

const int PHI {5};

std::mutex chop[PHI];

void eat(int id){
    int cishu{0};

    int left_chop{id};
    int right_chop{(id+1) % PHI};

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
}

int main() {
//    std::thread th1(eat,1);
//    std::thread th2(eat,2);
//    std::thread th3(eat,3);
//    std::thread th4(eat,4);
//    std::thread th5(eat,5);
//
//
//    if(th1.joinable() && th2.joinable() && th3.joinable() && th4.joinable() && th5.joinable()){
//        th1.join();
//        th2.join();
//        th3.join();
//        th4.join();
//        th5.join();
//    }

    std::vector<std::thread> philo;

    for (int i = 1; i <= PHI; ++i) {
        philo.push_back(std::thread(eat,i));
    }

    for (auto& ph:philo) {
        ph.join();
    }
    return 0;
}
