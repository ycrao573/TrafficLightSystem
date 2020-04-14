#include "JunctionLight.h"
#include <iostream>

using namespace std;

JunctionLight::JunctionLight(int* delayPtr, int lightNum){
    light[0] = TrafficLight(delayPtr);
    light[1] = TrafficLight(delayPtr);
    light[2] = TrafficLight(delayPtr);
    light[3] = TrafficLight(delayPtr);
    lightSeq = {
            light[0], light[1], light[2]
    };
    if (lightNum == 4) {
        lightSeq.push_back(light[3]);
        this->lightNum = 4;
    }
    currentLight = lightSeq.begin();
}
bool JunctionLight::needsUpdate(int current_time)
{
    if ((current_time - last_time) >= currentLight->period)
    {
        return true;
        cout << "needsUpdate" << endl;
    }
    return false;
}

void JunctionLight::doUpdate(int current_time)
{
    //start the next light
    if (currentLight == lightSeq.end())
        currentLight = lightSeq.begin();
    else
        ++currentLight;
    cout << "Next Light Enabled" << endl;
    last_time = current_time;
}

void JunctionLight::goNext()
{
    ++junc_time;
    if (this->needsUpdate(junc_time)) {
        this->doUpdate(junc_time);
    }
    currentLight->addSecond();
    cout << "total time: "<< junc_time << " Light time: " << currentLight->time << " Color: " << currentLight->getState() << endl;
}
