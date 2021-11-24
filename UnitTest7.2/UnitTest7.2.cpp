#include "pch.h"
#include "CppUnitTest.h"
#include "../7.2/7.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72
{
	TEST_CLASS(UnitTest72)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int rows = 2;
			const int cols = 2;
			int** array = new int*[rows];
			for (int j = 0; j < rows; j++) {
				array[j] = new int[cols];
			}
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++)
					array[i][j] = i + j;
			int s = min_elements_sum(array, rows, cols);
			Assert::AreEqual(s, 0);
		}
	};
}
