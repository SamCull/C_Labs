/**
 * @file main.cpp
 * Sam Cullen - C00250093
 * @brief {Doxygen documentation for the Wa-tor simluation 2023
 * @version 0.1
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "Barrier.h"
#include "Event.h"
#include <iostream>
#include <thread>
#include <vector>


static const int num_threads = 100;
const int size=20;



void producer(std::shared_ptr<SafeBuffer<std::shared_ptr<Event>> theBuffer, int numLoops){

  for(int i=0;i<numLoops;++i){
    //Produce event and add to buffer
    std::shared_ptr<Event> e= std::make_shared<Event>(i);
    theBuffer.put(e);
  }
  

}


void consumer(std::shared_ptr<SafeBuffer<std::shared_ptr Event>> theBuffer, int numLoops){

  for(int i=0;i<numLoops;++i){
    // add to buffer
    std::shared_ptr<Event> e= theBuffer->get();
    e->consume();
  }
  

}

int main(void){

  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<SafeBuffer<std::shared_ptr<Event>> aBuffer( new Buffer<shared_ptr Event>(size));
  //Launch threads
  int i=0;
  for(std::thread& t: vt){
    t=std::thread(updateTask,aBarrier,10);
  }
  // Join threads with main thread
  for (auto& v :vt){
      v.join();
  }
  std::cout << sharedVariable << std::endl;
  return 0;
}