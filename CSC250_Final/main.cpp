#include "Person.h"
#include "Athlete.h"
#include "Coach.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>  
#include <algorithm>

std::ifstream inFile;
std::ofstream outFile;

using namespace std;

void exit()
{
	system("cls");
	cout << "\n\n\n\t\tProgram Closing.\n\n\n";
	exit(1);
}

void help()
{
	cout << "Help Menu";
	cout << endl << endl;
	system("pause");
	system("cls");
}

int main(string fname) {


	//Person newPerson;
	Coach newPerson;

	//newPerson.getName();

	int choice; // user choice in menu
	system("cls");


	


	while (1) {
		cout << "HOME PORTAL";
		cout << "\n\n\n\t\tATHLETE REPOSITORY";
		cout << "\n\n\t1. Add Person\n\t2. Search Person "
				"\n\t3. Print Sorted List\n\t4. Write Workout For Athlete\n\t5. Help\n\t6. Exit\n\t> ";
		cin >> choice;

		switch (choice) {

		case 1: 
			newPerson.addPerson(); //function to add person from person class
			break;

		case 2:		
			newPerson.searchPerson(); //function to search from person class
			break;

		case 3:
			newPerson.printList(); //function to sort and print entries from file.
			break;

		case 4:
			newPerson.writeWorkout();//function to write work out for athlete to read.
			break;

		case 5:
			help();//function for help
			break;


		case 6:			
			exit();//function to exit
			break;

		default: 
			cout << "\n\n\tInvalid input.";

		}

	}

	return 0;
}

/*
TO DO
find a library to import date and time

coach can
	write work out per day
	view work out per day(and athlete)








*/