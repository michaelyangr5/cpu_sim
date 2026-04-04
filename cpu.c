#include "cpu.h"
#include <string.h>
#include <stdio.h>
static CPU cpu;

void cpu_init(void){

	memset(cpu.registers , 0 , sizeof(cpu.registers));
	memset(cpu.memory , 0 , sizeof(cpu.memory));
	cpu.program_counter = 0;
	cpu.flags = 0;

}

void cpu_load(uint8_t *commands , uint8_t size){
	memcpy(cpu.memory , commands , size);
}

void print_allmem(void){
	for(uint16_t i = 0 ; i < MAX_MEM ; i++ ){
		printf("[%d] = %d \n", i , cpu.memory[i]);
	}
}


uint8_t cpu_fetch(void){
	return cpu.memory[cpu.program_counter++];
}

STATE cpu_execute (uint8_t opcode) {
	
	switch( opcode ){
		case HLT :
			return CPU_STOP;
		
		case NOP:	
			return CPU_RUNNING;
	default :
		return CPU_RUNNING;
	}
	
}

void cpu_run(void){
	while(1){

	if(cpu_execute(cpu_fetch()) == CPU_STOP)
		break;
	}
	
}
