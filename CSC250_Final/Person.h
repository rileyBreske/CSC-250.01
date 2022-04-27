#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;

class Person {
private:
	

public:
	string usawID{};					//persons USA Weightlifting Id.
	string fname;						//persons first name.
	string lname;						//persons last name.
	int role;
	string roleString;
	
	
	void addPerson();					//function to add new person.
	void searchPerson();				//function to search people in index.
	bool check_digits(string x);		//function to check if length is appropriate .
	bool check_numbers(string x);		//function to check if numbers were input.
	void printList();					//function to count entire list in file (used by "printList" function).
	char grabName(string fname, string lname);

	Person();

};

