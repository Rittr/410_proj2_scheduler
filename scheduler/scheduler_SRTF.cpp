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
#include "../includes/scheduler_SRTF.h"

//override base class behavior if necessary, otherwise call it
bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {

	if (ready_q->front().remaining_cpu_time > 0
			&& ready_q->front().remaining_cpu_time < p.remaining_cpu_time) {
		return true;
	}

	return Scheduler::time_to_switch_processes(tick_count, p);
}

//helper function to sort PCB's by required CPU time
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
