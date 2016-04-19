/*
 * HighLevelScheduler.cpp
 *
 *  Created on: Mar 22, 2016
 *      Author: Brett
 */

#include "HighLevelScheduler.h"

bool newJobAdmissionStatus; // Indicates whether a new job will be admitted? (T=Admit, F=No Admit)
std::string entityStatus; // Indicates whether entity is (Job/Process/Terminated)
// Used to decide process admission
int processPriority; // Process priority
int expectedExecutionTime; // Expected execution time
int processIoLevel; // Integer rating of process's level of I/O utilization
int poolIoLevel; // Averaged integer rating of entire pool's level of I/O utilization
int poolIoLevels[100]; //Stores IO rating of each of the potential 100 processes in the pool
int poolCount; // Number of processes in the pool

HighLevelScheduler::HighLevelScheduler()
{
	// TODO Auto-generated constructor stub
}

HighLevelScheduler::~HighLevelScheduler()
{
	// TODO Auto-generated destructor stub
}

// Analyzes the PCB and generates a ranking of the level of I/O utilization
int setProcessIoLevel()
{
	// take some information from the PCB and calculate processIoLevel
	return processIoLevel;
}

// Updates the I/O rating on the current pool of processes
int updatePoolIoLevel()
{
	int tempIoTotal = 0;
	for (int i=1; i<=poolCount; i++)
	{
		tempIoTotal = tempIoTotal + poolIoLevels[i];
	}
	poolIoLevel = floor(tempIoTotal/poolCount);
	return poolIoLevel;
}

// Decides whether or not to admit a new job
bool decideAdmitNewJob()
{
	if (poolCount >= 100)
	{
		newJobAdmissionStatus = false;
	}

	if (poolCount < 100)
	{
		int tempPoolIoLevel = 0;
		tempPoolIoLevel = floor(((poolIoLevel + processIoLevel) / (poolCount + 1)));
		if (tempPoolIoLevel < 100)
		{
			newJobAdmissionStatus = true;
		}
		else
		{
			newJobAdmissionStatus = false;
		}
	}
	return newJobAdmissionStatus;
}

// Admits a new job
void admitJob ()
{
	if (newJobAdmissionStatus == true)
	{
		// call to changeEntityStatus
		// call to pcb creation
	}
}

// Converts status of entity among Job-->Process-->Terminated by gathering info from PCB
std::string changeEntityStatus()
{
	return entityStatus;
}
