//
// Created by RYC on 2020/4/14.
//

#include <iostream>
#include "Grid.h"


Grid::Grid() {

}

Grid::Grid(int len, int wid) {
    this->len = len;
    this->wid = wid;
    if (len == 1 && wid == 1)    //1*1 grid
    {
        Junction *junction1 = new Junction(100, 100);
        junction1->setCloseJunctions(nullptr, nullptr, nullptr, nullptr);
        myNetwork.push_back(junction1);
    }
    if (len == 2 && wid == 2)    //2*2 grid
    {
        //1 2
        //3 4
        //Junction* west, Junction* east, Junction* north, Junction* south
        Junction *junction1 = new Junction(100, 100);
        Junction *junction2 = new Junction(150, 100);
        Junction *junction3 = new Junction(100, 150);
        Junction *junction4 = new Junction(150, 150);
        junction1->setCloseJunctions(nullptr, junction2, nullptr, junction3);
        junction4->setCloseJunctions(junction3, nullptr, junction2, nullptr);
        myNetwork.push_back(junction1);
        myNetwork.push_back(junction2);
        myNetwork.push_back(junction3);
        myNetwork.push_back(junction4);
        cout << "Here is the grid created: " << endl << endl
             << " junction1    junction2 " << endl << endl << endl
             << " junction3    junction4 " << endl << endl;
    }
}

void Grid::sync(bool isSync) {
    if (isSync){
        ;
    }else{
        ;
    }
}
