//
// Created by RYC on 2020/4/14.
//

#include "Junction.h"
#include <iostream>

using namespace std;

Junction::Junction() {
    //set start point for all the roads in junction
//    for (currentRoad = roadSeq.begin(); currentRoad != roadSeq.end(); currentRoad++) {
//        switch (currentRoad->getDirection()) {
//            case 'n':
//                currentRoad->setStrPt(100, 50);
//                break;
//            case 'w':
//                currentRoad->setStrPt(50, 100);
//                break;
//            case 's':
//                currentRoad->setStrPt(100, 150);
//                break;
//            case 'e':
//                currentRoad->setStrPt(150, 100);
//                break;
//            default:;
//        }
        roadSeq[0].setStrPt(100,50);
        roadSeq[1].setStrPt(50,100);
        roadSeq[2].setStrPt(100,150);
        roadSeq[3].setStrPt(150,100);
        currentRoad = roadSeq.begin();
}

bool Junction::needsUpdate(int current_time)
{
    if ((current_time - last_time) >= currentRoad->trafficLight->period)
    {
        return true;
    }
    return false;
}

void Junction::doUpdate(int current_time)
{
    ++currentRoad;
    cout << "Next Light Enabled" << endl;
    last_time = current_time;
}

void Junction::goNext()
{
    ++junc_time;
    if (this->needsUpdate(junc_time)) {
        this->doUpdate(junc_time);
    }
//    currentRoad->trafficLight.addSecond();
    cout << "total time: "<< junc_time << " Light time: " << currentRoad->trafficLight->time << " Color: " << currentRoad->trafficLight->getState() << endl;
}

void Junction::simulate_one_tick() {//north -> north
    while(true){
        cout << "Current Road: " << currentRoad->getDirection() << endl;
        //activate trafficlight
        currentRoad->trafficLight->run_one_cycle();
        currentRoad++;
        if(currentRoad == roadSeq.end())
            currentRoad = roadSeq.begin();
    }
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