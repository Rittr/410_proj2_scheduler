/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements FIFO scheduling algorithm
 *      not pre-emptive
 */

#include "../includes/scheduler_FIFO.h"

//this is a non - preemptive scheduler, set the preemptive member variable to false
//	//when calling the base class
//	Scheduler_FIFO(std::queue<PCB> &queue):Scheduler(queue,false,UNINITIALIZED){};
//	virtual ~Scheduler_FIFO(){};

//override base class behaviour if necessary, otherwise call it
bool Scheduler_FIFO::time_to_switch_processes(int tick_count, PCB &p) {
	return true;
}

//FIFO - not preemptive - no sorting needed
void Scheduler_FIFO::sort() {

}
