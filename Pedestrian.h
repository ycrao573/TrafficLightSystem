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
    int x, y;
    bool needUpdateJunction();
    void updateRoad();
    void updateJunction();

private:
    Road currentRoad;
    Road nextRoad;
    Junction currentJunction;
    Junction nextJunction;
public:
    const Road &getNextRoad() const;

    void setNextRoad(const Road &nextRoad);

    const Junction &getNextJunction() const;

    void setNextJunction(const Junction &nextJunction);
};


#endif //TRAFFICLIGHTSYSTEM_PEDESTRIAN_H
