#include "Person.h"
#include "Athlete.h"
#include "Coach.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>  
#include <algorithm>




void Coach::retrieveDate() {





}

void Coach::writeWorkout() {

	ifstream myfile("Person.txt");
	

	Person workout; 
	workout.searchPerson();
	cout << fname; 


}

