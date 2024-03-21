#include <stdio.h>
#include <stdbool.h>
#include "point.h"
#include "math.h"

int maximum(int a, int b) {
    return (a > b) ? a : b;
}


double getLength(POINT pointOne, POINT pointTwo) {
	int xDifference = pointOne.x - pointTwo.x;
	int yDifference = pointOne.y - pointTwo.y;
	double length = sqrt((xDifference * xDifference) + (yDifference * yDifference));
	return length;
}

bool isPerpendicular(POINT vectorOne, POINT vectorTwo) {
    return (vectorOne.x * vectorTwo.x + vectorOne.y * vectorTwo.y) == 0;
}

POINT getVector(POINT pointOne, POINT pointTwo) {
    POINT vector;
    vector.x = pointTwo.x - pointOne.x;
    vector.y = pointTwo.y - pointOne.y;
    return vector;
}

void isRectangle(POINT* points) {
    bool isRectangle;
    int maxX = points[0].x, maxY = points[0].y;
    POINT p[RECTANGLE_POINTS];
    for (int i = 0; i < RECTANGLE_POINTS; i++) {
        maxX = maximum(maxX, points[i].x);
        maxY = maximum(maxY, points[i].y);
    }
    for (int i = 0; i < RECTANGLE_POINTS; i++) {
        if (points[i].x < maxX && points[i].y >= maxY) 
            p[0] = points[i];
        else if (points[i].x >= maxX && points[i].y >= maxY) 
            p[1] = points[i];
        else if (points[i].x < maxX && points[i].y < maxY) 
            p[2] = points[i];
        else if (points[i].x >= maxX && points[i].y < maxY) 
            p[3] = points[i];
    }
    double side[RECTANGLE_POINTS];
    double diagonal[2];
    side[0] = getLength(p[0], p[1]);
    side[1] = getLength(p[1], p[3]);
    side[2] = getLength(p[3], p[2]);
    side[3] = getLength(p[2], p[0]);
    diagonal[0] = getLength(p[0], p[2]);
    diagonal[1] = getLength(p[1], p[3]);

    POINT vectors[RECTANGLE_POINTS];
    vectors[0] = getVector(p[0], p[1]);
    vectors[1] = getVector(p[1], p[3]);
    vectors[2] = getVector(p[3], p[2]);
    vectors[3] = getVector(p[2], p[0]);
    bool perpendicular = isPerpendicular(vectors[0], vectors[1]) &&
                         isPerpendicular(vectors[1], vectors[2]) &&
                         isPerpendicular(vectors[2], vectors[3]) &&
                         isPerpendicular(vectors[3], vectors[0]);
    double perimeter = side[0] + side[1] + side[2] + side[3];
    if (perpendicular && (side[0] == side[2]) && (side[1] == side[3]) && (diagonal[0] == diagonal[1])) {
        printf_s("Your figure is a rectangle.\n");
        double area = side[0] * side[1];
        printf_s("Your rectandles perimeter is: %lf\n", perimeter);
        printf_s("Your rectandles area is: %lf\n", area);
    }
    else {
        printf_s("Your figure is not a rectangle.\n");
        printf_s("Your shape's perimeter is: %lf\n", perimeter);
    }
}
