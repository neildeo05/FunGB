#ifndef OPCODES_H_
#define OPCODES_H_

//TODO: More opcodes to be implemented from 6502
typedef enum {
  OP_NOP,
  OP_LD,
  OP_INC,
  OP_JP,
} OP_TYPE;

typedef struct {
  OP_TYPE type;
  char* instruction;
  unsigned char length;
	unsigned char byte;
} Opcode; 

#endif
