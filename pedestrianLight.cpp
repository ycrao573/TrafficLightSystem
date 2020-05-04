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

void PedestrianLight::setDelays(int period) {
    this->period = period;
}

void PedestrianLight::run_one_cycle() {
    canPass = true;
    int count = 0;
    while(count < period){
        Sleep(1000);
        count++;
    }
    canPass = false;
}
