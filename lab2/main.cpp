#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <unistd.h>
/*! \class Signal
    \brief An Implementation of Threads Using Semaphores 
   Uses C++11 features such as mutex and condition variables to implement Semaphores in thread functions 
*/

/*! displays a message first*/
void taskOne(std::shared_ptr<Semaphore> theSemaphore, int delay){
  sleep(delay);
  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first"<<std::endl;
  theSemaphore.get()->Signal();//if the taskOne completed,then notify the main thread to resume the threadTwo
}
/*! displays a message second*/
void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore.get()->Wait();//it will wait until it receive the signal sent by threadOne
  std::cout <<"This ";
  std::cout << "will ";
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
}


int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  int taskOneDelay=5;
  threadOne=std::thread(taskOne,sem,taskOneDelay);
  threadTwo=std::thread(taskTwo,sem);
  std::cout << "Launched from the main\n";
   /**< Wait for the threads to finish */
  threadOne.join();
  threadTwo.join();
  return 0;
}
