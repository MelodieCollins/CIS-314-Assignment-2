#include <stdio.h>

//return bit mask containing 1s for least-significant n [1,31] bits
unsigned int mask(int n){
	//create binary with all 1s
	unsigned int num = 0x0 - 1;
	//shift left by n 
	unsigned int shifted = num<< n;
	//mask is bitwise complement of shifted
	return ~shifted;
}

void main(){
	printf("mask(1): 0x%X\n", mask(1));
	printf("mask(2): 0x%X\n", mask(2));
	printf("mask(3): 0x%X\n", mask(3));
	printf("mask(5): 0x%X\n", mask(5));
	printf("mask(8): 0x%X\n", mask(8));
	printf("mask(16): 0x%X\n", mask(16));
	printf("mask(31): 0x%X\n", mask(31));
}
