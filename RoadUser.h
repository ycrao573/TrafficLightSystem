#ifndef TRAFFICLIGHTSYSTEM_ROADUSER_H
#define TRAFFICLIGHTSYSTEM_ROADUSER_H
#include "User.h"
#include "Junction.h"
#include "Road.h"

class RoadUser : User {
public:
    RoadUser();
    RoadUser(Junction, Road);
    char direction[4] = {'n', 's', 'w', 'e'};
    void move();
    void stop();
    void start();

    void changeDirection(char nextDirection);
    int x, y;
    const Junction &getCurrentJunction() const;
    const Road &getCurrentRoad() const;
    char getCurrentDirection() const;
    char getNextDirection() const;
    void setNextDirection(char nextDirection);
    int getVelocity() const;
    void setVelocity(int velocity);
    void setPt(int, int);
    void thruJunction();
    
private:
    Junction currentJunction;
    Road currentRoad; //contains currentDirection
    char currentDirection;
    bool passJunction;
public:
    bool isPassJunction();
private:
    char nextDirection; // will come to another road
    const int speed = 5;
    int velocity = speed;

};
//        |N              |N
//        +               |
//    *   |       *       |
//W==+===========+===============E
//    *   |       *       | *
//        +               |
//        S===============S
//                *
#endif //TRAFFICLIGHTSYSTEM_ROADUSER_H
