//
// Created by 85262 on 2024/4/24.
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
