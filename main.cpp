#include "JunctionLight.h"
#include "TrafficLight.h"
#include "Windows.h"
#include <iostream>

using namespace std;

int main(){
    int delay[4] = { 1,1,5,1 };
    JunctionLight* junction = new JunctionLight(delay, 3);
    TrafficLight* tra = new TrafficLight(delay);
    while (true) {
        junction->goNext();
        Sleep(1000);
    }
}