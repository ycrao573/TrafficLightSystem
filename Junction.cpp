//
// Created by RYC on 2020/4/14.
//

#include "Junction.h"
#include <iostream>
using namespace std;

//function definition for constructor - no data provided
Junction::Junction() {
    //set start point for all the roads in junction
    roadSeq[0].setStrPt(ctr_x, ctr_y + roadSeq[0].getLength());
    roadSeq[1].setStrPt(ctr_x - roadSeq[1].getLength(), ctr_y);
    roadSeq[2].setStrPt(ctr_x, ctr_y - roadSeq[2].getLength());
    roadSeq[3].setStrPt(ctr_x + roadSeq[3].getLength(), ctr_y);
    currentRoad = roadSeq.begin();
}

//function definition for constructor for cross junction - data provided
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

//function definition for constructor for T junction - data provided
Junction::Junction(int ctr_x, int ctr_y, string name, char del_road) {
    this->ctr_y = ctr_y;
    this->ctr_x = ctr_x;
    this->name = name;
    //removes a road from cross junction 
    //generates T junction
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


Junction::~Junction() {
    if(!roadSeq.empty() || pedestrianLight != nullptr){
        roadSeq.clear();
        delete[] pedestrianLight;
    }
}

//function definition for simulating one junction
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

//function definition for executing junction functionality simultaneously
//with the rest of the system
thread Junction::simulate_one_tick() {
    return thread([this] { this->tick(); });
}

//function definition for connecting adjacent junctions to current junction
void Junction::setCloseJunctions(Junction *west, Junction *east, Junction *north, Junction *south) {
    //setup the grid network (connect the junctions)
    westJunction = west;
    eastJunction = east;
    northJunction = north;
    southJunction = south;
    //connects current junction and the adjacent junctions in both ways
    //e.g. west road of current junction would connect to east road of adjacent junction
    if (west)
        west->eastJunction = this;
    if (east)
        east->westJunction = this;
    if (north)
        north->southJunction = this;
    if (south)
        south->northJunction = this;
}

//function definition for setting up independent traffic lights
void Junction::generateIndepSeq() {
    //generate random time for the traffic light time sequence by randomising the green light
    srand((unsigned) time(0));
    int delay[4] = {1, 1, (1 + (rand() % 10)), 1};
    for (int index = 0; index < roadSeq.size(); index++)
        this->roadSeq[index].trafficLight->setDelays(delay);
}

