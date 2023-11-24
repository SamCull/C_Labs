/**
 * @file Barrier.cpp
 * Sam Cullen - C00250093
 * @brief {Doxygen documentation for the Barrier lab 2023
 * @version 0.1
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "Barrier.h"
#include <iostream>

/*! \class Barrier
    \brief A Barrier Implementation

   Uses C++11 features such as mutex and condition variables to implement a Barrier class using Semaphores

*/

// Barrier constructor
Barrier::Barrier()
{
  count = 0;
  threadNum = 0;
  condition = false;
  theMutex = std::make_shared<Semaphore>(1);
  innerLock = std::make_shared<Semaphore>(0);
  outerLock = std::make_shared<Semaphore>(1);
}

// Barrier with parameter constructor
Barrier::Barrier(int countOfThreads)
{
  count = countOfThreads;
  threadNum = 0;
  condition = false;
  theMutex = std::make_shared<Semaphore>(1); 
  // inner lock to block threads until all threads have arrive  
  innerLock = std::make_shared<Semaphore>(0); 
  // outer lock to block threads until all threads are finish 
  outerLock = std::make_shared<Semaphore>(1); 
}


Barrier::~Barrier()
{
}


void Barrier::setCount(int x)
{
  this->count = x;
}


int Barrier::getCount()
{
  return this->count;
}

void Barrier::waitForAll()
{
  theMutex->Wait();
  threadNum++;




  
  if (threadNum == count) // release the outer lock 
  {
    outerLock->Wait(); // access the outer lock
    innerLock->Signal();  
  }
  theMutex->Signal(); // release the mutex 

  innerLock->Wait();
  innerLock->Signal();

  theMutex->Wait();
  threadNum--;

  if (threadNum == 0)  // if its last thread to finish, release outer lock */
  {
    innerLock->Wait();
    outerLock->Signal(); //release lock
  }
  theMutex->Signal(); 

  outerLock->Wait(); // access the outer lock (blocks other threads) 
  outerLock->Signal(); // release the outer lock 
}