#include "Person.h"
#include "Athlete.h"
#include "Coach.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>  
#include <algorithm>






void Coach::writeWorkout() {

	system("cls");

	Person workout; 
	workout.searchPerson();
	int choice = 1;
	string exersize = "Blank";
	string repScheme = "Blank";
	string percentage = "Blank";

cout << "Enter in todays workout for " << workout.fname << ". \n";
	do {
		ofstream prsn(workout.fname + workout.lname + "_WORKOUT.txt", ios::app);
		if (prsn.is_open()) {


			
			cout << "What excersize will " << workout.fname << " be doing?\n\t ";
			std::getline(std::cin >> std::ws, exersize);
			cout << "What repitition scheme will " << workout.fname << " be doing?\n\t ";
			std::getline(std::cin >> std::ws, repScheme);
			cout << "What percentage will " << workout.fname << " be doing?\n\t ";
			cin >> percentage;

			prsn << "\n\t" << exersize << ": " << repScheme << "@ " << percentage << endl;

			cout << "\n\n\t[1] to add another exersize: ";
			cout << "\n\n\t[2] to go back to menu: \n\t";
			cin >> choice;
		}
		else {
			cout << "\n\tError in opening record!\n\n\t\t*Please Retry*";

		} 
		system("cls");
		prsn.close();
	} while (choice == 1);
	
}

