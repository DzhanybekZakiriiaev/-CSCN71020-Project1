
#include <stdio.h>
#include<math.h>

//Below is the function to get the cos of side1
float formulacos(int side1, int side2, int side3) {
	//this will find cos(C) where c = side1
	float dividend = ((side2 ^ 2) + (side3 ^ 2) - (side1 ^ 2));
	float divisor = (2 * side2 * side3);
	float result = dividend / divisor;
	return result;
}