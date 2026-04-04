#include <stdio.h>
#include "cpu.h"

int main(void){
	
	uint8_t commands[] = { NOP };
	printf("welcome \n");
	cpu_init();
		
	printf("init complete\n");
	cpu_load( commands , sizeof(commands));
	cpu_run();
	
}
