//
// Created by RYC on 2020/4/14.
//

#ifndef TRAFFICLIGHTSYSTEM_ROAD_H
#define TRAFFICLIGHTSYSTEM_ROAD_H

#include "TrafficLight.h"
#include "stdlib.h"

class Road {
public:
    Road();
    Road(char, int, int);
    //~Road();
    char getDirection() const;
    int getLength() const;
    int getWidth() const;
    int str_x, str_y;
    void setStrPt(int, int);
    TrafficLight *trafficLight = new TrafficLight();
    string roadName(char);
private:
    char direction;
    int length, width;

};


#endif //TRAFFICLIGHTSYSTEM_ROAD_H
