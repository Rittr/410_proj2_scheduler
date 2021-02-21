/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

#include "../includes/stats.h"

Stats::Stats(std::vector<PCB> &finished_vector) {
	vec = new std::vector<PCB>();
	*vec = finished_vector;

	calcStats();
}

//does the work (only needs to run once)
void Stats::calcStats() {
	float sum_response = 0;
	float sum_turnaround = 0;
	float sum_wait = 0;

	for (int i = 0; i < int(vec->size()); i++) {
		sum_response += vec->at(i).start_time - vec->at(i).arrival_time;
		sum_turnaround += vec->at(i).finish_time - vec->at(i).arrival_time;
		sum_wait += vec->at(i).finish_time - vec->at(i).arrival_time
				- vec->at(i).required_cpu_time;
	}

	av_response_time = sum_response / vec->size();
	av_turnaround_time = sum_turnaround / vec->size();
	av_wait_time = sum_wait / vec->size();
}

//loops thru vec, prints 1 line for each process using the following format
//Process 1 Required CPU time:2  arrived:0 started:0 finished:2
//if there are 10 processes in vector, should print 10 lines
void Stats::showAllProcessInfo() {
//	int p_num = 0;
	for (int i = 0; i < int(vec->size()); i++) {
//		PCB v = vec->at(i);
		std::cout << "Process " << vec->at(i).process_number
				<< " Required CPU time:" << vec->at(i).required_cpu_time
				<< " arrived:" << vec->at(i).arrival_time << " started:"
				<< vec->at(i).start_time << " finished:"
				<< vec->at(i).finish_time << std::endl;
	}
}

//after a process is placed in the ready_q, how long does
//it take before its placed on the processor?
//response_time per process = start_time - arrival_time
//this function returns the average over all processes
float Stats::get_av_response_time() {
	return av_response_time;
}

//after a process is placed in the ready_q, how long does
//it take to complete?
//turnaround time per process = finish_time - arrival_time
//this function returns the average over all processes
float Stats::get_av_turnaround_time() {
	return av_turnaround_time;
}

//after a process is placed in the ready_q, how much time does it
//spend waiting for processor time?
//wait time per process = finish_time - arrival_time-required_CPU_time
//this function returns the average over all processes
float Stats::get_av_wait_time() {
	return av_wait_time;
}

