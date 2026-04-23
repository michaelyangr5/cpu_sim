#include <stdio.h>
#include "cpu.h"

int main(void){
	
	uint8_t commands[] = { LOAD, 0, 5, LOAD, 1 , 1 , SUB, 0 ,1, JZ, 13, JMP, 6 , HLT };
	cpu_init();
	cpu_load( commands , sizeof(commands));
	cpu_run();
	printf("R0 = %d\n", cpu_get_register(0)); 		
}
