#ifndef CPU_H
#define CPU_H

#include <stdint.h>

#define NUMBER_REGISTERS 8

#define MAX_MEM 256

typedef enum { CPU_STOP , CPU_RUNNING } STATE;

typedef enum { HLT , NOP , LOAD , STORE , ADD , SUB , JMP , JZ   }OP;
typedef struct{
	
	uint8_t	registers[NUMBER_REGISTERS];
	uint8_t memory[MAX_MEM];
	uint8_t program_counter;
	uint8_t flags;	

}CPU;

void cpu_init(void);
void cpu_load(uint8_t *commands , uint8_t size);
void print_allmem(void);
uint8_t cpu_fetch(void);
STATE cpu_execute (uint8_t opcode);
void cpu_run(void);

#endif
