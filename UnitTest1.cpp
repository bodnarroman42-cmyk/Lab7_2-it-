#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void FindMaxInEvenRows(int** a, const int rowCount, const int colCount, int& maxVal)
{
	int i; 
	int j;
	bool found;

	found = false;

	
	for (i = 0; i < rowCount; i += 2)
	{
		for (j = 0; j < colCount; j++)
		{
			
			if (!found)
			{
				maxVal = a[i][j];
				found = true;
			}
			else if (a[i][j] > maxVal)
			{
			
				maxVal = a[i][j];
			}
		}
	}
}

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestFindMaxInEvenRows)
		{
	
			int rowCount = 3;
			int colCount = 3;
			int maxVal = 0;
			int** T;
			int i, j;

		
			T = new int* [rowCount];
			for (i = 0; i < rowCount; i++)
			{
				T[i] = new int[colCount];
			}

		
			T[0][0] = 2;
			T[0][1] = 5;
			T[0][2] = -1;

			T[1][0] = 99;
			T[1][1] = 99;
			T[1][2] = 99;

			T[2][0] = -3;
			T[2][1] = 8;
			T[2][2] = 1;

		
			FindMaxInEvenRows(T, rowCount, colCount, maxVal);

		
			Assert::AreEqual(maxVal, 8);

			for (i = 0; i < rowCount; i++)
			{
				delete[] T[i];
			}
			delete[] T;
		}
	};
}