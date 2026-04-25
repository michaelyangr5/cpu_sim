#include "disassembler.h"
#include "cpu.h"
#include <stdio.h>
#include <stdint.h>
void disassemble(uint8_t *memory, uint8_t size){
	uint8_t i = 0;
	while ( i < size ){	
		switch(memory[i] ){
			case HLT :
				printf("[0x%02X] HALT \n" , i);
				i++;

				return;
			
			case NOP :
				printf("[0x%02X] NOP \n" , i);
				i++;

				break;

			case LOAD:
				printf("[0x%02X] LOAD R%d %d \n", i , memory[i+1] , memory[i+2]);
				i += 3;

				break;
			case STORE:
				printf("[0x%02X] STORE R%d %d \n", i , memory[i+1], memory[i+2]);
				i += 3;

				break;
			case ADD:
				printf("[0x%02X] ADD R%d R%d \n", i , memory[i+1], memory[i+2]);
				i += 3;

				break;
			case SUB:
				printf("[0x%02X] SUB R%d R%d \n", i , memory[i+1], memory[i+2]);
				i += 3;

				break;
			case ADC:
				printf("[0x%02X] ADC R%d R%d \n", i , memory[i+1], memory[i+2]);
				i += 3;

				break;
			case JMP:
				printf("[0x%02X] JMP 0x%02X \n", i , memory[i+1] );
				i += 2;

				break;
			case JZ:
				printf("[0x%02X] JZ 0x%02X \n", i , memory[i+1] );
				i += 2;
				
				break;
			default:
				return;
		}		
	}
}

