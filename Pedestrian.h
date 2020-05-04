//
// Created by RYC on 2020/4/14.
//

#ifndef TRAFFICLIGHTSYSTEM_PEDESTRIAN_H
#define TRAFFICLIGHTSYSTEM_PEDESTRIAN_H

#include "User.h"
#include "Junction.h"

class Pedestrian: User {
public:
    Pedestrian();
    Pedestrian(Junction, Road);
    void move();
    thread walk();
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


#endif //TRAFFICLIGHTSYSTEM_PEDESTRIAN_H
