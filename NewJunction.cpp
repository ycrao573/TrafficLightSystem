#include "Junction.h"
#include <iostream>
using namespace std;

Junction::Junction() {
    CrossJunction();
}


Junction::Junction(string Junc_Type) {
    if (Junc_Type == "Cross")
        CrossJunction();
    else
        TJunction();
}

void Junction::tick() {//north -> north

    while (true) {

        //activate trafficlight

        if (currentRoad == roadSeq.end()) {

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

    return thread([this] { this->tick(); });

}

void Junction::setCloseJunctions(Junction* west, Junction* east, Junction* north, Junction* south) {

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


