#ifndef FETCH_H_
#define FETCH_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

unsigned char* read_rom(char* filename)
{
	FILE* f = fopen(filename, "rb");
	fseek(f, 0, SEEK_END);
	size_t filelen = ftell(f);
	fseek(f, 0, SEEK_SET);
	
	unsigned char* buffer = malloc(filelen * sizeof(unsigned char));
	fread(buffer, filelen, 1, f);
	fclose(f);
	return buffer;
}

unsigned char fetch(unsigned char* rom, uint16_t* pc) 
{
	unsigned char ret = *(rom + *pc);
  // Increment PC by one, every time fetch is called. This functionallity should be placed outide of the fetch instruction, and the incrementation should depend on the cycle
	*pc += 0x1;
	return ret;
}
#endif
