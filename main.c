#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "fetch.h"
#include "decode.h"
#include "opcodes.h"
#include "memory.h"



int main(void)
{
	unsigned char* rom = read_rom("copy.gb");

	regfile.pc = 0x100;
	unsigned char op = fetch(rom, &regfile.pc);
	//unsigned char op = 0x01;

	Opcode decoded_op = decode(op);
	printf("Instruction: %s, with length %d\n", decoded_op.instruction, decoded_op.length);

	free(rom);
}

