#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"
#include "point.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"
int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			printf_s("% s\n", (findTriangleAngles(triangleSides[0], triangleSides[1], triangleSides[2])));
			break;
		case 2:
			printf_s("Rectangle selected.\n");
			POINT rectanglePoints[RECTANGLE_POINTS];
			getRectanglePoints(rectanglePoints);
			double area = 0.0;
			double perimeter = 0.0;
			if (isRectangle(rectanglePoints, &area, &perimeter)) {
				printf_s("Your figure is a rectangle.\n");
				printf_s("Your rectandles perimeter is: %lf\n", perimeter);
				printf_s("Your rectandles area is: %lf\n", area);
			}
			else {
				printf_s("Your figure is not a rectangle.\n");
				printf_s("Your shape's perimeter is: %lf\n", perimeter);
			}
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		if (scanf_s("%d", &triangleSides[i]) != 1) {
			exit(EXIT_FAILURE);
		}
	}
	return triangleSides;
}

void getRectanglePoints(POINT* points) {
	printf_s("Input for points in this format:\n");
	printf_s("Point#: x y\n");
	for (int i = 0; i < RECTANGLE_POINTS; i++) {
		printf_s("Point#%d: ", i+1);
		if (scanf_s("%d %d", &points[i].x, &points[i].y) != 2) {
			exit(EXIT_FAILURE);
		}
	}
}
