#include "pch.h"
#include "CppUnitTest.h"
#include <string.h>
#include "..\BookParser\PRNParser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(TEST_FOR_CLASS_PRNPasrser)
	{
	public:
		
		TEST_METHOD(Test_worng_length_input)
		{
			std :: string excpectedResult = "Error"; 
			PRNParser* a = new PRNParser();
			string result  = a->ParseLine("Wrong_Length_Of_Input");
			Assert::AreEqual ( result , excpectedResult);
		}
		TEST_METHOD(Test_Done_input)
		{
			std::string excpectedResult1 = "Done";
			PRNParser* a = new PRNParser();
			string result = a->ParseLine("The House of Doctor Dee                 Ackroyd,Peter                 9780140171174");
			Assert::AreEqual(result, excpectedResult1);
		}
	};
}
