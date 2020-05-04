#include "User.h"
#include <iostream>

using namespace std;

User::User() {
    setPt(0, 0);
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

void User::stop() {
    setVelocity(0);
}

void User::start() {
    setVelocity(speed);
}

void User::setVelocity(int velocity) {
    this->velocity = velocity;
}

void User::setPt(int x, int y) {
    this->x = x;
    this->y = y;
}

int User::getSpeed() {
    return speed;
}

void User::setSpeed(int speed) {
    this->speed = speed;
}

int User::getVelocity() {
    return velocity;
}
