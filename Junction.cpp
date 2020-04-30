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

Junction::Junction(int ctr_x, int ctr_y) {
    this->ctr_y = ctr_y;
    this->ctr_x = ctr_x;
    //n: 100, 150 e: 50, 100 , s: 100, 50  , w 150, 100
    //set start point for all the roads in junction
    roadSeq[0].setStrPt(ctr_x, ctr_y + roadSeq[0].getLength() - 5);
    roadSeq[1].setStrPt(ctr_x - roadSeq[1].getLength() + 5, ctr_y);
    roadSeq[2].setStrPt(ctr_x, ctr_y - roadSeq[2].getLength() + 5);
    roadSeq[3].setStrPt(ctr_x + roadSeq[3].getLength() - 5, ctr_y);
    currentRoad = roadSeq.begin();
}
//
//bool Junction::needsUpdate(int current_time)
//{
//    if ((current_time - last_time) >= currentRoad->trafficLight->period)
//    {
//        return true;
//    }
//    return false;
//}
//
//void Junction::doUpdate(int current_time)
//{
//    ++currentRoad;
//    cout << "Next Light Enabled" << endl;
//    last_time = current_time;
//}

void Junction::tick() {//north -> north
    while(true){
        //activate trafficlight
        if(currentRoad == roadSeq.end()) {
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