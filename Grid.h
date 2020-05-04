//
// Created by RYC on 2020/4/14.
//

#ifndef TRAFFICLIGHTSYSTEM_GRID_H
#define TRAFFICLIGHTSYSTEM_GRID_H
#include <vector>
#include "Junction.h"
#include "User.h"

//class containing attributes and methods associated to a grid
class Grid {
//contains Junction, User
public:
    //constructor - no data provided
    Grid();
    //constructor - data provided
    Grid(int len, int wid);
    int len, wid;
    //grid consists of a vector of junctions
    vector<Junction*> myNetwork;
};

#endif //TRAFFICLIGHTSYSTEM_GRID_H
