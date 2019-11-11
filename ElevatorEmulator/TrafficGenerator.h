#include <iostream>


#ifndef ELEVATOREMULATOR_TRAFFICGENERATOR_H
#define ELEVATOREMULATOR_TRAFFICGENERATOR_H


#include "TrafficGenerator.h"
#include "Probablity.h"
#include "FileRead.h"
#include "StringHelper.h"

#include "Passenger.h"
#include "Visitors.h"
#include "SupportStaff.h"
#include "MedicalStaff.h"
#include "SecurityPersonnel.h"
#include "Elevators.h"


class TrafficGenerator {

public:
    /*
     * Attributes
     */

    // Call FileRead class and sets Data Attributes in Constructor
    map<int, vector<std::string>> Data;
    map<int,vector<Passenger *>> Levels;


    string floor;
    string totalNumberElevator;
    string capacity;
    string TotalPassenger;


    vector<string> visitor;
    vector<string> patient;
    vector<string> supportstaff;
    vector<string> medicalstaff;
    vector<string> securitystaff;
    vector <Passenger *> PassengerGoingUp;
    vector <Passenger *> PassengerGoingDown;
    vector <Passenger *> PassengerGoingNone;



public:
    /*
     * Constructor and Destructor
     */
    TrafficGenerator();
    TrafficGenerator(std::string Path);
    ~TrafficGenerator();

public:
    /*
     * Methods
     */

    void  generateTraffic();
    void display(std::string name,vector<std::string> type, int count);
    void introducePassenger(int low, int high,Passenger *passenger []);
    void populateElevator();
    void displayFloorStatus();
    void addPassengerToVectors();

};


#endif //ELEVATOREMULATOR_TRAFFICGENERATOR_H
