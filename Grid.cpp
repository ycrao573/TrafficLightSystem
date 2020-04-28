//
// Created by RYC on 2020/4/14.
//

#include <iostream>
#include "Grid.h"

Grid::Grid() {

}

void Grid::doNext() {
    for(; currentJunction!=myNetwork.end(); currentJunction++){
        currentJunction->simulate_one_tick();
    }
    cout << "New Network" << endl;
}

void Grid::Grid_Size(int length, int width) {
    for(i = 0; i < length; i++) {
        
    }
}

void Grid::restart() {
    //go back to login page
}

void Grid::sync(bool isSync) {
    if (isSync){
        ;
    }else{
        ;
    }
}
