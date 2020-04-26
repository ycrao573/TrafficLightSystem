//
// Created by RYC on 2020/4/26.
//
#include "Windows.h"
#include "pedestrianLight.h"

PedestrianLight::PedestrianLight() {
    current_state = state.begin();
    setDelays(this->period);
}

PedestrianLight::PedestrianLight(int period) {
    current_state = state.begin();
    setDelays(period);
}

//bool PedestrianLight::needsUpdate(int current_time) {
//    return false;
//}
//
//void PedestrianLight::doUpdate(int current_time) {
//
//}

string PedestrianLight::getState() {
    return *current_state;
}

void PedestrianLight::setDelays(int period) {
    this->period = period;
}

void PedestrianLight::run_one_cycle() {
    while(true){
        *current_state = state[1];
//        cout << "Pedestrian State: " << *current_state << endl;
        ++ped_time;
        Sleep(1000);
        if(ped_time % period == 0) {
            current_state = state.begin();
            break;
        }
    }
}
