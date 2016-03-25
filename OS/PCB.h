/*
 * PCB.h
 *
 *  Created on: Mar 22, 2016
 *      Author: kylearchuleta
 */

#ifndef PCB_H_
#define PCB_H_
#include <iostream>
#include <ctime>

#define TIMESLICE 100 //temporary value for timeslice

struct AccountingInfo{
	time_t timeLeft; //time used
	time_t timeSlice; //time limits
	//int account number; //account number  
};

enum ProcessState {start,ready,blocked,running,end};
class PCB {
private:
	int identifier; //Unique identifier for each process
	ProcessState state; //State of the process
	int priority; //Priority level relative to other processes
	int programCounter; //Address of the next instruction in the program to be executed
	int *memoryPointer; //pointers to program code/data & memory blocks shared with other processes
	int contextdata; //data that are present in registers in the processor while its executing
	int io; //work on, includes outstanding IO requires, devices, list of files in use, etc
	AccountingInfo info;
public:
	PCB(int, int, time_t);
	~PCB();
	void test(); //test method to print info
};

#endif /* PCB_H_ */
