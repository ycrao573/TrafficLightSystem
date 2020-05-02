#ifndef TRAFFICLIGHTSYSTEM_CROSSJUNCTION_H
#define TRAFFICLIGHTSYSTEM_CROSSJUNCTION_H
#include "Junction.h"

class CrossJunction : Junction {
    //contains four roads(with single direction and one traffic light)
public:
    CrossJunction();
    CrossJunction(int ctr_x, int ctr_y);
    vector<Road> roadSeq = {

            Road('n', 50, 20),

            Road('e', 50, 20),

            Road('s', 50, 20),

            Road('w', 50, 20)
    };

    void setCloseJunctions(Junction*, Junction*, Junction*, Junction*);
    Junction* westJunction = nullptr;
    Junction* eastJunction = nullptr;
    Junction* northJunction = nullptr;
    Junction* southJunction = nullptr;
};

#endif //TRAFFICLIGHTSYSTEM_CROSSJUNCTION_H
