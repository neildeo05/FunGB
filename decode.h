#ifndef DECODE_H_
#define DECODE_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "registers.h"
#include "memory.h"
#include "opcodes.h"

//TODO: Change this from decode to execute, because decode step is not necessary when the instructions are so definite
Opcode
decode(unsigned char op) 
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
		// Load (BC) into a
		ret = (Opcode) {.type = OP_LD, .instruction="ld (bc), a", .length = 1};
		}
	}
	return ret;
}

#endif
