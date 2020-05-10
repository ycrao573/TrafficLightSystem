//Windows.h required for sleep functionality
#include "Windows.h"
#include "pedestrianLight.h"

//function definition for constructor - no data provided
PedestrianLight::PedestrianLight() {
    //predefined delays utilised
    setDelays(this->period);
}

//function definition for constructor - data provided
PedestrianLight::PedestrianLight(int period) {
    //user defined delays utilised
    setDelays(period);
}

//function definition for delay of green state
void PedestrianLight::setDelays(int period) {
    this->period = period;
}

//function definition for one light sequence 
void PedestrianLight::run_one_cycle() {
    //pedestrain can cross while current time is less than period of green state
    canPass = true;
    int count = 0;
    while(count < period){
        //sleep used to generate 1 second time interval between each iteration of count
        Sleep(1000);
        count++;
    }
    canPass = false;
}
