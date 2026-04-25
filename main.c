#include <stdio.h>
#include "cpu.h"
#include "disassembler.h"
int main(void){
	
	uint8_t commands[] = { LOAD, 0, 5, LOAD, 1 , 1 , SUB, 0 ,1, JZ, 13, JMP, 6 , HLT };
	cpu_init();
	cpu_load( commands , sizeof(commands));
	disassemble( commands , sizeof(commands));
	cpu_run(); 		
}
