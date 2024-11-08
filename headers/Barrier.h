#ifndef BARRIER_H
#define BARRIER_H

#include <mutex>
#include <condition_variable>

class Barrier {
public:
    Barrier(int numThreads);
    /* точка синхронизации */
    void arrive_and_wait();

private:
    std::mutex mutex;
    /* событие для ожидания */
    std::condition_variable condition;
    int numThreads;
    /* количество потоков, которые уже достигли барьера */
    int waiting;
};

#endif
