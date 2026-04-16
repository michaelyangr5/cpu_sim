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
	uint8_t address;
	uint8_t data;
	uint8_t reg;
	uint8_t reg_1;
	uint16_t result;
	int16_t sub_result;
	switch( opcode ){
		case HLT :
			return CPU_STOP;
		
		case NOP:	
			return CPU_RUNNING;
		
		case LOAD: 
			reg = cpu_fetch();
			data = cpu_fetch();
			cpu.registers[reg] = data;
			return CPU_RUNNING;
		

		case STORE: 
			reg = cpu_fetch();
			address = cpu_fetch();
			cpu.memory[address] = cpu.registers[reg];
			return CPU_RUNNING;
		

		case ADD: 
			reg = cpu_fetch();
			reg_1 = cpu_fetch();
			result = cpu.registers[reg]  + cpu.registers[reg_1];
			cpu.registers[reg] =(uint8_t) result;	
			
			if (result == 0)
    				cpu.flags |= FLAG_ZERO;
			else
    				cpu.flags &= ~FLAG_ZERO;
		
			if (result > 255)
				cpu.flags |= FLAG_CARRY;
			else
				cpu.flags &= ~FLAG_CARRY;
			
			return CPU_RUNNING;
		
		
		case SUB: 
			reg = cpu_fetch();
			reg_1 = cpu_fetch();
			sub_result = cpu.registers[reg]  - cpu.registers[reg_1];
			cpu.registers[reg] =(uint8_t) sub_result;	
	
			if (sub_result <  0 )
				cpu.flags |= FLAG_NEGATIVE;
			else
				cpu.flags &= ~FLAG_NEGATIVE;
			
			if (sub_result == 0)
    				cpu.flags |= FLAG_ZERO;
			else
    				cpu.flags &= ~FLAG_ZERO;
			return CPU_RUNNING;	
		
		case ADC:
			reg = cpu_fetch();
			reg_1 = cpu_fetch();
			result = cpu.registers[reg]  + cpu.registers[reg_1];
			cpu.registers[reg] =(uint8_t) result;	
			
			if (result == 0)
    				cpu.flags |= FLAG_ZERO;
			else
    				cpu.flags &= ~FLAG_ZERO;
		
			if (result > 255)
				cpu.flags |= FLAG_CARRY;
			else
				cpu.flags &= ~FLAG_CARRY;
			
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
