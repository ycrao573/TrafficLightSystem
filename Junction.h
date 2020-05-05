//
// Created by RYC on 2020/4/14.
//

#ifndef TRAFFICLIGHTSYSTEM_JUNCTION_H
#define TRAFFICLIGHTSYSTEM_JUNCTION_H

#include "Road.h"
#include "PedestrianLight.h"

//class containing attributes and methods associated with a junction
class Junction {
public:
    //constructor - no data provided
    Junction();
    //constructor for cross junction - data provided
    Junction(int, int, string);
    //constructor for T Junction - data provided
    Junction(int, int, string, char);
    //contains four roads (with single direction and one traffic light)
    vector<Road> roadSeq = {
            Road('n', 50, 5),
            Road('e', 50, 5),
            Road('s', 50, 5),
            Road('w', 50, 5)
    };
    //execute light sequence functionality simultaneously with junction functionality
    thread simulate_one_tick();
    //iterates through roads that make up junction
    //initially points to the south road in the north direction (moving clockwise afterwards)
    vector<Road>::iterator currentRoad = roadSeq.begin();
    //each junction contains one pedestrian light
    //instance created with associated delay of 8 seconds for green state
    PedestrianLight* pedestrianLight = new PedestrianLight(8);
    //method to simulate one complete junction
    void tick();
    string name;
    //method to set traffic lights to work independently 
    void generateIndepSeq();
    //connects adjacent junctions in grid to the four roads of the current junction
    void setCloseJunctions(Junction*, Junction*, Junction*, Junction*);
    //pointers to the adjacent junctions
    Junction *westJunction = nullptr;
    Junction *eastJunction = nullptr;
    Junction *northJunction = nullptr;
    Junction *southJunction = nullptr;
    //variables associated with central point of junction
    int ctr_x = 100, ctr_y = 100;
};

#endif //TRAFFICLIGHTSYSTEM_JUNCTION_H
