#include "Junction.h"
#include "TrafficLight.h"
#include "Windows.h"
#include "User.h"
#include "RoadUser.h"
#include "Pedestrian.h"
#include "PedestrianLight.h"
#include <iostream>
#include <thread>

using namespace std;

int main(){
//    roadSeq = {N,E,S,W}
//    int delay[4] = { 1,1,5,1 };
//    TrafficLight *tra = new TrafficLight(delay);
    Junction *junction1 = new Junction();
    Junction *junction2 = new Junction();
    junction1->setCloseJunctions(junction2, nullptr, nullptr, nullptr);

    RoadUser *logan = new RoadUser(*junction1, junction1->roadSeq[0]);
    logan->setNextJunction(*junction2);

    thread t1 = junction1->simulate_one_tick();
    thread t2 = junction2->simulate_one_tick();
    thread t3 = logan->drive();

    t1.join();
    Sleep(5);
    t2.join();
    Sleep(5);
    t3.join();



    // Both function are now running an different thread
    // We need to wait for them to finish
}