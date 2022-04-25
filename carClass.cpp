#include<iostream>
#include<exception>
#include<string>
#include <stdexcept>

using namespace std;

//Car class declaration
class Car
{
    private: 

    //private variables
    int year, speed;
    string make;

    public:    

    //Car class member functions and accesors

    Car()//default constructor
    {
        year = 0;
        make = "default";
        speed = 0;
    }

    Car(int y, string m) //constructor
        {
        year = y;
        make = m;
        speed = 0;
        }


    int getYear() //gets year of car from user
        {
        try{
        cout << "what is the year of the car? ";
        cin >> year;
        if ((year > 2024) || (year < 1920)) {throw runtime_error("Invalid year.");}
        }
        catch (runtime_error& excpt){
            cout << excpt.what() << endl;
            cout << "cannot accept entered year." << endl;
            cout << "enter a valid year: ";
            cin >> year;
        }
           return year;
        }

    string getMake() //gets make of car from user
        {
        cout << "what is the make of the car? ";
        cin >> make; 
        return make;
        }

    int getSpeed() //gets speed of car
        {
        return speed;
        }

    void accelerate() //accelerates car by 5 units
        {
        speed = speed + 5;
        }

    void brake() //slows car by 5 units
        {
        speed = speed - 5;
        }

    void printYear()
        {
        cout << "year: " << year << endl;
        }
    
    void printMake()
        {
        cout << "make: " << make << endl;
        }

};






int main()
{
    Car testCarObj;

    testCarObj.getYear();
    testCarObj.getMake();

    testCarObj.printYear();
    testCarObj.printMake();

    //Car testCarObj(2022,"Ford");

    //Call the accelerate function five times and display current speed;
    for (int fast=0; fast < 5; fast++) //accelerates 5 times.
        {
        testCarObj.accelerate();
        cout << "The current speed when accelerating is: " << testCarObj.getSpeed() << endl;
        }

    for (int slow=0; slow < 5; slow++) //brakes 5 times.
        {
        testCarObj.brake();
        cout << "Now the current speed is: " << testCarObj.getSpeed() << endl;
        }

    cout << endl;

    return 0;

}