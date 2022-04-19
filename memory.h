#ifndef MEMORY_H_
#define MEMORY_H_


unsigned char rom[0x8000];
unsigned char vram[0x2000];
unsigned char sram[0x2000];
unsigned char iram[0x2000];
unsigned char oam[0x100];
unsigned char io[0x4C];
unsigned char hram[0x80];


unsigned char read8(uint16_t address)
{
	if (address <= 0x7FFF) {
		return rom[address];
	}
	if (address >= 0x8000 && address <= 0x9FFF) {
		return vram[address - 0x8000];
	}
	if (address >= 0xA000 && address <= 0xBFFF) {
		return sram[address - 0xA000];
	}
	if (address >= 0xC000 && address <= 0xDFFF) {
		return iram[address - 0xC000];
	}
	if (address >= 0xFE00 && address <= 0xFE9F) {
		return oam[address - 0xFE00];
	}
	if (address >= 0xFF00 && address <= 0xFF4B) {
		return io[address - 0xFF00];
	}
	if (address >= 0xFF80 && address <= 0xFFFE) {
		return hram[address - 0xFF80];
	}
	//TODO: Implement all IO events depending on readbyte
	//TODO: Implement interrupts
	else {
		fprintf(stderr, "Tried to read byte in unaddressable area");
		exit(1);
	}
}
void write8(uint16_t address, unsigned char byte) {

	if (address <= 0x7FFF) {
		rom[address] = byte;
	}
	if (address >= 0x8000 && address <= 0x9FFF) {
		vram[address - 0x8000] = byte;
	}
	if (address >= 0xA000 && address <= 0xBFFF) {
		sram[address - 0xA000] = byte;
	}
	if (address >= 0xC000 && address <= 0xDFFF) {
		iram[address - 0xC000] = byte;
	}
	if (address >= 0xFE00 && address <= 0xFE9F) {
		oam[address - 0xFE00] = byte;
	}
	if (address >= 0xFF00 && address <= 0xFF4B) {
		io[address - 0xFF00] = byte;
	}
	if (address >= 0xFF80 && address <= 0xFFFE) {
		hram[address - 0xFF80] = byte;
	}
	//TODO: Implement all IO events depending on readbyte
	//TODO: Implement interrupts
	else {
		fprintf(stderr, "Tried to write in unaddressable area");
		exit(1);
	}
}
uint16_t read16(uint16_t address) 
{
	unsigned char lsb = read8(address);
	unsigned char msb = read8(address + 0x1);
	return (msb << 8) | lsb;
}
void write16(uint16_t address, uint16_t val)
{
	write8(address, (unsigned char) (val & 0xFF));
	write8(address + 0x1, (unsigned char) (val >> 8) & 0xFF);

}

#endif
