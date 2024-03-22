#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<math.h>
#include "triangleSolver.h"
#define RADIANS 57.8
#define MAXCHAR 500
#define M_PI 3.1415

// CSCN71020 - Group 3 - Winter 2024
// triangleSolver ADT - implementation

//test branch
//Below is the function to get the cos of side1
float formulacos(int side1, int side2, int side3) {
	// Calculate squares
	if (side1 < 0 || side2 < 0 || side3 < 0) {
		return 0; 
	}
	else {
		float side1_squared = side1 * side1;
		float side2_squared = side2 * side2;
		float side3_squared = side3 * side3;

		// Calculate dividend and divisor
		float dividend = side2_squared + side3_squared - side1_squared;
		float divisor = 2 * side2 * side3;
		if (divisor == 0) {
			return 0; // Return 0 to avoid division by zero
		}
		// Calculate result
		float result = dividend / divisor;

		return result;
	}
}

// Takes all the inputted sides and checks to see what type of triangle it is
char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 > side2 && side1 > side3)
	{
		result = "Right angle triangle";
	}
	else if (side1 == side2 && side1 == side3) 
	{
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) ||
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else 
	{
		result = "Scalene triangle";
	}

	return result;
}

//Below is the function to find the interior triangle angles
char* findTriangleAngles(int side1, int side2, int side3) {
	//To solve this will use the formula c^2 = a^2 + b^2 - 2abcosC
	char* angles = malloc(MAXCHAR * sizeof(char));
	if (angles == NULL) {
		printf("Memory allocation failed.\n");
		return NULL;
	}

	// Calculate cosine of angles
	float cos1 = formulacos(side1, side2, side3);
	float cos2 = formulacos(side2, side3, side1);
	float cos3 = formulacos(side3, side1, side2);

	// Calculate angles in degrees
	float angle1 = acos(cos1) * 180.0 / M_PI;
	float angle2 = acos(cos2) * 180.0 / M_PI;
	float angle3 = acos(cos3) * 180.0 / M_PI;

	// Format angles into the output string
	snprintf(angles, MAXCHAR, "Angle 1: %.2f degrees, Angle 2: %.2f degrees, Angle 3: %.2f degrees", angle1, angle2, angle3);

	return angles;
}
