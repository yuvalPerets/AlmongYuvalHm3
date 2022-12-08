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
			Assert::AreEqual (excpectedResult, result);
		}
		
		TEST_METHOD(Test_Done_input)
		{
			std::string excpectedResult1 = "Done";
			PRNParser* a = new PRNParser();
		std::string example = "Little Women                            Alcott,Louisa May             9781402714580";
			string result = a->ParseLine(example);
			
				Assert::AreEqual(excpectedResult1, result);
		}
		TEST_METHOD(Test_Incomplete_input)
		{
			std::string excpectedResult2 = "Incomplete";
			PRNParser* a = new PRNParser();
		std::string exampleForIncomplete = "Uncle Tom's Cabin; or, Life Among the...Beecher Stowe,Harriet         9781840224023";
			string result = a->ParseLine(exampleForIncomplete);

			Assert::AreEqual(excpectedResult2, result);
		}
		TEST_METHOD(Test_Incomplete_input_part2)
		{
			std::string excpectedResult3 = "Done";
			PRNParser* a = new PRNParser();
		std::string exampleForIncomplete = "Uncle Tom's Cabin; or, Life Among the...Beecher Stowe,Harriet         9781840224023";
			a->ParseLine(exampleForIncomplete);
			std::string exampleForDone = " Lonely  ";
			string result = a->ParseLine(exampleForDone);

			Assert::AreEqual(excpectedResult3, result);
		}
		TEST_METHOD(Test_zero_input)
		{
			std::string excpectedResult = "Error";
			std::string trytingtopull = "pullmeplease";
			PRNParser* a = new PRNParser();
			string result = a->ParseLine("");
			Assert::AreEqual(excpectedResult, result);
		}
	};
}
