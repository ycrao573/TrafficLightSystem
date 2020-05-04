//
// Created by RYC on 2020/4/14.
//

#ifndef TRAFFICLIGHTSYSTEM_JUNCTION_H
#define TRAFFICLIGHTSYSTEM_JUNCTION_H

#include "Road.h"
#include "PedestrianLight.h"

class Junction {
    //contains four roads(with single direction and one traffic light)
public:
    Junction();
    Junction(int, int, string);
    Junction(int, int, string, char);
    //contains four roads(with single direction and one traffic light)
    vector<Road> roadSeq = {
            Road('n', 50, 5),
            Road('e', 50, 5),
            Road('s', 50, 5),
            Road('w', 50, 5)
    };
    thread simulate_one_tick();
    vector<Road>::iterator currentRoad = roadSeq.begin();
    PedestrianLight* pedestrianLight = new PedestrianLight(8);
    void tick();
    string name;
    void generateIndepSeq();
    void setCloseJunctions(Junction*, Junction*, Junction*, Junction*);
    Junction *westJunction = nullptr;
    Junction *eastJunction = nullptr;
    Junction *northJunction = nullptr;
    Junction *southJunction = nullptr;
    bool isAdjacent;
    int ctr_x = 100, ctr_y = 100;
};

#endif //TRAFFICLIGHTSYSTEM_JUNCTION_H