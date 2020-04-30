#ifndef TRAFFICLIGHTSYSTEM_T_JUNCTION_H

#define TRAFFICLIGHTSYSTEM_T_JUNCTION_H



#include "Road.h"
#include "Junction.h"
#include "PedestrianLight.h"



class Junction: T_Junction {

//contains three roads(with single direction and one traffic light)

public:
    Junction();
    Junction(int ctr_x, int ctr_y);
//    Junction(vector<Road>);

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

    thread simulate_one_tick();

    vector<Road>::iterator currentRoad = roadSeq.begin();

    PedestrianLight pedestrianLight;

    int ctr_x = 100, ctr_y = 100;

    int last_time = 0;

    void tick();



    void setCloseJunctions(Junction*, Junction*, Junction*, Junction*);

    Junction *westJunction = nullptr;

    Junction *eastJunction = nullptr;

    Junction *northJunction = nullptr;

    Junction *southJunction = nullptr;

};





#endif //TRAFFICLIGHTSYSTEM_T_JUNCTION_H
