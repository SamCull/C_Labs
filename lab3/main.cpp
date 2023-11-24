/**
 * @file main.cpp
 * Sam Cullen - C00250093
 * @brief {Doxygen documentation for Barrier lab 2023
 * @version 0.1
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "Barrier.h"
#include <thread>
#include <vector>


const int TotalThreads = 5;
// shows first function in the barrier being executed
void task(std::shared_ptr<Barrier> barrierObj){

for(int i = 0; i < 5; ++i) {
  std::cout << "first " << std::endl;
  barrierObj->waitForAll();
  std::cout << "second" << std::endl;
  barrierObj->waitForAll();
  }
}




int main(void){

  // Array threads and pointer to barrier object
  std::vector<std::thread> threadArray(TotalThreads);
  std::shared_ptr<Barrier> barrierObj( new Barrier(5));

  for(int i=0; i < threadArray.size(); i++){
    threadArray[i]=std::thread(task,barrierObj);
  }
  for(int i = 0; i < threadArray.size(); i++){
    threadArray[i].join();
  }
  return 0;
}