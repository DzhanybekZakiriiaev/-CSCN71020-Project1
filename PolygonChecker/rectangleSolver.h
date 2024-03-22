#pragma once
#include <stdio.h>
#include "point.h"
#include <stdbool.h>

double getLength(POINT, POINT);

bool isRectangle(POINT* points, double* area, double* perimeter);

bool isPerpendicular(POINT vectorOne, POINT vectorTwo);

POINT getVector(POINT pointOne, POINT pointTwo);