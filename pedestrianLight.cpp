//
// Created by RYC on 2020/4/26.
//
#include "Windows.h"
#include "pedestrianLight.h"

PedestrianLight::PedestrianLight() {
    setDelays(this->period);
}

PedestrianLight::PedestrianLight(int period) {
    setDelays(period);
}

//bool PedestrianLight::needsUpdate(int current_time) {
//    return false;
//}
//
//void PedestrianLight::doUpdate(int current_time) {
//
//}

void PedestrianLight::setDelays(int period) {
    this->period = period;
}

void PedestrianLight::run_one_cycle() {
    canPass = true;
    Sleep(1000 * period);
    canPass = false;
}
