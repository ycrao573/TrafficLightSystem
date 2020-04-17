#pragma once
#ifndef USER_HPP
#define USER_HPP
#include <string>
using namespace std;

class User
{
public:
    User();                              //constructor
//    ~User();                             //destructor
    User(string, int);
    void printUserType();
    virtual void moveNorth();
    virtual void moveSouth();
    virtual void moveEast();
    virtual void moveWest();
    //operator overloading utilised so that...
    //when increase num of cars button is selected...
    //num of cars is increased
    User operator+(User);
    //operator overloading utilised so that...
    //when decrease num of cars button is selected...
    //num of cars is decreased
    User operator-(User);
private:
    string UserType;
    int NumOfCars;
};

#endif

/*
 * User -> Car or Pedestrian (Button Chosen) -> Car, Pedestrian inherits User class
 *
 * Button to adjust the car on the lane  --- later
 *
 * 1. configure a network of traffic lights (with or without a pedestrian crossing feature)
 * 2. set up a network of roads with sets of lights at each junction and then step through the network operation while a “car” or user journeys through the system
 * 3. The user may be a pedestrian or road user
 * 4. globally synchronised or indeed to work  independently
 * 5. It is left to the users to consider if filter lanes are to be considered.
 *
 * */