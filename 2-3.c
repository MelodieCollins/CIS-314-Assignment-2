#include <stdio.h>

int le(float x, float y){
	unsigned int ux = *((unsigned int*) &x); // convert x raw bits
	unsigned int uy = *((unsigned int*) &y); // convert y rraw bits
	unsigned int sx = ux >> 31; // extract sign bit of ux
	unsigned int sy = uy >> 31; // extract sign bit of uy
	ux <<= 1; // drop sign bit of ux
	uy <<= 1; // drop sign bit of uy

	// if x and y both negative and y <= x, return true
	// if x and y both positive and y >= x, return true
	// if x negative and y positive, return true
	// else, return false

	return (sx == 1 && sy == 1 && uy <= ux) || (sx == 0 && sy == 0 && uy >= ux) || (sx > sy);
}

void main(){
	printf("le(0.0f, 0.0f): %i\n", le(0.0f, 0.0f));
	printf("le(-0.0f, 0.0f): %i\n", le(-0.0f, 0.0f));
	printf("le(-1.0f, -1.0f): %i\n", le(-1.0f, -1.0f));
	printf("le(1.0f, 1.0f): %i\n", le(1.0f, 1.0f));
	printf("le(-1.0f, 0.0f): %i\n", le(-1.0f, 0.0f));
	printf("le(0.0f, 1.0f): %i\n", le(0.0f, 1.0f));
	printf("le(1.0f, 0.0f): %i\n", le(1.0f, 0.0f));
	printf("le(0.0f, -1.0f): %i\n", le(0.0f, -1.0f));
	printf("le(-1.0f, -2.0f): %i\n", le(-1.0f, -2.0f));
}
