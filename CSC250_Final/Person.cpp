#include "Person.h"
#include "Athlete.h"
#include "Coach.h"
#include<string>
#include<iostream>
#include<vector>
#include <algorithm> 

Person::Person() { // default constructor
    fname = "John";
    lname = "Doe";
    usawID = "1111111";
    role = 0;

}

void Person::addPerson() {

    string roleString;

	ofstream prsn("Person.txt", ios::app);
	system("cls");
	cout << "\n\n\tEnter First Name: ";
	cin >> fname;
	cout << "\n\tEnter "<< fname <<"'s Last Name: ";
    cin >> lname;
	cout << "\n\tEnter " << fname << "'s USA Weightlifting User ID: ";
	cin >> usawID; 
    cout << "\n\tselect " << fname << "'s Role: ";
    cout << "\n\t\t[1] Athlete. \n\t\t[2] Coach. \n\t\t";
    cin >> role;

    switch(role) {
        case 1:
            roleString = "ATHLETE";
            break;
                
        case 2:
            roleString = "COACH";
            break;

        default:
            cout << "\n\n\tInvalid input.";
    }

    transform(fname.begin(), fname.end(), fname.begin(), ::toupper); //converts entry to upper to avoid discrepancy
    transform(lname.begin(), lname.end(), lname.begin(), ::toupper); //converts entry to upper to avoid discrepancy

    if (check_digits(usawID) == true) {                 //runs function to check if length is appropriate
        if (check_numbers(usawID) == true) {            //runs function to check if numbers were entered
            if (prsn.is_open()) {
                prsn << fname << " " << lname << " "
                    << usawID << " " << roleString << endl;
                cout << "\n\tContact saved successfully !";
            }
            else {
                cout << "\n\tError in opening record!\n\n\t\t*Please Retry*";
            }
        }
        else {
            cout << "\n\tOnly numbers are allowed!\n\n\t\t*Please Retry*";
        }
    }
    else {
        cout << "\n\tUSA Weightlifting ID should be of 6 to 8 digits only.\n\n\t\t*Please Retry*";

    }

    cout << endl << endl;
    system("pause");
    system("cls");
    prsn.close();

}

bool Person::check_digits(string usawID)
{
    if (usawID.length() >= 6 && usawID.length() <= 8)
        return true;
    else
        return false;
}

bool Person::check_numbers(string usawID)
{
    bool check = true;

    for (int i = 0; i < usawID.length(); i++) {
        if (!(int(usawID[i]) >= 48 && int(usawID[i]) <= 57)) { //verifys if numbers
            check = false;
            break;
        }
    }

    if (check == true)
        return true;

    if (check == false)
        return false;

    cout << endl << endl;
    system("pause");
    system("cls");
}



void Person::searchPerson() {
    bool found = false;
    ifstream myfile("Person.txt");
    string keyword;
    cout << "\n\tEnter Name to search : ";
    cin >> keyword;
    transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper); //convers search to uppercase to prevent discrepancy
    while (myfile >> fname >> lname >> usawID >> roleString) {
        if (keyword == fname || keyword == lname) {
            system("cls");
            cout << "\n\n\n\t\tPERSONS DETAILS";
            cout << "\n\nFirst Name : " << fname;
            cout << "\nLast Name : " << lname;
            cout << "\nUSA Weightlifting ID : " << usawID;
            cout << "\nPersons role : " << roleString;

            found = true;
            break;
        }
    }
    if (found == false)
        cout << "\nNo such contact is found!\n\n\t\t*Please Retry*";

    cout << endl << endl;
    system("pause");
    system("cls");


}


void Person::printList() {

    system("cls");

    vector<string> input;
    ifstream myfile("Person.txt");
    if (!myfile) {
    cout << "Error opening file" << endl;
        return;
    }
    string temp;
    while (getline(myfile, temp)) {
    input.push_back(temp);
    }
    sort(input.begin(), input.end());
    for (const auto& s : input)
    cout << "\t\t" << s << endl;

    system("pause");
    system("cls");
}