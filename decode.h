#ifndef DECODE_H_
#define DECODE_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "registers.h"
#include "memory.h"
#include "opcodes.h"
#include "fetch.h"

//TODO: Change this from decode to execute, because decode step is not necessary when the instructions are so definite
// Return the opcode for debugging purposes
// Execute based on the opcode
Opcode
decode_and_execute(unsigned char op, unsigned char* rom) 
{
	Opcode ret = {0};
	switch(op) {
		case 0x00:
		{
		//NOP
			ret = (Opcode) {.type=OP_NOP, .instruction="nop", .length = 1, .byte=0x00};
			break;
		}
		case 0x01:
		{
		// Load u16 into register BC
      ret = (Opcode) {.type=OP_LD, .instruction="ld bc, %d", .length = 2, .byte = 0x01};
      break;
		}
		case 0x02:
		{
      ret = (Opcode) {.type = OP_LD, .instruction="ld (bc), a", .length = 1, .byte=0x02};
      printf("%x\n", fetch(rom, &regfile.pc));
      break;
		}
    case 0x03:
    {
      ret = (Opcode) {.type = OP_INC, .instruction="inc bc", .length = 1};
      break;
    }
	}
	return ret;
}

#endif
