#include "SafeQueue.h"
#include "ThreadPool.h"


void doWork1() {
    std::cout << "Функция: " << __FUNCTION__ << " сделала свою работу!" << std::endl;
}

void doWork2() {
    std::cout << "Функция: " << __FUNCTION__ << " сделала свою работу!" << std::endl;
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "rus");
    const int cores = std::thread::hardware_concurrency();
    std::vector<std::function<void()>> vectorOfFunctions{ doWork1, doWork2 };
    int countSubmits = 8;
    ThreadPool thread_pool{ cores };
    std::thread thread1(&ThreadPool::submit, &thread_pool, vectorOfFunctions, countSubmits);
    thread1.join();
    return 0;
}