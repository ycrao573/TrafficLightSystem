//
// Created by RYC on 2020/4/14.
//

#ifndef TRAFFICLIGHTSYSTEM_GRID_H
#define TRAFFICLIGHTSYSTEM_GRID_H
#include <vector>
#include "Junction.h"
#include "User.h"


class Grid {
//contains Junction, User
public:
    Grid();
    vector<Junction> myNetwork;
    vector<Junction>::iterator currentJunction;
    vector<User> users;
    void restart();
    void doNext();
    void sync(bool);

};


#endif //TRAFFICLIGHTSYSTEM_GRID_H
