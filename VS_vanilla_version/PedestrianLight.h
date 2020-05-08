//
// Created by RYC on 2020/4/26.
//

#ifndef TRAFFICLIGHTSYSTEM_PEDESTRIANLIGHT_H
#define TRAFFICLIGHTSYSTEM_PEDESTRIANLIGHT_H

//vector and iostream included for use of associated data types
//iostream used for inputting and outputting data to system
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//class containing attributes and methods associated with a pedestrian light
class PedestrianLight {
public:
    //constructor - when no data is provided
    PedestrianLight();
    //constructor - when data is provided
    PedestrianLight(int period);                             
    void setDelays(int period);
    void run_one_cycle();
    bool canPass = false;
    bool isCrossing = false;
    //time associated to green state
    int period = 8;
};

#endif //TRAFFICLIGHTSYSTEM_PEDESTRIANLIGHT_H
