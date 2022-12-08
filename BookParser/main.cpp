#include <stdio.h>
#include <string.h>
#include<iostream>
#include <fstream>
using namespace std;
#include "PRNParser.h"
void main() 
	{
	ifstream myDatabase("ISBNs.prn", ios::in);
	PRNParser* p = new PRNParser() ;
	char  currentLine [100];

	myDatabase.getline(currentLine, '\n');


	cout << currentLine  ;
	}
	