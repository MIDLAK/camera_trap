#include "../headers/Barrier.h"

Barrier::Barrier(int numThreads) : numThreads(numThreads), waiting(0) {}

void Barrier::arrive_and_wait() {
    /* блокировка мьютекса */
    std::unique_lock<std::mutex> lock(mutex);
    waiting++;

    if (waiting == numThreads) {
        /* последний поток сбрасывает счетчик и будит все потоки */
        waiting = 0;
        condition.notify_all();
    } else {
        /* ждать до тех пор, пока все потоки не достигнут барьера */
        condition.wait(lock, [this] { return waiting == 0; });
    }
}
