//=========================================================
//HW#: HW1
//Name: Fernando Juarez & Christian Galleisky
//Date: September 18, 2019
//Course: CS433 HW1
//Complier:  g++
//File type: main.cpp - Driver class of HW1, testes the data
// and outputs the result after each procedure.
//=========================================================
#include <time.h>
#include "PCB.h"
#include "PCB_Table.h"
#include "ReadyQueue.h"
#include <time.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <sys/time.h>

using namespace std;

int main()
{
    //prepare clock
    struct timeval start, end;
    
    //creates a PCB object in order to print out the header
    PCB header;
    header.printHeader();
    
    //creates a table of 20 entries
    PCB_Table table;
    table.createTable(20);
    
    //creates a ReadyQueue q1
    //and then gets PCB's from table and insert them into q1
    ReadyQueue q1;
    q1.insertProc(table.getElementFromTable(5));
    q1.insertProc(table.getElementFromTable(1));
    q1.insertProc(table.getElementFromTable(8));
    q1.insertProc(table.getElementFromTable(11));
    q1.displayQueue();
    //use these functions for removing highest priority process from queue
    //and to display the remaining elements in the queue
    q1.removeHighestProc();
    q1.displayQueue();
    
    q1.removeHighestProc();
    q1.displayQueue();
    
    q1.insertProc(table.getElementFromTable(3));
    q1.insertProc(table.getElementFromTable(7));
    q1.insertProc(table.getElementFromTable(2));
    q1.insertProc(table.getElementFromTable(12));
    q1.insertProc(table.getElementFromTable(9));
    q1.displayQueue();
    
    q1.removeHighestProc();
    q1.displayQueue();
    
    q1.removeHighestProc();
    q1.displayQueue();
    
    q1.removeHighestProc();
    q1.displayQueue();
    
    q1.removeHighestProc();
    q1.displayQueue();
    
    q1.removeHighestProc();
    q1.displayQueue();
    
    q1.removeHighestProc();
    q1.displayQueue();
    
    q1.removeHighestProc();
    q1.displayQueue();
    
    //TEST #2
    
    srand(time(0));
    
    // start timer.
    gettimeofday(&start, NULL);
    
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    
    int x = 0;

    //insert ten PCBs into q1
    while (q1.size() != 10)
    {
        int randIndex = rand() % 20;
        PCB randElement;
        randElement = table.getElementFromTable(randIndex);
        randElement.setPriority(rand() % 50 + 1);
        q1.insertProc(randElement); 
    }
    
    for (int k = 0; k < 1000000; k++)
    {
        int Rand_Max_Half = RAND_MAX/2;
        int decider = rand() / Rand_Max_Half;
        if (decider == 0) {
            q1.removeHighestProc();
        }
        else {
            //insertProc will kill on identifying a duplicate, so we loop
            int before = q1.size();
            while (q1.size() != (before+1) && q1.size() < 20)
            {
                int randIndex = rand() % 20;
                PCB randElement;
                randElement = table.getElementFromTable(randIndex);
                randElement.setPriority(rand() % 50 + 1);
                q1.insertProc(randElement);
            }
        }
    }
    
    q1.reHeap();
    q1.displayQueue();
    
    // stop timer.
    gettimeofday(&end, NULL);
    
    // Calculating total time taken by the program.
    double time_taken;
    
    time_taken = (end.tv_sec - start.tv_sec) * 1e6;
    time_taken = (time_taken + (end.tv_usec -
                                start.tv_usec)) * 1e-6;
    
    cout << "Time taken by program is : " << fixed
    << time_taken;
    cout << " sec" << endl;
    
    return 0;
}

