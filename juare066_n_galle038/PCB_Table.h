//=========================================================
//HW#: HW1
//Name: Fernando Juarez & Christian Galleisky
//Date: September 18, 2019
//Course: CS433 HW1
//Complier:  g++
//File type: PCB_Table.h - Header file for PCB_Table.cpp
//=========================================================

#ifndef PCB_TABLE_H
#define PCB_TABLE_H

#include "PCB.h"
#include "vector"
class PCB_Table : public PCB
{
private:
    std::vector<PCB> vectorOfProcesses;
public:
    PCB_Table();
    ~PCB_Table();
    void createTable(int numberOfEntries);
    PCB getElementFromTable(int id);
};
#endif
