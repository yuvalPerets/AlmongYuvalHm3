#include "pch.h"
#include "CppUnitTest.h"
#include "..\\BookParser\PRNParser.h"
#include <string.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Unittestforlastread
{
	TEST_CLASS(Unittestforlastread)
	{
	public:
		
		TEST_METHOD(TestMethod1_book_doesnt_exist)
		{
			Book* excpectedResult = new Book();
			PRNParser* a = new PRNParser();
			Book result = a->getlastbook();
			string stringbookexpected = excpectedResult->getBookName() + excpectedResult->getBookAuthor() + excpectedResult->getBookID();
			string stringbookResult = a->getlastbook().getBook();
				Assert::AreEqual(stringbookexpected, stringbookResult);
		}
		TEST_METHOD(TestMethod2_book_does_exist)
		{
			PRNParser* a = new PRNParser();
			std::string example = "Little Women                            Alcott,Louisa May             9781402714580";
			a->ParseLine(example);
			string stringbookResult = a->getlastbook().getBook();
			Assert::AreEqual(example, stringbookResult);

		}
		TEST_METHOD(TestMethod3_book_exist_and_last_status_error)
		{
			PRNParser* a = new PRNParser();
			std::string example = "Little Women                            Alcott,Louisa May             9781402714580";
			a->ParseLine(example);
			a->ParseLine("input_that_creates_an_'error'_return");
			string stringbookResult = a->getlastbook().getBook();
			Assert::AreEqual(example, stringbookResult);

		}
		TEST_METHOD(TestMethod4_last_line_genererated_incomplete)
		{
			PRNParser* a = new PRNParser();
			std::string example = "Uncle Tom's Cabin; or, Life Among the...Beecher Stowe,Harriet         9781840224023";
			a->ParseLine(example);
			string stringbookResult = a->getlastbook().getBook();
			string expectedResult = ""; 
			Assert::AreEqual(expectedResult, stringbookResult);
		}
	};
}
