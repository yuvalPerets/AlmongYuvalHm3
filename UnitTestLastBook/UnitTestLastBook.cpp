#include "pch.h"
#include "CppUnitTest.h"
#include <string.h>
#include "..\BookParser\PRNParser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLastBook
{
	TEST_CLASS(UnitTestLastBook)
	{
	public:
		
		TEST_METHOD(Test_last_book_doesnt_exist)
		{
			PRNParser* a = new PRNParser();
			
			
		}
	};
}
