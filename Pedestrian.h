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
    void moveNorth();
    void moveSouth();
    void moveEast();
    void moveWest();
    int x, y;
    Road currentRoad;
    Junction currentJunction;
    Junction nextJunction;

private:

};


#endif //TRAFFICLIGHTSYSTEM_PEDESTRIAN_H
