#include "point.h"

POINT CreatePoint(int x, int y) {
	POINT p = {0};
	p.x = x;
	p.y = y;
	return p;
}

void DisposePoint(POINT* point) {
	//nothing to be done here
}