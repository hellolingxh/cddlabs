#ifndef RENDEZVOUSTHREAD_H
#define RENDEZVOUSTHREAD_H
#include "Semaphore.h"
#include <thread>
#include <memory>
#include <iostream>
class RendezvousThread : public thread
{
    std::shared_ptr<Semaphore> firstSemaphore;
    std::shared_ptr<Semaphore> secondSemaphore;
    int waitTime;
public:
    RendezvousThread(std::shared_ptr<Semaphore>, std::shared_ptr<Semaphore>, int);
    void run();
};

#endif // RENDEZVOUSTHREAD_H
