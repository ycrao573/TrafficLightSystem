//
// Created by RYC on 2020/4/14.
//

#ifndef TRAFFICLIGHTSYSTEM_ROAD_H
#define TRAFFICLIGHTSYSTEM_ROAD_H

#include "TrafficLight.h"

class Road {
public:
    Road();
    Road(char, int, int);
    //~Road();
    TrafficLight trafficLight = TrafficLight();
    char getDirection() const;
    void setDirection(char direction);
    int getLength() const;
    void setLength(int length);
    int getWidth() const;
    void setWidth(int width);
    int delayPtr[4] = {2,1,2,1};
private:
    char direction;
    int length, width;

};


#endif //TRAFFICLIGHTSYSTEM_ROAD_H
