/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */
#include <queue>
#include "../includes/scheduler.h"
#include "../includes/PCB.h"
//TODO fill in content

//add a process, either a new one or one that
//had been running on the CPU and has been preempted
void Scheduler::add(PCB p) {
	ready_q->push(p);
	sort();
}

//get next process
PCB Scheduler::getNext() {
//	if (!ready_q->empty()) {
	PCB first = ready_q->front();
	ready_q->pop();
	return first;
//	}
//	return PCB();
}

//returns true if there are no  jobs in the readyQ
//false otherwise
bool Scheduler::isEmpty() {
	return ready_q->empty();
}

//if process has completed (used all its remaining_cpu_time) or
//if we are using a preemptive scheduling algorithm and the
//timeslice is over then its time to switch processes
//returns:
//true - switch processes
//false - do not switch
bool Scheduler::time_to_switch_processes(int tick_count, PCB &p) {

//	if (p.remaining_cpu_time <= 0) {
//		return true;
//	}

	if (preemptive) {
		int total_time = p.required_cpu_time - p.remaining_cpu_time;
		int current_slice = total_time % time_slice;

		if (total_time > 0 && current_slice == 0) {
			return true;
		}
	}

	return p.remaining_cpu_time <= 0;
//	int relativeTick = 0;

//	if (preemptive && (tick_count - p.start_time % time_slice == 0)) {
//	if (preemptive
//			&& (p.required_cpu_time - p.remaining_cpu_time % time_slice == 0)) {
//		return true;
//	}

}
