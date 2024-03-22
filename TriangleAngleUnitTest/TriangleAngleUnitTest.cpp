#include "pch.h"
#include "CppUnitTest.h"
#define MAXANGLEARRAY 3
#define _CRT_SECURE_NO_WARNINGS

// CSCN71020 - Group 3 - Winter 2024
// TriangleAngleUnitTest ADT - implementation

extern "C" float formulacos(int side1, int side2, int side3);
extern "C" char* findTriangleAngles(int side1, int side2, int side3);
//These unit tests will test the functionality of the triangle angle finder
//and the cosine formula functions.
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TriangleAngleUnitTest
{
	TEST_CLASS(COSINEFORMULAFUNCTIONT_TESTS)
	{
	public:

		TEST_METHOD(FORMULATEST_POSITIVEINT)
		{
			//This tests whether the function correctly finds
			//cos when given positive integers
			float result;
			int side1 = 5;
			int side2 = 5;
			int side3 = 5;
			result = formulacos(side1, side2, side3);
			float expected = 0.5;
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(FORMULATEST_UNEQUALIT)
		{
			//This tests whether the function correctly finds
			//cos when given positive integers
			float result;
			int side1 = 4;
			int side2 = 7;
			int side3 = 9;
			result = formulacos(side1, side2, side3);
			//This is to lmiit the result to one decimal place
			float rounded_result = round(result * 10) / 10;
			float expected = 0.9;
			Assert::AreEqual(expected, rounded_result);
		}
		TEST_METHOD(FORMULATEST_NEGATIVE)
		{
			//This tests whether the function correctly finds
			//cos when given positive integers
			float result;
			int side1 = -4;
			int side2 = -7;
			int side3 = -9;
			result = formulacos(side1, side2, side3);
			float expected = 0;
			Assert::AreEqual(expected, result);
		}
	};
	TEST_CLASS(GETANGLESFUNCTIONTEST)
	{
	public:
		TEST_METHOD(GETANGLESEQUILATERALTEST)
		{
			int side1 = 5;
			int side2 = 5;
			int side3 = 5;
			char* result = findTriangleAngles(side1, side2, side3);

			// Expected result for an equilateral triangle
			const char* expected = "Angle 1: 60.00 degrees, Angle 2: 60.00 degrees, Angle 3: 60.00 degrees";

			// Compare strings character by character
			bool equal = true;
			for (int i = 0; expected[i] != '\0' && result[i] != '\0'; ++i) {
				if (expected[i] != result[i]) {
					equal = false;
					break;
				}
			}

			Assert::IsTrue(equal); // Assert if the strings are equal
		}

		TEST_METHOD(GETANGLESSCALENE)
		{
			int side1 = 4;
			int side2 = 7;
			int side3 = 9;
			char* result = findTriangleAngles(side1, side2, side3);

			// Expected result for a scalene triangle
			const char* expected = "Angle 1: 25.21 degrees, Angle 2: 48.19 degrees, Angle 3: 106.60 degrees";

			// Compare strings character by character
			bool equal = true;
			for (int i = 0; expected[i] != '\0' && result[i] != '\0'; ++i) {
				if (expected[i] != result[i]) {
					equal = false;
					break;
				}
			}

			Assert::IsTrue(equal); // Assert if the strings are equal
		}
			TEST_METHOD(GETANGLESISOSCELES) 
		{
			int side1 = 5;
			int side2 = 5;
			int side3 = 8; // Modify one side to make it different from the other two
			char* result = findTriangleAngles(side1, side2, side3);

			// Expected result for an isosceles triangle
			const char* expected = "Angle 1: 36.87 degrees, Angle 2: 36.87 degrees, Angle 3: 106.26 degrees"; 

			// Compare strings character by character
			bool equal = true;
			for (int i = 0; expected[i] != '\0' && result[i] != '\0'; ++i) {
				if (expected[i] != result[i]) {
					equal = false;
					break;
				}
			}

			Assert::IsTrue(equal); // Assert if the strings are equal
		}
	};
}




