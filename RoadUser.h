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
    void moveNorth();
    void moveSouth();
    void moveEast();
    vvoid moveWest();
    void stop();
    void start();
    bool passJunction;
    void changeDirection(char nextDirection);
    int x, y;
    const Junction &getCurrentJunction() const;
    void setCurrentJunction(const Junction &currentJunction);
    const Road &getCurrentRoad() const;
    void setCurrentRoad(const Road &currentRoad);
    char getCurrentDirection() const;
    void setCurrentDirection(char currentDirection);
    char getNextDirection() const;
    void setNextDirection(char nextDirection);
//    if(road->trafficLight = ???)
//        then stop()
//    else
//        then start()
private:
    Junction currentJunction;
    Road currentRoad; //contains currentDirection
    char currentDirection;
    char nextDirection; // will come to another road
    const int speed = 5;
    int velocity;

public:
    int getVelocity() const;
    void setVelocity(int velocity);
};
        |N              |N
        +               |
    *   |       *       |
W==+===========+===============E
    *   |       *       | *
        +               |
        S===============S
                *
#endif //TRAFFICLIGHTSYSTEM_ROADUSER_H
