#pragma once
#include <stdio.h>
#define RECTANGLE_POINTS 4
typedef struct point {
	int x;
	int y;
}POINT;

POINT CreatePoint(int, int);

void DisposePoint(POINT*);