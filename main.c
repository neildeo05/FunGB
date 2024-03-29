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
  //Arbitrary 0x100 address, but should jump to FFFC and FFFD to see exactly where to read (from Ben Eater's 65c02 videos)
	regfile.pc = 0x100;
  unsigned int program_size = 10;
  unsigned char op;
  for(int i = 0; i < program_size; i++){
    op = fetch(rom, &regfile.pc);
    Opcode decoded_op = decode_and_execute(op, rom);

    printf("Instruction: %s, with length %d\n", decoded_op.instruction, decoded_op.length);
  }

	free(rom);
}



//TODO: Add suport for loading roms in browser using WebAssembly
