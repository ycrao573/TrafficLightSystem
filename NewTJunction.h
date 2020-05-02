#ifndef TRAFFICLIGHTSYSTEM_TJUNCTION_H
#define TRAFFICLIGHTSYSTEM_TJUNCTION_H
#include "Junction.h"

class TJunction : Junction {
    //contains three roads(with single direction and one traffic light)
public:
    TJunction();
    TJunction(int ctr_x, int ctr_y);
    vector<Road> roadSeq = {
            Road('e', 50, 20),

            Road('s', 50, 20),

            Road('w', 50, 20)
    };

    void setCloseJunctions(Junction*, Junction*, Junction*);
    Junction* westJunction = nullptr;
    Junction* eastJunction = nullptr;
    Junction* southJunction = nullptr;
};

#endif //TRAFFICLIGHTSYSTEM_TJUNCTION_H
