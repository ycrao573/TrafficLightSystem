#ifndef TRAFFICLIGHTSYSTEM_ROADUSER_H
#define TRAFFICLIGHTSYSTEM_ROADUSER_H
#include "User.h"
#include "Junction.h"
#include "Road.h"

//class containing attributes and methods associated with Road user
class RoadUser : User {
public:
    //constructor - when no data is provided
    RoadUser();
    //constructor - when data is provided
    RoadUser(Junction junction, Road road, string type);

    void move();
    //executes drive functionality simultaneosuly to traffic light functionality
    thread drive();
    //method to turn the road user to the next road after leaving the previous road 
    void thruJunction();
    //method to tell road user whether they are reaching the junction
    bool isPassJunction();
    //vector of junctions representing the user's path in the grid
    vector<Junction*> juncSeq;
    //iterator to walk through vector of junctions 
    vector<Junction*>::iterator juncSeqPtr;
    void setCurrentJunction(Junction *currentJunction);
    void setNextJunction(Junction *nextJunction);
    void setCurrentRoad(Road *currentRoad);
    void setNextRoad(Road *nextRoad);
    bool reachDestination = false;
    string type = "c";
private:
    Junction* currentJunction;
    Junction* nextJunction;
    Road* currentRoad;
    Road* nextRoad;
    //variable to represent whether road user has passed the previous junction
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
