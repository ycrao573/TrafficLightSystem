#pragma once
#ifndef USER_HPP
#define USER_HPP
#include <string>
#include <vector>
#include <thread>
#include "Windows.h"
#include "Junction.h"
using namespace std;

class User
{
public:
    User();                              //constructor
    User(Junction junction, Road road);
//    ~User();                             //destructor
    virtual void move(){};
    //operator overloading utilised so that...
    //when increase num of cars button is selected...
    //num of cars is increased
    User operator+(User);
    //operator overloading utilised so that...
    //when decrease num of cars button is selected...
    //num of cars is decreased
    User operator-(User);
    void stop();
    void start();
    int x, y;
    int getSpeed();
    void setSpeed(int speed);
    int getVelocity();
    void setVelocity(int velocity);
    void setPt(int x, int y);
    int speed;
    int velocity = speed;
private:
    int NumOfCars;
};

#endif