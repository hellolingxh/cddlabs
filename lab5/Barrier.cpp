// Barrier.cpp --- 
// 
// Filename: Barrier.cpp
// Description: As one of the synchronization methods, a barrier tells a group of threads or processes must stop at the barrier and cannot proceed until all other threads/processes reach this barrier.
// Author: Xiaohui Ling 
// Created:22/11/2019 
// 
//The MIT License

/* * Copyright (c) 2019 Xiaohui Ling
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */ 

// Code:
#include "Semaphore.h"
#include "Barrier.h"
#include <iostream>

Barrier::Barrier(int numThreads):
	numThreads(numThreads)
{
	this->numThreads = numThreads;
	this->count = 0;
	this->theLock.reset(new Semaphore(1));
	this->turnstile1.reset(new Semaphore(0));
	this->turnstile2.reset(new Semaphore(1));
}

Barrier::~Barrier()
{
	this->theLock.reset();
	this->turnstile1.reset();
	this->turnstile2.reset();
}


void Barrier::phase1()
{
	this->theLock->Wait();	
	++count;
	if(count==numThreads)
	{
		this->turnstile2->Wait();
		this->turnstile1->Signal();
	}
	this->theLock->Signal();
	this->turnstile1->Wait();
	this->turnstile1->Signal();
	
}

void Barrier::phase2()
{
	this->theLock->Wait();	
	--count;
	if(count==0)
	{
		this->turnstile1->Wait();
		this->turnstile2->Signal();
	}
	this->theLock->Signal();
	this->turnstile2->Wait();
	this->turnstile2->Signal();
	
}

void Barrier::wait()
{
	phase1();
	phase2();
}
 
// Barrier.cpp ends here
