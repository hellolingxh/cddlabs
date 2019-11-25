/* MessageBuffer.h ---
 * 
 * Filename: MessageBuffer.h
 * Author: Xiaohui Ling / C00212235
 * Description: 
 * This is a buffer to keep the Message instance object.
 */

#ifndef MESSAGEBUFFER_H
#define MESSAGEBUFFER_H


/* Code: */

#pragma once
#include "Message.h"
#include "Semaphore.h"
#include <vector>

class MessageBuffer
{
	private:
		int size; // buffer size
		int count; // how many character in the buffer
		std::vector<Message> queue; // store the char ito the vector
		std::shared_ptr<Semaphore> theMutex; // the mutex lock
		std::shared_ptr<Semaphore> theSemaphore; // the semaphore sync siganl

	public:	
		MessageBuffer(int size); //initial constructor
		Message get(); // the get method that get the char from the queue.
		int put(Message); // the put method that put the char into the queue.
};

#endif //MESSAGEBUFFER_H
