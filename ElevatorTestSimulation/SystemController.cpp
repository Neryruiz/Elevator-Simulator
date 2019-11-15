#include <iostream>
#include <map>
#include <vector>

using  namespace std;


#include "SystemController.h"
#include "TrafficGenerator.h"

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