/* MessageBuffer.cpp ---
 *
 * Filename: MessageBuffer.cpp
 * Author: Xiaohui Ling / C00212235
 * Description:
 * This is a class implement the MessageBuffer.h interface.
 */


/* code: */

#include "MessageBuffer.h"
#include <iostream>
#include <stdlib.h>

// initialization the members within constructor
MessageBuffer::MessageBuffer(int aSize)
{
	this->size = aSize;
	this->count = 0;
	this->theMutex = std::make_shared<Semaphore>(1);
	this->theSemaphore = std::make_shared<Semaphore>(0);
}

// put the the char into the queue through the mutex lock and semaphore sync signal
int MessageBuffer::put(Message msg)
{
	this->theMutex->Wait();
	this->queue.push_back(msg);
 	std::cout << "Producer: ";
 	msg.printMsg();
	std::cout << std::endl;	
	++count;
	int size = this->queue.size();
	this->theMutex->Signal();
	this->theSemaphore->Signal();
	return size;
}

// get the the char from the queue through the mutex lock and semaphore sync signal
Message MessageBuffer::get()
{
	this->theSemaphore->Wait();
	this->theMutex->Wait();
	Message msg = this->queue.back();
	this->queue.pop_back();
 	std::cout << "Consumer: "; 
	msg.printMsg();
	std::cout << std::endl;	
	--count;
	this->theMutex->Signal();
	return msg;
}
