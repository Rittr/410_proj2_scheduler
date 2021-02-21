/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

#include <algorithm>
#include <vector>
#include "../includes/scheduler_SRTF.h"

//this is a  preemptive scheduler, so set the preemptive member variable to true
//when calling the base class
//Scheduler::Scheduler_SRTF(std::queue<PCB> &queue){};
//virtual ~Scheduler_SRTF() {};

//override base class behaviour if necessary, otherwise call it
bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	return Scheduler::time_to_switch_processes(tick_count, p);
}

bool sortHelper(PCB a, PCB b) {
	return a.required_cpu_time < b.required_cpu_time;
}

//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
void Scheduler_SRTF::sort() {
	std::vector<PCB> process_vector;

	while (!ready_q->empty()) {
		process_vector.push_back(ready_q->front());
		ready_q->pop();
	}

	std::sort(process_vector.begin(), process_vector.end(), sortHelper);

	for (PCB process : process_vector) {
		ready_q->push(process);
	}
}
