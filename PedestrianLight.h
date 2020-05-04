//
// Created by RYC on 2020/4/26.
//

#ifndef TRAFFICLIGHTSYSTEM_PEDESTRIANLIGHT_H
#define TRAFFICLIGHTSYSTEM_PEDESTRIANLIGHT_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class PedestrianLight {
public:
    PedestrianLight();
    PedestrianLight(int period);                              //constructor
    void setDelays(int period);
    void run_one_cycle();
    bool canPass = false;
    bool isCrossing = false;
    int period = 8;
};


#endif //TRAFFICLIGHTSYSTEM_PEDESTRIANLIGHT_H
