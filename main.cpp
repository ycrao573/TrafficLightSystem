#include "Junction.h"
#include "TrafficLight.h"
#include "Windows.h"
#include "User.h"
#include "RoadUser.h"
#include "Pedestrian.h"
#include <iostream>
#include <thread>

using namespace std;

int main(){
//    int delay[4] = { 1,1,5,1 };
//    TrafficLight *tra = new TrafficLight(delay);
    Junction *junction = new Junction();
    RoadUser *logan = new RoadUser(*junction, junction->roadSeq[3]);

    thread t1 = junction->simulate_one_tick();
    thread t2 = logan->drive();

    t1.join();
    t2.join();

    // Both function are now running an different thread
    // We need to wait for them to finish
}