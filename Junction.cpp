//
// Created by RYC on 2020/4/14.
//

#include "Junction.h"
#include <iostream>

using namespace std;

Junction::Junction() {
    //n: 100, 150 e: 50, 100 , s: 100, 50  , w 150, 100
    //set start point for all the roads in junction
    roadSeq[0].setStrPt(ctr_x, ctr_y + roadSeq[0].getLength());
    roadSeq[1].setStrPt(ctr_x - roadSeq[1].getLength(), ctr_y);
    roadSeq[2].setStrPt(ctr_x, ctr_y - roadSeq[2].getLength());
    roadSeq[3].setStrPt(ctr_x + roadSeq[3].getLength(), ctr_y);
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

void Junction::tick() {//north -> north
    while(true){
//        cout << "Current Road: " << currentRoad->getDirection() << endl;
        //activate trafficlight
        while(currentRoad == roadSeq.end()) {
            //let pedestiran go
            //go to the first light
            currentRoad = roadSeq.begin();
            pedestrianLight.run_one_cycle();
        }
        currentRoad->trafficLight->run_one_cycle();
        currentRoad++;
    }
}

thread Junction::simulate_one_tick() {
    return thread( [this] { this->tick(); } );
}

void Junction::setCloseJunctions(Junction* west, Junction* east, Junction* north, Junction* south) {
    westJunction = west;
    eastJunction = east;
    northJunction = north;
    southJunction = south;
    if(west)
        west->eastJunction = this;
    if(east)
        east->westJunction = this;
    if(north)
        north->southJunction = this;
    if(south)
        south->northJunction = this;
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