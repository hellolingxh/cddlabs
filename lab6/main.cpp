/* main.cpp --- 
 * 
 * Filename: main.cpp
 * Author: Xiaohui Ling / C00212235
 * Description: 
 * This is main function to run the test producer and consumer with semaphore sync 
 */


/* Code: */

#include "Message.h"
#include "MessageBuffer.h"
#include <iostream>
#include <thread>
#include <vector>


static const int PRODUCER_THREAD_TOTAL = 1; // create the quantity of the producer thread 
static const int CONSUMER_THREAD_TOTAL = 5; // create the quantity of the consumer thread 
static const int SIZE=5;// the message buffer size 
static const int CHAR_NUMBER = 10;// the number of the loop times 

/*! \fn producer
    \brief Creates messages and adds them to buffer
*/

void producer(std::shared_ptr<MessageBuffer> mBuffer){
  
   for(int i=0;i<CHAR_NUMBER;i++){ 
    //Produce message and add to buffer
    Message msg;
    mBuffer->put(msg);
    //if the value of the msg is 'X' then need to finish the producer thread.
   }
}//producer

/*! \fn consumer
    \brief Takes messages from buffer and consumes them
*/

void consumer(std::shared_ptr<MessageBuffer> mBuffer){
  for(int i=0;i<CHAR_NUMBER;i++){
    //Produce event and add to buffer
    Message msg = mBuffer->get();
    // if the value of the msg is 'X' then need to finish the consumer thread.
  }
}//consumer

int main(void){

  std::vector<std::thread> producers(PRODUCER_THREAD_TOTAL);
  std::vector<std::thread> consumers(CONSUMER_THREAD_TOTAL);
  std::shared_ptr<MessageBuffer> messageBuffer( new MessageBuffer(SIZE));
  /**< Launch the threads  */
  for(std::thread& p: producers){
    p=std::thread(producer,messageBuffer);
  }

  for(std::thread& c: consumers){
    c=std::thread(consumer,messageBuffer);
  }

  /**< Join the threads with the main thread */
  for (auto& p :producers){
      p.join();
  }
  for (auto& c :consumers){
      c.join();
  }

  std::cout  << std::endl;
  return 0;
}
