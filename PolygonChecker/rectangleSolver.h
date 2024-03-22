#pragma once
#include <stdio.h>
#include "point.h"
#include <stdbool.h>

// CSCN71020 - Group 3 - Winter 2024
// rectangleSolver ADT - interface

double getLength(POINT, POINT);

bool isRectangle(POINT* points, double* area, double* perimeter);

bool isPerpendicular(POINT vectorOne, POINT vectorTwo);

POINT getVector(POINT pointOne, POINT pointTwo);