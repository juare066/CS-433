//=========================================================
//HW#: HW1
//Name: Fernando Juarez & Christian Galleisky
//Date: September 18, 2019
//Course: CS433 HW1
//Complier:  g++
//File type: PCB_Table.cpp - Creates and gets elements from
// the PCB table.
//=========================================================

#include "PCB_Table.h"
#include <iostream>
using namespace std;

// constructor of PCB_Table
PCB_Table::PCB_Table()
{
    
}
// Destructor of PCB_Table
PCB_Table::~PCB_Table()
{
    
}
// PURPOSE: Creates a table with a given # of entries
void PCB_Table::createTable(int numberOfEntries)
{
    for (int i = 1; i <= numberOfEntries ; i++)
    {
        PCB newProcess = PCB(i, i);
        vectorOfProcesses.push_back(newProcess);
    }
}
// PURPOSE: elements from the table are retrieved
PCB PCB_Table::getElementFromTable(int id)
{
    return vectorOfProcesses.at(id);
}
