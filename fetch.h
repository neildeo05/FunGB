#ifndef FETCH_H_
#define FETCH_H_
#include <stdio.h>
#include <stdlib.h>
// I like using unsigned char for bytes, and uint16_t for shorts cause it feels more semantic and cool for some reason
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
	*pc += 0x1;
	return ret;
}
#endif
