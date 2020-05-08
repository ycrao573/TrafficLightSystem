#include "User.h"
//required for inputtig and outputting data
#include <iostream>

using namespace std;

//function definition for constructor - no data provided
User::User() {
    //initialises start point to predefined position
    setPt(0, 0);
}

User::User(Junction junction, Road road)
{
}

//function definiton for adding more cars to the road
User User::operator+(User a) {
    //create new instance of User class
    User c;
    //Increase number of cars
    c.NumOfCars = this->NumOfCars + a.NumOfCars;
    return c;
}

//function definiton for adding more cars to the road
User User::operator-(User a) {
    //create new instance of User class
    User c;
    //decrease number of cars
    c.NumOfCars = this->NumOfCars - a.NumOfCars;
    return c;
}

//function definiton for stopping user movement
void User::stop() {
    setVelocity(0);
}

//function definiton for starting user movement
void User::start() {
    //the velocity is set to a constant speed
    setVelocity(speed);
}

//function definiton for setting the user's velocity
void User::setVelocity(int velocity) {
    this->velocity = velocity;
}

//function definiton for setting user's position on the map
void User::setPt(int x, int y) {
    this->x = x;
    this->y = y;
}

//function definiton for returning user's speed
int User::getSpeed() {
    return speed;
}

//function definiton for setting user's speed
void User::setSpeed(int speed) {
    this->speed = speed;
}

//function definiton for returning user's velocity
int User::getVelocity() {
    return velocity;
}
