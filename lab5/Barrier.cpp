// Barrier.cpp --- 
// 
// Filename: Barrier.cpp
// Description: 
// Author: Joseph
// Maintainer: 
// Created: Tue Jan  8 12:14:02 2019 (+0000)
// Version: 
// Package-Requires: ()
// Last-Updated: Tue Jan  8 12:15:21 2019 (+0000)
//           By: Joseph
//     Update #: 2
// URL: 
// Doc URL: 
// Keywords: 
// Compatibility: 
// 
// 

// Commentary: 
// 
// 
// 
// 

// Change Log:
// 
// 
// 
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at
// your option) any later version.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
// 
// 

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
