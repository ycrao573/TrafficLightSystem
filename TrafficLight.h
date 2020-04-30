#ifndef TRAFFICLIGHTSYSTEM_TRAFFICLIGHT_H
#define TRAFFICLIGHTSYSTEM_TRAFFICLIGHT_H

#include <vector>
#include <string>
#include <thread>

using namespace std;

class TrafficLight {
public:
    TrafficLight();
    TrafficLight(int *delayPtr);                              //constructor
    TrafficLight(int *delayPtr, bool random);

    bool needsUpdate(int current_time);
    void doUpdate(int current_time);
    string getState();
    void setDelays(int* delayPtr);
    int time = 0;
    void run_one_cycle();


    // combine state and delay in 1 field so we can always iterate together
    vector<pair<string, int>> state_pair = {
            {"R", Rtime},
            {"RA", RAtime},
            {"G", Gtime},
            {"A", Atime},
    };
    vector<pair<string, int>>::iterator current_state = state_pair.begin();


    int lastUpdate;
    int Rtime, RAtime = 1, Gtime, Atime = 1;
    int period;
    int delayPtr[4] = { 1,1,5,1 };
};
#endif //TRAFFICLIGHTSYSTEM_TRAFFICLIGHT_H
