#include "TrafficLight.h"
#include <iostream>
#include "Windows.h"

TrafficLight::TrafficLight() {
    lastUpdate = 0;
    current_state = state_pair.begin();
    setDelays(this->delayPtr);
}

TrafficLight::TrafficLight(int* delayPtr) {
    lastUpdate = 0;
    current_state = state_pair.begin();
    setDelays(delayPtr);
}

bool TrafficLight::needsUpdate(int current_time)
{
    if ((current_time - lastUpdate) >= current_state->second){
        return true;
    }
    return false;
}

void TrafficLight::doUpdate(int current_time)
{
    ++current_state;
    if (current_state == state_pair.end()) {
        current_state = state_pair.begin();
    }
    lastUpdate = current_time;
}//1/4 cycle

void TrafficLight::run_one_cycle() {
    while(true){
//        cout << time << " " << getState() << endl;
        ++time;
        Sleep(1000);
        if(time % period == 0) {
            current_state = state_pair.begin();
//            cout << "end" << endl;
            break;
        }
        if(needsUpdate(time))
            doUpdate(time);
    }
}


string TrafficLight::getState()
{
    return current_state->first;
}

void TrafficLight::setDelays(int* delayPtr) {
    Rtime = state_pair[0].second = delayPtr[0];
    RAtime = state_pair[1].second = delayPtr[1];
    Gtime = state_pair[2].second = delayPtr[2];
    Atime = state_pair[3].second = delayPtr[3];
    period = Rtime + RAtime + Gtime + Atime;
}
