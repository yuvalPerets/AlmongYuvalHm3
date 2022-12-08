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
			if (size(Line) != 84)
				this->status = "Error";
			else
			{
				if (Line.substr(37, 39) == "...")
				{
					this->status = "Incomplete";
				}
				else
				{
					this->status = "Done";
				}
			}
		}
		else
		{
			string realName = this->lastRead.getBookName().substr(0,36)	 + Line; 
			this->lastRead.setBookName(realName);
		}
		if (this->status != "Error")
		{
			string BookName = Line.substr(0, 39);
			string bookAuthor = Line.substr(40, 69);
			string bookID = Line.substr(70, 83);
			this->lastRead.setBookAuthor(bookAuthor);
			this->lastRead.setBookID(bookID);
			this->lastRead.setBookName(BookName);
		}
		return this->status;
	}

	Book getlastbook() { return this->lastRead; }
	
	
};