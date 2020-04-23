//
// Created by RYC on 2020/4/14.
//

#ifndef TRAFFICLIGHTSYSTEM_JUNCTION_H
#define TRAFFICLIGHTSYSTEM_JUNCTION_H

#include "Road.h"

class Junction {
//contains four roads(with single direction and one traffic light)
public:
    Junction();
    Junction(vector<Road>);
    bool needsUpdate(int current_time);
    void doUpdate(int current_time);
    void goNext();
    int delayPtr[4];
    int junc_time = 0;
    vector<Road> roadSeq = {
            Road('n', 50, 20),
            Road('e', 50, 20),
            Road('s', 50, 20),
            Road('w', 50, 20)
    };
    vector<Road>::iterator currentRoad = roadSeq.begin();
    int ctr_x = 100, ctr_y = 100;
    int last_time = 0;
    void simulate_one_tick();
};


#endif //TRAFFICLIGHTSYSTEM_JUNCTION_H


//
// Created by RYC on 2020/4/13.
//
//
//#ifndef TRAFFICLIGHTSYSTEM_JUNCTIONLIGHT_H
//#define TRAFFICLIGHTSYSTEM_JUNCTIONLIGHT_H
//
//#include <vector>
//#include <string>
//#include "TrafficLight.h"
//
//using namespace std;
//
//class JunctionLight {
//public:
//    JunctionLight(int* delayPtr, int lightNum);                              //constructor
//
//    int last_time = 0;
//    //there are 3-4 lights in a junction
//    TrafficLight light[4];
//    vector<TrafficLight>lightSeq;
//    vector<TrafficLight>::iterator currentLight;
//    bool needsUpdate(int current_time);
//    void doUpdate(int current_time);
//    void goNext();
//    int delayPtr[4];
//    int lightNum = 3;
//    int junc_time = 0;
//};
//
//
//#endif //TRAFFICLIGHTSYSTEM_JUNCTIONLIGHT_H
