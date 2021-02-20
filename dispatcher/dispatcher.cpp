/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

#include "../includes/dispatcher.h"

//CPU *cpu; 	//this is initialized from a reference, it cannot be null
//bool is_valid_job_on_cpu; //set or reset according to whether  there is a job on the CPU

//Dispatcher::Dispatcher(CPU &cpu):cpu(&cpu),is_valid_job_on_cpu(false) {};

//pull current process (if any) off CPU and return it
//if nothing on CPU returns an uninitialized PCB
PCB Dispatcher::get_from_CPU(){
//	if (isValidJobOnCPU){
////		return cpu->current_Process;
//
//	}
//
//	return PCB();

	return cpu->get_process_off_core();
}

//place the current process on the CPU for execution
void Dispatcher::put_on_CPU(PCB &process){
	cpu->put_process_on_core(process);
}

//is CPU idle or working
bool Dispatcher::isValidJobOnCPU(){
	return (cpu->current_Process != NULL);
}
