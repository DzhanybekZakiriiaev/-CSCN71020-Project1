#include "point.h"

// CSCN71020 - Group 3 - Winter 2024
// point ADT - implementation

POINT CreatePoint(int x, int y) {
	POINT p = {0};
	p.x = x;
	p.y = y;
	return p;
}

void DisposePoint(POINT* point) {
	//nothing to be done here
}