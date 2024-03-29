#include "pch.h"
#include "CppUnitTest.h"
#include <stdbool.h>

typedef struct point {
	int x;
	int y;
}POINT;

extern "C" double getLength(POINT, POINT);
extern "C" POINT CreatePoint(int x, int y);
extern "C" bool isRectangle(POINT * points, double* area, double* perimeter);
extern "C" bool isPerpendicular(POINT vectorOne, POINT vectorTwo);
extern "C" POINT getVector(POINT pointOne, POINT pointTwo);
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleUnitTest
{
	TEST_CLASS(RectangleUnitTest)
	{
	public:
		
		TEST_METHOD(GetLengthTest)
		{


			POINT p1;
			p1.x = 1;
			p1.y = 6;

			POINT p2;
			p2.x = 6;
			p2.y = 6;
			int result = getLength(p1 , p2);

			Assert::AreEqual(5, result);
			//this will pass
		}
		TEST_METHOD(IsRectangleTest) {
			POINT* p;
			POINT p1, p2, p3, p4;

			p1.x = 1;
			p1.y = 6;
			p2.x = 6;
			p2.y = 6;
			p3.x = 1;
			p3.y = 4;
			p4.x = 6;
			p4.y = 4;

			POINT points[4] = { p1 ,p2 ,p3 ,p4 };

			p = &points[0];
			

			bool result;

			result = isRectangle(p, 0, 0);
			Assert::AreEqual(true, result);
		}
		TEST_METHOD(isPerpendicularTest) {
			POINT vx, vy, p1, p2;
			p1.x = 1;
			p1.y = 6;
			p2.x = 6;
			p2.y = 4;
			vx.x = p1.x - p2.x;
			vy.y = p1.y - p2.y;
			bool result;
			result = isPerpendicular(vx, vy);
			Assert::AreEqual(true, result);
		}
		TEST_METHOD(getVectorTest) {
			bool actual;
			POINT p1, p2, vector;
			p1.x = 1;
			p1.y = 6;
			p2.x = 6;
			p2.y = 4;
			int expectedx = 5, expectedy = -2;
			 vector = getVector(p1, p2);
			 if (vector.x == expectedx && vector.y == expectedy) {
				 actual = true;
			}
			 else {
				 actual = false;
			 }
			 Assert::AreEqual(true, actual);
		}

	};
}
