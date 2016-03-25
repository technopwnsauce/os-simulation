/*
 * main.cpp
 *
 *  Created on: Mar 24, 2016
 *      Author: kylearchuleta
 */

#include <iostream>
#include <ctime>
#include "PCB.h"

using namespace std;

int main(void){ //main function - the OS simulator

	//some test "processes to see if the PCB works.

	PCB process1(0,1,1000);
	PCB process2(1,2,600);
	PCB process3(2,2,400);

	process1.test();
	process2.test();
	process3.test();

	return 0;
}

