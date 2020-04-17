#ifndef TRAFFICLIGHTSYSTEM_ROADUSER_H
#define TRAFFICLIGHTSYSTEM_ROADUSER_H
#include "User.h"
#include "Junction.h"
#include "Road.h"

class RoadUser : User {
public:
    RoadUser();
    RoadUser(Junction, Road);
    char direction[4] = {'N', 'S', 'W', 'E'};
    void move();
    void stop();
    void start();
    bool passJunction;
    void changeDirection(char nextDirection);
    int x, y;
    const Junction &getCurrentJunction() const;
    const Road &getCurrentRoad() const;
    char getCurrentDirection() const;
    char getNextDirection() const;
    void setNextDirection(char nextDirection);
//    if(road->trafficLight = ???)
//        then stop()
//    else
//        then start()
    int getVelocity() const;
    void setVelocity(int velocity);
    
private:
    Junction currentJunction;
    Road currentRoad; //contains currentDirection
    char currentDirection;
    char nextDirection; // will come to another road
    const int speed = 5;
    int velocity;

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
