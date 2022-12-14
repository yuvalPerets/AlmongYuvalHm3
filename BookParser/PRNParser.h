#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;
#include "Book.h"
class PRNParser {
	Book lastRead;
	string status;
public :
	string ParseLine(string Line)
	{
		if (this->status != "Incomplete")
		{
			if (size(Line) != 83)
				this->status = "Error";
			else
			{
				if (Line.substr(37, 3) == "...")
				{
					this->status = "Incomplete";
				} 
				else
				{
					this->status = "Done";
				}
			}
			if (this->status != "Error")
			{
				string bookAuthor = Line.substr(40, 30);
				string bookID = Line.substr(70, 13);
				string BookName = Line.substr(0, 40);

				this->lastRead.setBookAuthor(bookAuthor);
				this->lastRead.setBookID(bookID);
				this->lastRead.setBookName(BookName);
			}
		}
		else
		{
			string realName = this->lastRead.getBookName().substr(0,37)	 + Line; 
			this->lastRead.setBookName(realName);
			this->status = "Done";
		}
		
		return this->status;
	}

	Book getlastbook() { 
		if (this->status == "Incomplete")
		{
			Book* a = new Book();
			return *a;
		}
		else
			return this->lastRead;
	}
	
	
};