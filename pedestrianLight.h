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
//    bool needsUpdate(int current_time);
//    void doUpdate(int current_time);
    string getState();
    void setDelays(int period);
    int ped_time = 0;
    void run_one_cycle();
    vector<string> state = {"R", "G"};
    vector<string>::iterator current_state = state.begin();

    int lastUpdate;
    int period = 8;
};


#endif //TRAFFICLIGHTSYSTEM_PEDESTRIANLIGHT_H
