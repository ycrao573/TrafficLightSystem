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
    thread drive();
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
    bool isPassJunction();
    const Junction &getNextJunction() const;
    void setNextJunction(Junction nextJunction);
    const Road &getNextRoad() const;
    void setNextRoad(const Road &nextRoad);
    void setCurrentJunction(const Junction &currentJunction);
    void setCurrentRoad(const Road &currentRoad);
    void setCurrentDirection(char currentDirection);

private:
    Junction currentJunction;
    Junction nextJunction;
    Road currentRoad;
    //contains currentDirection
    Road nextRoad;
    char currentDirection;
    bool passJunction;
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
