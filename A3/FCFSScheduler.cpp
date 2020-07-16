//==============================================================================
//HW#: HW3
//Name: Fernando Juarez & Michael Trani
//Date: November 1, 2019
//Course: CS433 HW3
//Complier:  g++
//File type: scheduler.cpp - FCFS scheduler class which implements the First come
// first serve algorithm when user selects this algorithm option.
//==============================================================================
#include "FCFSScheduler.h"

FCFSScheduler::FCFSScheduler() {
    this->preemptive = 0;
    this->CPUState = 0;
}

FCFSScheduler::FCFSScheduler(const FCFSScheduler& orig) {
    
}

FCFSScheduler::~FCFSScheduler() {
    
}
