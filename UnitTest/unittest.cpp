

#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Flexer/Token.h"
#include "../Flexer/Lexer.h"
#include "../Flexer/Function.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char SimbolBegin = 'A';
			char SimbolEnd = 'Z';

			for (char i = SimbolBegin; i <= SimbolEnd; i++) {
				Assert::IsTrue(isletter(i) == 1);
			}

			SimbolBegin = 'a';
			SimbolEnd = 'z';

			for (char i = SimbolBegin; i <= SimbolEnd; i++) {
				Assert::IsTrue(isletter(i) == 1);
			}

			SimbolBegin = '0';
			SimbolEnd = '9';

			for (char i = SimbolBegin; i <= SimbolEnd; i++) {
				Assert::IsTrue(isletter(i) == 0);
			}

			SimbolBegin = '(';
			SimbolEnd = '.';

			for (char i = SimbolBegin; i <= SimbolEnd; i++) {
				Assert::IsTrue(isletter(i) == 0);
			}
		}

		TEST_METHOD(TestMethod2)
		{
			Token Test;
			string Line = "char float int double var";
			int Array[5] = { 4, 5, 3, 6, 3 };
			int LineNumber = 0;
			int Size = Line.size();
			int IdentidierArraySize = 0, IdentidierArray = 0;
			int CharacterReadMode = 0;
			for (int Identifier = 0; Identifier < Size; Identifier++) {
				while (Line[Identifier] == ' ' && Identifier < Size) Identifier++;
				Test = WordString(Line, LineNumber, Size, Identifier, CharacterReadMode);

				Assert::IsTrue(Test.GetString() == Line.substr(IdentidierArray, Array[IdentidierArraySize]));
				IdentidierArray += Array[IdentidierArraySize] + 1;
				IdentidierArraySize++;
			}
			
		}

		TEST_METHOD(TestMethod3)
		{
			Token Test;
			string Line = "Main static for if while class";
			int Array[6] = { 4, 6, 3, 2, 5, 5 };
			int LineNumber = 0;
			int Size = Line.size();
			int IdentidierArraySize = 0, IdentidierArray = 0;
			int CharacterReadMode = 0;
			for (int Identifier = 0; Identifier < Size; Identifier++) {
				while (Line[Identifier] == ' ' && Identifier < Size) Identifier++;
				Test = WordString(Line, LineNumber, Size, Identifier, CharacterReadMode);

				Assert::IsTrue(Test.GetString() == Line.substr(IdentidierArray, Array[IdentidierArraySize]));
				IdentidierArray += Array[IdentidierArraySize] + 1;
				IdentidierArraySize++;
			}
		}

		TEST_METHOD(TestMethod4)
		{
			Token Test;
			string Line = "0 1 2 3 4 5 6 7 8 9";
			int LineNumber = 0;
			int Size = Line.size(), SizeWord = 1;
			int IdentidierArray = 0;
			int CharacterReadMode = 0;
			for (int Identifier = 0; Identifier < Size; Identifier++) {
				while (Line[Identifier] == ' ' && Identifier < Size) Identifier++;
				Test = WordDigit(Line, LineNumber, Identifier);

				Assert::IsTrue(Test.GetString() == Line.substr(IdentidierArray, SizeWord));
				IdentidierArray += 2;
			}
		}

		TEST_METHOD(TestMethod5)
		{
			Token Test;
			string Line = "+ - / * % = ( ) [ ] { } < > ; . : , ";
			int LineNumber = 0;
			int Size = Line.size(), SizeWord = 1;
			int IdentidierArray = 0;
			int CharacterReadMode = 0;
			for (int Identifier = 0; Identifier < Size; Identifier++) {
				while (Line[Identifier] == ' ' && Identifier < Size) Identifier++;
				Test = WordZnak(Line, LineNumber, Size, Identifier);

				Assert::IsTrue(Test.GetString() == Line.substr(IdentidierArray, SizeWord));
				IdentidierArray += 2;
			}
		}

	};
}