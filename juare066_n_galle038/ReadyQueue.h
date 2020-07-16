//=========================================================
//HW#: HW1
//Name: Fernando Juarez & Christian Galleisky
//Date: September 18, 2019
//Course: CS433 HW1
//Complier:  g++
//File type: ReadyQueue.h - Header file for ReadyQueue.cpp
//=========================================================

#ifndef READYQUEUE_H
#define READYQUEUE_H

#include <vector>
#include <iterator>
#include "PCB.h"

using namespace std;

class ReadyQueue
{
private:
    int left(int parent);
    int right(int parent);
    int parent(int child);
    vector <PCB> heap;
    void heapifyUp(int index);
    void heapifyDown(int index);
public:
    ReadyQueue();
    ~ReadyQueue();
    void insertProc(PCB element);
    void deleteMin();
    void removeHighestProc();
    void displayQueue();
    void aging(unsigned int index);
    void reHeap();
    int size();
    
};

#endif
