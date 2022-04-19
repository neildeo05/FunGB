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
      ret = (Opcode) {.type=OP_LD, .instruction="ld bc, %d", .length = 2};
      // Execute:
      regfile.bc = fetch(rom, &regfile.pc);
      dump(&regfile);
      break;
		}
		case 0x02:
		{
      // Load value of register a into the memory address specified by bc
      ret = (Opcode) {.type = OP_LD, .instruction="ld (bc), a", .length = 1};
      printf("%x\n", fetch(rom, &regfile.pc));
      // Execute:
      write8(regfile.bc, regfile.a);
      break;
		}
    case 0x03:
    {
      ret = (Opcode) {.type = OP_INC, .instruction="inc bc", .length = 1};
      regfile.bc++;
      break;
    }
    case 0xc3: 
    {
      ret = (Opcode) {.type = OP_JP, .instruction="jp %d", .length=3};
      unsigned char lsb = fetch(rom, &regfile.pc);
      unsigned char msb = fetch(rom, &regfile.pc);
      uint16_t addr = (msb << 8) | lsb;
      printf("Address => %x\n", addr);
      regfile.pc = addr;
      break;
    }
    case 0xaf:
    {
      //Technically also an NOP instruction
      ret = (Opcode) {.type = OP_NOP, .instruction="ld a, a", .length=1};
      break;
    }
    default: 
    {
      fprintf(stderr, "Instruction %x is not implemented yet\n", op);
      exit(1);
    }
	}
	return ret;
}

#endif
