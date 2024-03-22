#pragma once
#include <stdio.h>
#define RECTANGLE_POINTS 4

// CSCN71020 - Group 3 - Winter 2024
// point ADT - interface

typedef struct point {
	int x;
	int y;
}POINT;

POINT CreatePoint(int, int);

void DisposePoint(POINT*);