#include <iostream>
#include <map>
#include <vector>

using  namespace std;


#include "SystemController.h"
#include "TrafficGenerator.h"
#include "StringHelper.h"
#include "Elevators.h"


void SystemController::startElevator()
{
    numberElevator = StringHelper::string_to_int(PData[0][0][1]);
    maxCapacity = StringHelper::string_to_int(PData[0][0][2]);

    // steps
    /*
     * Create Elevator Pointer Array
     * create objects for number of Elevator
     * Set the Direction of Elevator as Going Up
     * Set the low and high Floor
     *
     */
//
//    Elevators *elevator[numberElevator];
//
//    for(int i=0; i<numberElevator; i++)
//    {
//        elevator[i] = new Elevators();
//    }
//
//    for(int i=0; i<numberElevator; i++)
//    {
//        elevator[i]->elevatorIntroduce();
//    }


}


SystemController::SystemController(std::string p, int epoch):path{p},epoch{epoch}
{

    // create  a  object of Traffic Generator
    TrafficGenerator *generate;
    generate = new TrafficGenerator(path);

    for(int i=0; i<epoch; i++)
    {
        generate->generatePassengers();
    }

    Levels = generate->Levels;
    PData= generate->PData;
    generate->displayPassenger();
}

SystemController::~SystemController()
{

}


void SystemController::generateTraffic(int epoch)
{

}