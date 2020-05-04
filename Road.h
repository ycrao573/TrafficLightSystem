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
    void setDirection(char direction);
    int getLength() const;
    void setLength(int length);
    int getWidth() const;
    void setWidth(int width);
    int str_x, str_y;
    void setStrPt(int, int);
    int delayPtr[4] = {1,1,5,1};
    TrafficLight *trafficLight = new TrafficLight(delayPtr);
    string roadName(char);
private:
    char direction;
    int length, width;

};


#endif //TRAFFICLIGHTSYSTEM_ROAD_H
