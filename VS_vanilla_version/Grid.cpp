//
// Created by RYC on 2020/4/14.
//

#include <iostream>
#include "Grid.h"

//function defintion for a constructor - no data provided
//never occurs as user is repeatedly prompted to give grid dimensions
Grid::Grid() {
}

//function defintion for a constructor - data provided
Grid::Grid(int len, int wid) {
    //user defined grid dimensions (length and width)
    this->len = len;
    this->wid = wid;
    if (len == 1 && wid == 1)    //1*1 grid
    {
        //push_back functionality utilised to add new junction element to myNetwork vector
        //associated central point of junction is also added to same element of myNetwork vector 
        myNetwork.push_back(new Junction(100, 100, "Junction 1"));
        //connects junction (comprised of four roads) to no junctions
        //in this case since it is 1*1, there are no other junctions, so pointers to the other junctions are null
        myNetwork[0]->setCloseJunctions(nullptr, nullptr, nullptr, nullptr);
    }
    else if (len == 2 && wid == 1) {  //1*2 grid
        myNetwork.push_back(new Junction(100, 100, "Junction 1"));
        myNetwork.push_back(new Junction(150, 100, "Junction 2"));
        //in this case since it is 1*2, there is 1 other junction in the east direction, so all but 1 pointer is null
        myNetwork[0]->setCloseJunctions(nullptr, myNetwork[1], nullptr, nullptr);
    }
    else if (len == 1 && wid == 2) {  //2*1 grid
        myNetwork.push_back(new Junction(100, 100, "Junction 1"));
        myNetwork.push_back(new Junction(100, 150, "Junction 2"));
        //in this case since it is 2*1, there is 1 other junction in the south direction, so all but 1 pointer is null
        myNetwork[0]->setCloseJunctions(nullptr, nullptr, nullptr, myNetwork[2]);
    }
    else if (len == 2 && wid == 2)    //2*2 grid
    {
        //1 2
        //3 4
        myNetwork = {
                new Junction(100, 100, "Junction 1"),
                new Junction(150, 100, "Junction 2"),
                new Junction(100, 150, "Junction 3"),
                new Junction(150, 150, "Junction 4")
        };
        //connects junction 1 (comprised of four roads) to two other junctions
        //in this case since it is 2*2, there is 1 other junction in the east direction and another in the south,
        //so all but 2 pointers are null
        myNetwork[0]->setCloseJunctions(nullptr, myNetwork[1], nullptr, myNetwork[2]);
        //connects junction 4 (comprised of four roads) to two other junctions
        //in this case since it is 2*2, there is 1 other junction in the west direction and another in the north,
        //so all but 2 pointers are null
        myNetwork[3]->setCloseJunctions(myNetwork[2], nullptr, myNetwork[1], nullptr);
        cout << "Here is the grid created: \n\n\n"
            << " junction1    junction2 \n\n\n"
            << " junction3    junction4 \n\n\n";
    }
    else if (len == 3 && wid == 3)   //3*3 grid
    {
        myNetwork = {
                new Junction(100, 100, "Junction 1"),
                new Junction(150, 100, "Junction 2"),
                new Junction(200, 100, "Junction 3"),
                new Junction(100, 150, "Junction 4"),
                new Junction(150, 150, "Junction 5"),
                new Junction(200, 150, "Junction 6"),
                new Junction(100, 200, "Junction 7"),
                new Junction(150, 200, "Junction 8"),
                new Junction(200, 200, "Junction 9"),
        };
        //        0   1   2
        //        3   4   5
        //        6   7   8;
        myNetwork[1]->setCloseJunctions(myNetwork[0], myNetwork[2], nullptr, myNetwork[4]);
        myNetwork[3]->setCloseJunctions(nullptr, myNetwork[4], myNetwork[0], myNetwork[6]);
        myNetwork[5]->setCloseJunctions(myNetwork[4], nullptr, myNetwork[2], myNetwork[8]);
        myNetwork[7]->setCloseJunctions(myNetwork[6], myNetwork[8], myNetwork[4], nullptr);
        cout << "Here is the grid created: \n\n\n"
            << " junction1    junction2    junction3\n\n\n"
            << " junction4    junction5    junction6\n\n\n"
            << " junction7    junction8    junction9\n\n\n";
    }
}

//function defintion for a destructor for grid
Grid::~Grid() {
    if (!myNetwork.empty())
        myNetwork.clear();
}
