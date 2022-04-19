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
  unsigned int loop_tracker = 0;
  unsigned char op;
  for(;;){
    op = fetch(rom, &regfile.pc);
    Opcode decoded_op = decode_and_execute(op, rom);
    printf("Instruction: %s, with length %d\n", decoded_op.instruction, decoded_op.length);
    if (loop_tracker == 10) break;
    loop_tracker++;
  }

	free(rom);
}

