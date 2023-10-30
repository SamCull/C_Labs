#include "Barrier.h"

/*! \class Barrier
    \brief An Implementation of a barrier Using Semaphores

   Uses C++11 features such as mutex and condition variables to implement a barrier using Semaphores with N number threads

*/
/*! Barrier constructor*/
Barrier::Barrier(int NumOfThreads) {
    this->count = NumOfThreads;
    threadNum = 0;
    condition = false;
    theMutex = std::make_shared<Semaphore>(1);
    innerLock = std::make_shared<Semaphore>(0);
    outerLock = std::make_shared<Semaphore>(1);
}
/*! Barrier with parameter constructor*/
/*
Barrier::Barrier(int count){
  this->count = count;
  threadNum = 0;
  condition = false;
  std::shared_ptr<Semaphore> theMutex(new Semaphore(1));
  std::shared_ptr<Semaphore> innerLock(new Semaphore(0));
  std::shared_ptr<Semaphore> outerLock(new Semaphore(1)); // '1' means one wait without a block
} */
/*! Barrier deconstructor*/
Barrier::~Barrier() {
    // nothing to do
}

/*! sets count value*/
void Barrier::setCount(int x) {
    this->count = x;
}
/*! returns count value*/
int Barrier::getCount() {
    return this->count;
}

/*! waits for all the threads before starting second half of code*/
void Barrier::waitForAll() {
    theMutex->Wait();
    threadNum++;

    if (threadNum == count) {
        outerLock->Wait();
        innerLock->Signal();
    }
    theMutex->Signal();
    innerLock->Wait();
    innerLock->Signal();
    theMutex->Wait();
    threadNum--;
    if (threadNum == 0) {
        innerLock->Wait();
        outerLock->Signal();
    }
    theMutex->Signal();
    outerLock->Wait();
    outerLock->Signal();
}