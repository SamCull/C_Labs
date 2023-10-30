#include "Barrier.h"
#include <thread>
#include <vector>
const int TotalThreads = 5;
/*! displays the first function in the barrier being executed */
void task(std::shared_ptr<Barrier> barrierObj) {
    for (int i = 0; i < 5; ++i) {
        std::cout << "first " << std::endl;
        barrierObj->waitForAll();
        std::cout << "second" << std::endl;
        barrierObj->waitForAll();
    }
}
int main(void) {

    /*!< An array of threads*/
    std::vector<std::thread> threadArray(TotalThreads);
    /*!< Pointer to barrier object*/
    std::shared_ptr<Barrier> barrierObj(new Barrier(5));

    barrierObj->setCount(5);

    for (int i = 0; i < threadArray.size(); ++i) {
        threadArray[i] = std::thread(task, barrierObj);
    }

    for (int i = 0; i < threadArray.size(); i++) {
        threadArray[i].join();
    }

    return 0;
}