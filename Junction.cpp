//
// Created by RYC on 2020/4/14.
//

#include "Junction.h"
#include <iostream>

using namespace std;

Junction::Junction() {
    //set start point for all the roads in junction
    roadSeq[0].setStrPt(ctr_x, ctr_y + roadSeq[0].getLength());
    roadSeq[1].setStrPt(ctr_x - roadSeq[1].getLength(), ctr_y);
    roadSeq[2].setStrPt(ctr_x, ctr_y - roadSeq[2].getLength());
    roadSeq[3].setStrPt(ctr_x + roadSeq[3].getLength(), ctr_y);
    currentRoad = roadSeq.begin();
}

Junction::Junction(int ctr_x, int ctr_y, string name) {
    this->ctr_y = ctr_y;
    this->ctr_x = ctr_x;
    this->name = name;
    //set start point for all the roads in junction
    roadSeq[0].setStrPt(ctr_x, ctr_y + roadSeq[0].getLength());
    roadSeq[1].setStrPt(ctr_x - roadSeq[1].getLength(), ctr_y);
    roadSeq[2].setStrPt(ctr_x, ctr_y - roadSeq[2].getLength());
    roadSeq[3].setStrPt(ctr_x + roadSeq[3].getLength(), ctr_y);
    currentRoad = roadSeq.begin();
}

Junction::Junction(int ctr_x, int ctr_y, string name, char del_road) {
    this->ctr_y = ctr_y;
    this->ctr_x = ctr_x;
    this->name = name;
    switch (del_road) {
        case 'n':
            roadSeq.erase(roadSeq.begin());
            break;
        case 'e':
            roadSeq.erase(roadSeq.begin() + 1);
            break;
        case 's':
            roadSeq.erase(roadSeq.begin() + 2);
            break;
        case 'w':
            roadSeq.erase(roadSeq.begin() + 3);
            break;
    }
}

void Junction::tick() {//four directions of lights + pedestrian light
    while (true) {
        //activate trafficlight
        if (currentRoad == roadSeq.end()) {
            //let pedestiran go
            //go to the first light
            currentRoad = roadSeq.begin();
            pedestrianLight->run_one_cycle();
        }
        currentRoad->trafficLight->run_one_cycle();
        currentRoad++;
    }
}

thread Junction::simulate_one_tick() {
    return thread([this] { this->tick(); });
}

void Junction::setCloseJunctions(Junction *west, Junction *east, Junction *north, Junction *south) {
    //setup the grid network (connect the junctions)
    westJunction = west;
    eastJunction = east;
    northJunction = north;
    southJunction = south;
    if (west)
        west->eastJunction = this;
    if (east)
        east->westJunction = this;
    if (north)
        north->southJunction = this;
    if (south)
        south->northJunction = this;
}

void Junction::generateIndepSeq() {
    //generate random time for the traffic light time sequence by randomising the green light
    srand((unsigned) time(0));
    int delay[4] = {1, 1, (1 + (rand() % 10)), 1};
    for (int index = 0; index < roadSeq.size(); index++)
        this->roadSeq[index].trafficLight->setDelays(delay);
}
