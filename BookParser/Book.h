#include <stdio.h>
#include<iostream>
using namespace std;
#include <string.h>

  class Book {
     private:
		 string bookName ;
		 string atuhor ;
		 string ID ;

  public:

	 Book (string bookName , string atuhor , string ID )
	{
		 this->atuhor = atuhor;
		 this->bookName = bookName;
		 this->ID = ID;
	 }
	 Book() {
		 this->atuhor = "";
		 this->bookName = "";
		 this->ID = "";
	 }
 
	  string getBookName() { return this->bookName; }
	  string getBookAuthor() { return this->atuhor; }
	  string getBookID() { return this->ID; }
	  string getBook() { return getBookName() + getBookAuthor() + getBookID(); }

	  void setBookName(string bookName) { this->bookName = bookName; }
	  void setBookAuthor(string Author) { this->atuhor = Author; }
	  void setBookID(string ID) { this->ID = ID; }
	  bool operator==(Book& another)
	  {
		  return ((this->atuhor == another.atuhor) && (this->bookName == another.bookName) && (this->ID == another.ID));
	  }


};