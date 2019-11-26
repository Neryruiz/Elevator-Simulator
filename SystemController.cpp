#include <iostream>
#include <map>
#include <vector>
#include "StatisticsKeeper.h"
using  namespace std;


#include "SystemController.h"
#include "TrafficGenerator.h"
#include "StringHelper.h"
#include "Elevators.h"
#include "timingWheel.h"
#include "partitions.h"


void SystemController::startElevator(int simulationtime)
{

    for(int i=1; i<=simulationtime; i++)
    {
        Levels = generate->generatePassengers();

    }

     // LEVEL DATA STRUCTURE
    for(int j = 0; j< Levels->size(); j++)
    {
        cout << "Floor : " << j << "  Passenger : " << endl;
        for(auto x:Levels->at(j))
        {
            cout << " ID : " << x->PassengerId << endl;
        }

    }


    cout << "\n";
    cout << "\t\t==============================================="<< endl;
    cout << "\t\t\t\t\t" << "Total Visitors  "<< StatisticsKeeper::visitorCounter  << endl;
    cout << "\t\t\t\t\t" << "Total Patients  "<< StatisticsKeeper::patientCounter  << endl;
    cout << "\t\t\t\t\t" << "Total Security personal  "<< StatisticsKeeper::securityStaffCounter  << endl;
    cout << "\t\t\t\t\t" << "Total Support Staff  "<< StatisticsKeeper::supportStaffCounter  << endl;
    cout << "\t\t\t\t\t" << "Total Medical Staff  "<< StatisticsKeeper::medicalStaffCounter  << endl;
    cout << "\t\t\t\t\t" << "Total Passenger Going Up "<< StatisticsKeeper::totalPassengerGoingUp  << endl;
    cout << "\t\t\t\t\t" << "Total Passenger Going Down "<< StatisticsKeeper::totalPassengerGoingDown  << endl;
    cout << "\t\t==============================================="<< endl;
    cout << "\n";


}


SystemController::SystemController(std::string p, int delay):path{p}
{
    /*
     * Constructor
     */

    // TrafficGenerator *generate;
    generate = TrafficGenerator::getinstance(path);

    PData = generate->PData;
    timewheel =  new timingWheel(maxFloor, delay, PData);
    delay = delay;

}

SystemController::~SystemController(){}


