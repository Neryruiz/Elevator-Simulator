#include <iostream>
#include <map>
#include <vector>

using  namespace std;


#include "SystemController.h"
#include "TrafficGenerator.h"
#include "StringHelper.h"
#include "Elevators.h"
#include "Display.h"
#include "timingWheel.h"
#include "partitions.h"


void SystemController::startElevator()
{
    Display::displayDestinationFloors(LevelDest);

    //    int timeunite;
    //    timeunite  = delay * (maxFloor + 1);

    //timewheel->schedule();


}


SystemController::SystemController(std::string p, int epoch, int delay):path{p},epoch{epoch}
{
    /*
     * Constructor
     * Populates the Level for Specified Epoch
     * TrafficGenerator class is called
     * TrafficGenerator is singelton Design pattern
     */

    // System Controller calls the Traffic Generator
    TrafficGenerator *generate;
    generate = TrafficGenerator::getinstance(path);

    for(int i=0; i<epoch; i++)
    {
        generate->generatePassengers();
    }

    Levels = generate->Levels;
    PData= generate->PData;
    generate->displayPassenger();

    // Reverse Mapping for Destination Floor and Passengers
    for (int i=0; i<Levels.size(); i++)
    {
        for(auto x: Levels[i])
        {
            LevelDest[x->DestinationFloor].push_back(x);
        }
    }

    numberElevator = StringHelper::string_to_int(PData[0][0][1]);       // Number of Elevator
    maxCapacity = StringHelper::string_to_int(PData[0][0][2]);          // max Capacity
    maxFloor = StringHelper::string_to_int(PData[0][0][0]);             // max Floors

    // Create a map of bool
    // map<int ,bool>

    for(int i=0; i<Levels.size(); i++)
    {
        if(Levels[i].size()>0)      // which check is there is any passenges
        {
            floorStatus[i]= true;
        }
        else
            {
                floorStatus[i]= false;
            }
    }


    timewheel =  new timingWheel(maxFloor, delay, Levels, PData);
    delay = delay;

}

SystemController::~SystemController()
{

}


