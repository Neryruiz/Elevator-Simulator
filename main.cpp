#include <iostream>
#include "Visitors.h"
#include "TrafficGenerator.h"
#include "SystemController.h"
#include <map>
#include <vector>


int main() {


    std::string path = "/Users/soumilshah/CLionProjects/ElevatorTestSimulation/input.txt";
    int delay = 5;
    int simulationtime = 2;

    SystemController *systemcontroller;
    systemcontroller = new SystemController(path , delay);
    systemcontroller->startElevator(simulationtime);


    return 0;



}