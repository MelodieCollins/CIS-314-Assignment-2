#include <stdio.h>

unsigned int extract(unsigned int x, int i){
	//shift byte i to rightmost position
	unsigned int shifted = x >> (i<< 3);
	//isolate shifted byte i
	unsigned int isolated = shifted & 0xFF;
	//mask against 0x80 to see if leftmost binary is 1 (negative)
	unsigned int leftmost = isolated & 0x80;
	//shift right and subtract 1
	unsigned int leftmostShifted = leftmost >> 7;
	//mask rightmost for sign extension
	unsigned int mask = ~(leftmostShifted - 1);
	//clear spot for isolated byte i
	unsigned int cleared = mask & 0xFFFFFF00;
	//combine sign extension and byte i
	unsigned int combined = cleared | isolated;
	return combined;
}

void main(){
	printf("extract(0x12345678, 0): 0x%08X\n", extract(0x12345678, 0));
	printf("extract(0xABCDEF00, 2): 0x%08X\n", extract(0xABCDEF00, 2));
}
