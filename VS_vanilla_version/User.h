#ifndef USER_HPP
#define USER_HPP

//include libraries for predefined functions such as sleep
#include <string>
#include <vector>
#include <thread>
#include "Windows.h"
#include "Junction.h"
using namespace std;

//class containing attributes and methods associated with a user
class User
{
public:
    //constructor - no data is provided
    User();               
    //virtual method used to direct the function definition to the child class
    //function definition not required in parent class
    virtual void move(){};
    void stop();
    void start();
    //variables associated with x and y postition in map
    int x, y;
    int getSpeed();
    void setSpeed(int speed);
    int getVelocity();
    void setVelocity(int velocity);
    void setPt(int x, int y);
    int speed;
    int velocity = speed;
    bool reachLastJunction = false;
};

#endif
