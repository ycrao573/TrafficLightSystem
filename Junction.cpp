//
// Created by RYC on 2020/4/14.
//

#include "Junction.h"
#include <iostream>

using namespace std;

Junction::Junction() {
    roadSeq = {
            Road('n', 50, 20),
            Road('w', 50, 20),
            Road('s', 50, 20),
            Road('e', 50, 20)
    };
    currentRoad = roadSeq.begin();
}


bool Junction::needsUpdate(int current_time)
{
    if ((current_time - last_time) >= currentRoad->trafficLight.period)
    {
        return true;
    }
    return false;
}

void Junction::doUpdate(int current_time)
{
    ++currentRoad;
    if (currentRoad == roadSeq.end())
        currentRoad = roadSeq.begin();
    cout << "Next Light Enabled" << endl;
    last_time = current_time;
}

void Junction::goNext()
{
    ++junc_time;
    if (this->needsUpdate(junc_time)) {
        this->doUpdate(junc_time);
    }
    currentRoad->trafficLight.addSecond();
    cout << "total time: "<< junc_time << " Light time: " << currentRoad->trafficLight.time << " Color: " << currentRoad->trafficLight.getState() << endl;
}



//Junction::Junction(vector<Road> roadSeq) {
//    this->roadSeq = roadSeq;
//
//}

//JunctionLight::JunctionLight(int* delayPtr, int lightNum){
//    light[0] = TrafficLight(delayPtr);
//    light[1] = TrafficLight(delayPtr);
//    light[2] = TrafficLight(delayPtr);
//    light[3] = TrafficLight(delayPtr);
//    lightSeq = {
//            light[0], light[1], light[2]
//    };
//    if (lightNum == 4) {
//        lightSeq.push_back(light[3]);
//        this->lightNum = 4;
//    }
//    currentLight = lightSeq.begin();
//}