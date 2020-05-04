//
// Created by RYC on 2020/4/14.
//

#ifndef TRAFFICLIGHTSYSTEM_PEDESTRIAN_H
#define TRAFFICLIGHTSYSTEM_PEDESTRIAN_H

#include "User.h"
#include "Junction.h"

//class containing attributes and methods associated to pedestrian
class Pedestrian: User {
public:
    //constructor - no data provided
    Pedestrian();
    //constructor - data provided
    Pedestrian(Junction, Road);
    void move();
    //executes walking functionality simultaneously with traffic light and pedestrian light functionality
    thread walk();
    //method to turn the pedestrain to the next road after leaving the previous road
    void thruJunction();
    //method to tell pedestrian whether they are reaching the junction
    bool isPassJunction();
    //vector of junction representing the user's path in the grid
    vector<Junction*> juncSeq;
    //iterator to walk through vector of junctions
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
    //variable to represent whether road user has passed the previous junction
    bool flag_passed = true;
};

#endif //TRAFFICLIGHTSYSTEM_PEDESTRIAN_H
