#ifndef TRAFFICLIGHTSYSTEM_ROAD_H
#define TRAFFICLIGHTSYSTEM_ROAD_H

#include "TrafficLight.h"
//required for random generator function
#include "stdlib.h"

//class to store attributes and methods associated with a road
class Road {
public:
    //constructor - creates instance when no data is provided
    Road();
    //constructor - creates instance when data is provided
    Road(char, int, int);
    //destructor - destroys instance of class
    ~Road();
    char getDirection() const;
    int getLength() const;
    int getWidth() const;
    //variables associated to start point of road
    int str_x, str_y;
    void setStrPt(int, int);
    //each road contains one traffic light
    //implemented via creation of instance pointed to via a pointer
    TrafficLight *trafficLight = new TrafficLight();
    string roadName(char);
private:
    char direction;
    int length, width;
};

#endif //TRAFFICLIGHTSYSTEM_ROAD_H
