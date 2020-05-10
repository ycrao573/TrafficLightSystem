#include "Road.h"

//function definition for constructor - no data provided
Road::Road() {
    //initialises predefined road
    this->direction = 'n';
    this->length = 50;
    this->width = 5;
}

//function definition for constructor - no data provided
Road::Road(char direction, int length, int width) {
    //initialises user defined road
    this->direction = direction;
    this->length = length;
    this->width = width;
}

Road::~Road() {
    if(trafficLight->time != 0)
        delete trafficLight;
}

//function definition for returning road direction
char Road::getDirection() const {
    return direction;
}

//function definition for returning road length
int Road::getLength() const {
    return length;
}

//function definition for returning road width
int Road::getWidth() const {
    return width;
}

//function definition for defining starting point of road
void Road::setStrPt(int x, int y) {
    str_x = x;
    str_y = y;
}

//function definition for returning road name
string Road::roadName(char) {
    switch (getDirection()) {
        case 'n':
            return "South Road";
        case 'w':
            return "East Road";
        case 's':
            return "North Road";
        case 'e':
            return "West Road";
        default:
            return "";
    }
}


