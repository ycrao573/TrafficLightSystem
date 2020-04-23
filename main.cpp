#include "Junction.h"
#include "TrafficLight.h"
#include "Windows.h"
#include "RoadUser.h"
#include <iostream>
#include <thread>

using namespace std;

int main(){
//    int delay[4] = { 1,1,5,1 };
//    TrafficLight *tra = new TrafficLight(delay);
    Junction *junction = new Junction();
    junction->simulate_one_tick();
    RoadUser* logan = new RoadUser(*junction, junction->roadSeq[3]);
    logan->move();

    // Both function are now running an different thread
    // We need to wait for them to finish
}