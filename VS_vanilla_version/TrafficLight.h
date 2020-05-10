#ifndef TRAFFICLIGHTSYSTEM_TRAFFICLIGHT_H
#define TRAFFICLIGHTSYSTEM_TRAFFICLIGHT_H

//include vector and string libraries for associated data types
//include thread library to execute functions simultaenously
#include <vector>
#include <string>
#include <thread>
using namespace std;

//Class to store attributes and methods associated with a Traffic Light
class TrafficLight {
public:
    TrafficLight();
    //constructor - creates instance of traffic light when data is provided
    //pointer required to point to the array of delay times
    TrafficLight(int *delayPtr);        
    bool needsUpdate(int current_time);
    //method to update traffic light state e.g. R -> RA
    void doUpdate(int current_time);
    string getState();
    //setter method used to assign values to delay times of each state
    void setDelays(int* delayPtr);
    int time = 0;
    //method used to run one light sequence 
    void run_one_cycle();
    //Vector pair used to combine state and delay in 1 field so can always iterate together
    vector<pair<string, int>> state_pair = {
            {"R", Rtime},
            {"RA", RAtime},
            {"G", Gtime},
            {"A", Atime},
    };
    //iterator used to navigate through state_pair vector 
    //initially begins at first element of state_pair vector e.g. {"R", Rtime}
    vector<pair<string, int>>::iterator current_state = state_pair.begin();
    //updates the time when the traffic light state ends
    int lastUpdate;
    int Rtime, RAtime = 1, Gtime, Atime = 1;
    //variable for total time taken for light sequence 
    int period;
    //array to store delays for each state of traffic light
    int delayPtr[4] = { 1,1,5,1 };
};

#endif //TRAFFICLIGHTSYSTEM_TRAFFICLIGHT_H
