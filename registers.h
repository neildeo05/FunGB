#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef struct {
	union {
		struct{
			uint8_t f;
			uint8_t a;
		};
		uint16_t af;
	};

	union {
		struct{
			uint8_t c;
			uint8_t b;
		};
		uint16_t bc;
	};
	union {
		struct{
			uint8_t e;
			uint8_t d;
		};
		uint16_t de;
	};
	union {
		struct{
			uint8_t l;
			uint8_t h;
		};
		uint16_t hl;
	};
	uint16_t sp;
	uint16_t pc;
} regfile_t;

void dump(regfile_t* regfile) 
{
	printf("a: %x, f = %x, af = %02x\n", regfile->a, regfile->f, regfile->af);
	printf("b: %x, c = %x, bc = %02x\n", regfile->b, regfile->c, regfile->bc);
	printf("d: %x, e = %x, de = %02x\n", regfile->d, regfile->e, regfile->de);
	printf("h: %x, l = %x, hl = %02x\n", regfile->h, regfile->l, regfile->hl);
	printf("sp: %x\n", regfile->sp);
	printf("pc: %x\n", regfile->pc);
}
regfile_t regfile;

