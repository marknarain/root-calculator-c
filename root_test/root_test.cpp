#include "CppUnitTest.h"
#include "../root_c/root.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace roottest
{
	TEST_CLASS(splitNumberTest)
	{
	public:
		
		TEST_METHOD(splitNumberTest1)
		{
			int* p = splitNumber("0");			
			Assert::IsNotNull(p);
			Assert::AreEqual(p[0], 1);
			Assert::AreEqual(p[1], 0);
		}

		TEST_METHOD(splitNumberTest2)
		{
			int* p = splitNumber("1");
			Assert::IsNotNull(p);
			Assert::AreEqual(p[0], 1);
			Assert::AreEqual(p[1], 1);
		}

		TEST_METHOD(splitNumberTest3)
		{
			int* p = splitNumber("12");
			Assert::IsNotNull(p);
			Assert::AreEqual(p[0], 1);
			Assert::AreEqual(p[1], 12);
		}

		TEST_METHOD(splitNumberTest4)
		{
			int* p = splitNumber("123");
			Assert::IsNotNull(p);
			Assert::AreEqual(p[0], 2);
			Assert::AreEqual(p[1], 1);
			Assert::AreEqual(p[2], 23);
		}

		TEST_METHOD(splitNumberTest5)
		{
			int* p = splitNumber("1234");
			Assert::IsNotNull(p);
			Assert::AreEqual(p[0], 2);
			Assert::AreEqual(p[1], 12);
			Assert::AreEqual(p[2], 34);
		}

		TEST_METHOD(splitNumberTest6)
		{
			int* p = splitNumber("12345");
			Assert::IsNotNull(p);
			Assert::AreEqual(p[0], 3);
			Assert::AreEqual(p[1], 1);
			Assert::AreEqual(p[2], 23);
			Assert::AreEqual(p[3], 45);
		}

		TEST_METHOD(splitNumberTest7)
		{
			int* p = splitNumber("123456");
			Assert::IsNotNull(p);
			Assert::AreEqual(p[0], 3);
			Assert::AreEqual(p[1], 12);
			Assert::AreEqual(p[2], 34);
			Assert::AreEqual(p[3], 56);
		}

		TEST_METHOD(splitNumberTest8)
		{
			int* p = splitNumber("1234567");
			Assert::IsNotNull(p);
			Assert::AreEqual(p[0], 4);
			Assert::AreEqual(p[1], 1);
			Assert::AreEqual(p[2], 23);
			Assert::AreEqual(p[3], 45);
			Assert::AreEqual(p[4], 67);
		}

		TEST_METHOD(splitNumberTest_invalidCharacters)
		{
			int* p = splitNumber("as34567");
			Assert::IsNull(p);
			p = splitNumber("as3456");
			Assert::IsNull(p);
			p = splitNumber("34567as");
			Assert::IsNull(p);
			p = splitNumber("4567as");
			Assert::IsNull(p);
		}

	};
	TEST_CLASS(rootOfFirstItemTest)
	{
	public:

		TEST_METHOD(rootOfFirstItemTest1)
		{
			int testOut = rootOfFirstItem(84);
			Assert::AreEqual(9, testOut);
		}

		TEST_METHOD(rootOfFirstItemTest2)
		{
			int testOut = rootOfFirstItem(35);
			Assert::AreEqual(5, testOut);
		}

		TEST_METHOD(rootOfFirstItemTest3)
		{
			int testOut = rootOfFirstItem(48);
			Assert::AreEqual(6, testOut);
		}

		TEST_METHOD(rootOfFirstItemTest4)
		{
			int testOut = rootOfFirstItem(10);
			Assert::AreEqual(3, testOut);
		}
	};
	TEST_CLASS(rootDigitCalculatorTest)
	{
	public:

		TEST_METHOD(rootDigitCalculatorTest1)
		{
			int testOut = rootDigitCalculator(800, 8);
			Assert::AreEqual(4, testOut);
		}

		TEST_METHOD(rootDigitCalculatorTest2)
		{
			int testOut = rootDigitCalculator(700, 8);
			Assert::AreEqual(4, testOut);
		}

		TEST_METHOD(rootDigitCalculatorTest3)
		{
			int testOut = rootDigitCalculator(600, 8);
			Assert::AreEqual(3, testOut);
		}
	};
	TEST_CLASS(rootTest)
	{
	public:

		TEST_METHOD(rootTest1)
		{
			int* testOut = root("123", 7);
			Assert::IsNotNull(testOut);
			Assert::AreEqual(10, testOut[0]);
			Assert::AreEqual(3, testOut[1]);
			Assert::AreEqual(1, testOut[2]);
			Assert::AreEqual(1, testOut[3]);
			Assert::AreEqual(0, testOut[4]);
			Assert::AreEqual(9, testOut[5]);
			Assert::AreEqual(0, testOut[6]);
			Assert::AreEqual(5, testOut[7]);
			Assert::AreEqual(3, testOut[8]);
			Assert::AreEqual(6, testOut[9]);
			Assert::AreEqual(5, testOut[10]);
		}

		TEST_METHOD(rootTest2)
		{
			int* testOut = root("123", 6);
			Assert::IsNotNull(testOut);
			Assert::AreEqual(9, testOut[0]);
			Assert::AreEqual(3, testOut[1]);
			Assert::AreEqual(1, testOut[2]);
			Assert::AreEqual(1, testOut[3]);
			Assert::AreEqual(0, testOut[4]);
			Assert::AreEqual(9, testOut[5]);
			Assert::AreEqual(0, testOut[6]);
			Assert::AreEqual(5, testOut[7]);
			Assert::AreEqual(3, testOut[8]);
			Assert::AreEqual(6, testOut[9]);
		}

		TEST_METHOD(rootTest3)
		{
			int* testOut = root("123", 5);
			Assert::IsNotNull(testOut);
			Assert::AreEqual(8, testOut[0]);
			Assert::AreEqual(3, testOut[1]);
			Assert::AreEqual(1, testOut[2]);
			Assert::AreEqual(1, testOut[3]);
			Assert::AreEqual(0, testOut[4]);
			Assert::AreEqual(9, testOut[5]);
			Assert::AreEqual(0, testOut[6]);
			Assert::AreEqual(5, testOut[7]);
			Assert::AreEqual(3, testOut[8]);
		}

		TEST_METHOD(rootTest4)
		{
			int* testOut = root("123", 4);
			Assert::IsNotNull(testOut);
			Assert::AreEqual(7, testOut[0]);
			Assert::AreEqual(3, testOut[1]);
			Assert::AreEqual(1, testOut[2]);
			Assert::AreEqual(1, testOut[3]);
			Assert::AreEqual(0, testOut[4]);
			Assert::AreEqual(9, testOut[5]);
			Assert::AreEqual(0, testOut[6]);
			Assert::AreEqual(5, testOut[7]);
		}
#
		TEST_METHOD(rootTest5)
		{
			int* testOut = root("123", 3);
			Assert::IsNotNull(testOut);
			Assert::AreEqual(6, testOut[0]);
			Assert::AreEqual(3, testOut[1]);
			Assert::AreEqual(1, testOut[2]);
			Assert::AreEqual(1, testOut[3]);
			Assert::AreEqual(0, testOut[4]);
			Assert::AreEqual(9, testOut[5]);
			Assert::AreEqual(0, testOut[6]);
		}

		TEST_METHOD(rootTest6)
		{
			int* testOut = root("123", 2);
			Assert::IsNotNull(testOut);
			Assert::AreEqual(5, testOut[0]);
			Assert::AreEqual(3, testOut[1]);
			Assert::AreEqual(1, testOut[2]);
			Assert::AreEqual(1, testOut[3]);
			Assert::AreEqual(0, testOut[4]);
			Assert::AreEqual(9, testOut[5]);
		}

		TEST_METHOD(rootTest7)
		{
			int* testOut = root("123", 1);
			Assert::IsNotNull(testOut);
			Assert::AreEqual(4, testOut[0]);
			Assert::AreEqual(3, testOut[1]);
			Assert::AreEqual(1, testOut[2]);
			Assert::AreEqual(1, testOut[3]);
			Assert::AreEqual(0, testOut[4]);
		}

		TEST_METHOD(rootTest8)
		{
			int* testOut = root("123", 0);
			Assert::IsNotNull(testOut);
			Assert::AreEqual(3, testOut[0]);
			Assert::AreEqual(3, testOut[1]);
			Assert::AreEqual(1, testOut[2]);
			Assert::AreEqual(1, testOut[3]);
		}

		TEST_METHOD(rootTest9)
		{
			int* testOut = root("2", 8);
			Assert::IsNotNull(testOut);
			Assert::AreEqual(10, testOut[0]);
			Assert::AreEqual(2, testOut[1]);
			Assert::AreEqual(1, testOut[2]);
			Assert::AreEqual(4, testOut[3]);
			Assert::AreEqual(1, testOut[4]);
			Assert::AreEqual(4, testOut[5]);
			Assert::AreEqual(2, testOut[6]);
			Assert::AreEqual(1, testOut[7]);
			Assert::AreEqual(3, testOut[8]);
			Assert::AreEqual(5, testOut[9]);
			Assert::AreEqual(6, testOut[10]);
		}
		
		TEST_METHOD(rootTest10)
		{
			int* testOut = root("2", 7);
			Assert::IsNotNull(testOut);
			Assert::AreEqual(9, testOut[0]);
			Assert::AreEqual(2, testOut[1]);
			Assert::AreEqual(1, testOut[2]);
			Assert::AreEqual(4, testOut[3]);
			Assert::AreEqual(1, testOut[4]);
			Assert::AreEqual(4, testOut[5]);
			Assert::AreEqual(2, testOut[6]);
			Assert::AreEqual(1, testOut[7]);
			Assert::AreEqual(3, testOut[8]);
			Assert::AreEqual(5, testOut[9]);
		}

		TEST_METHOD(rootTest11)
		{
			int* testOut = root("2", 6);
			Assert::IsNotNull(testOut);
			Assert::AreEqual(8, testOut[0]);
			Assert::AreEqual(2, testOut[1]);
			Assert::AreEqual(1, testOut[2]);
			Assert::AreEqual(4, testOut[3]);
			Assert::AreEqual(1, testOut[4]);
			Assert::AreEqual(4, testOut[5]);
			Assert::AreEqual(2, testOut[6]);
			Assert::AreEqual(1, testOut[7]);
			Assert::AreEqual(3, testOut[8]);
		}

		TEST_METHOD(rootTest12)
		{
			int* testOut = root("2", 5);
			Assert::IsNotNull(testOut);
			Assert::AreEqual(7, testOut[0]);
			Assert::AreEqual(2, testOut[1]);
			Assert::AreEqual(1, testOut[2]);
			Assert::AreEqual(4, testOut[3]);
			Assert::AreEqual(1, testOut[4]);
			Assert::AreEqual(4, testOut[5]);
			Assert::AreEqual(2, testOut[6]);
			Assert::AreEqual(1, testOut[7]);
		}

		TEST_METHOD(rootTest13)
		{
			int* testOut = root("2", 4);
			Assert::IsNotNull(testOut);
			Assert::AreEqual(6, testOut[0]);
			Assert::AreEqual(2, testOut[1]);
			Assert::AreEqual(1, testOut[2]);
			Assert::AreEqual(4, testOut[3]);
			Assert::AreEqual(1, testOut[4]);
			Assert::AreEqual(4, testOut[5]);
			Assert::AreEqual(2, testOut[6]);
		}

		TEST_METHOD(rootTest14)
		{
			int* testOut = root("2", 3);
			Assert::IsNotNull(testOut);
			Assert::AreEqual(5, testOut[0]);
			Assert::AreEqual(2, testOut[1]);
			Assert::AreEqual(1, testOut[2]);
			Assert::AreEqual(4, testOut[3]);
			Assert::AreEqual(1, testOut[4]);
			Assert::AreEqual(4, testOut[5]);
		}

		TEST_METHOD(rootTest15)
		{
			int* testOut = root("2", 2);
			Assert::IsNotNull(testOut);
			Assert::AreEqual(4, testOut[0]);
			Assert::AreEqual(2, testOut[1]);
			Assert::AreEqual(1, testOut[2]);
			Assert::AreEqual(4, testOut[3]);
			Assert::AreEqual(1, testOut[4]);
		}

		TEST_METHOD(rootTest16)
		{
			int* testOut = root("2", 1);
			Assert::IsNotNull(testOut);
			Assert::AreEqual(3, testOut[0]);
			Assert::AreEqual(2, testOut[1]);
			Assert::AreEqual(1, testOut[2]);
			Assert::AreEqual(4, testOut[3]);
		}

		TEST_METHOD(rootTest17)
		{
			int* testOut = root("2", 0);
			Assert::IsNotNull(testOut);
			Assert::AreEqual(2, testOut[0]);
			Assert::AreEqual(2, testOut[1]);
			Assert::AreEqual(1, testOut[2]);
		}

		TEST_METHOD(rootTest18)
		{
			int* testOut = root("100", 7);
			Assert::IsNotNull(testOut);
			Assert::AreEqual(3, testOut[0]);
			Assert::AreEqual(3, testOut[1]);
			Assert::AreEqual(1, testOut[2]);
			Assert::AreEqual(0, testOut[3]);
		}

		TEST_METHOD(rootTest19)
		{
			int* testOut = root("4", 7);
			Assert::IsNotNull(testOut);
			Assert::AreEqual(2, testOut[0]);
			Assert::AreEqual(2, testOut[1]);
			Assert::AreEqual(2, testOut[2]);
		}

		TEST_METHOD(rootTest20)
		{
			//31622,776
			int* testOut = root("999999999", 3);
			Assert::IsNotNull(testOut);
			Assert::AreEqual(9, testOut[0]);
			Assert::AreEqual(6, testOut[1]);
			Assert::AreEqual(3, testOut[2]);
			Assert::AreEqual(1, testOut[3]);
			Assert::AreEqual(6, testOut[4]);
			Assert::AreEqual(2, testOut[5]);
			Assert::AreEqual(2, testOut[6]);
			Assert::AreEqual(7, testOut[7]);
			Assert::AreEqual(7, testOut[8]);
			Assert::AreEqual(6, testOut[9]);
		}

		TEST_METHOD(rootTest21)
		{
			int* testOut = root("99999999999999999", 3);
			Assert::IsNull(testOut);
		}

		TEST_METHOD(rootTest22)
		{
			int* testOut = root("0", 3);
			Assert::IsNotNull(testOut);
			Assert::AreEqual(2, testOut[0]);
			Assert::AreEqual(2, testOut[1]);
			Assert::AreEqual(0, testOut[2]);
		}

		TEST_METHOD(rootTest23)
		{
			int* testOut = root("-4", 3);
			Assert::IsNull(testOut);
		}

		TEST_METHOD(rootTest24)
		{
			int* testOut = root("asdf", 3);
			Assert::IsNull(testOut);
		}
	};
}
