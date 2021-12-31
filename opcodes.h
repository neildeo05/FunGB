#ifndef OPCODES_H_
#define OPCODES_H_

typedef enum {
  OP_NOP,
  OP_LD,
} OP_TYPE;

typedef struct {
  OP_TYPE type;
  char* instruction;
  unsigned char length;
	unsigned char byte;
} Opcode; 

#endif
