#include "Semaphore.h"
#include <thread>
#include <vector>
#include <iostream>


int arrThread = 0;

/*! displays the first function in the barrier being executed */
void task(std::shared_ptr<Semaphore> mutexSem, std::shared_ptr<Semaphore> barrierSem, int threadCount) {

    mutexSem->Wait(); // Open
    std::cout << "first " << std::endl;
    ++arrThread; // increment thread

    if (arrThread == threadCount) { // if all threads arrive, proceed
        mutexSem->Signal();
        barrierSem->Signal();
    }
    else {
        mutexSem->Signal();
        barrierSem->Wait();
    }
    //put barrier code here
    mutexSem->Wait(); // Open
    std::cout << "second" << std::endl;
    mutexSem->Signal(); // Release lock

    barrierSem->Signal();
}




int main(void) {
    std::shared_ptr<Semaphore> mutexSem;
    std::shared_ptr<Semaphore> barrierSem;
    int threadCount = 5;
    mutexSem = std::make_shared<Semaphore>(1);
    barrierSem = std::make_shared<Semaphore>(0);
    /*!< An array of threads*/
    std::vector<std::thread> threadArray(threadCount);
    /*!< Pointer to barrier object*/

    for (int i = 0; i < threadArray.size(); i++) {
        threadArray[i] = std::thread(task, mutexSem, barrierSem, threadCount);
    }

    for (int i = 0; i < threadArray.size(); i++) {
        threadArray[i].join();
    }

    return 0;
}
