//
// Created by RYC on 2020/4/14.
//

#ifndef TRAFFICLIGHTSYSTEM_JUNCTION_H
#define TRAFFICLIGHTSYSTEM_JUNCTION_H

#include "JunctionLight.h"
#include "Road.h"

class Junction {
//contains one junctionlight (four trafficlights), four roads(with single direction)
public:
    Junction();
    Junction(JunctionLight, vector<Road>);

};


#endif //TRAFFICLIGHTSYSTEM_JUNCTION_H
