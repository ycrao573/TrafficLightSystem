#include "User.h"
#include <iostream>
using namespace std;

User::User()
{
    UserType = "Car";
    NumOfCars = 1;
}

User::~User()
{
}

User::User(string UserSelection, int NumOfCars)
{
    //set number of cars to user defined number
    this->NumOfCars = NumOfCars;
    //if condition to determine user type
    if (UserSelection == "Car" || UserSelection == "car")
        this->UserType = "Car";
    else if (UserSelection == "Pedestrian" || UserSelection == "pedestrian")
        this->UserType = "Pedestrian";
}

void User::printUserType()
{
    cout << "User Selection: " << UserType << endl;
}

//operator+ function definition for when...
//increase numOfCars button is selected
User User::operator+(User a) {
    //create new instance of User class
    User c;
    //Increase number of cars
    c.NumOfCars = this->NumOfCars + a.NumOfCars;
    return c;
}

//operator- function definition for when...
//decrease numOfCars button is selected
User User::operator-(User a) {
    //create new instance of User class
    User c;
    //decrease number of cars
    c.NumOfCars = this->NumOfCars - a.NumOfCars;
    return c;
}