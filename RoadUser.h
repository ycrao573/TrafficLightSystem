#ifndef TRAFFICLIGHTSYSTEM_ROADUSER_H
#define TRAFFICLIGHTSYSTEM_ROADUSER_H
#include "User.h"
#include "Junction.h"
#include "Road.h"

class RoadUser : User {
public:
    RoadUser();
    RoadUser(Junction, Road);
    void move();
    thread drive();
    void thruJunction();
    bool isPassJunction();
    vector<Junction*> juncSeq;
    vector<Junction*>::iterator juncSeqPtr;
    void setCurrentJunction(Junction *currentJunction);
    void setNextJunction(Junction *nextJunction);
    void setCurrentRoad(Road *currentRoad);
    void setNextRoad(Road *nextRoad);
    bool reachDestination = false;

private:
    Junction* currentJunction;
    Junction* nextJunction;
    Road* currentRoad;
    Road* nextRoad;
    bool flag_passed = true;
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
