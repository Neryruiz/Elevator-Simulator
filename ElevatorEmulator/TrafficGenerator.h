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


class TrafficGenerator {

public:
    /*
     * Attributes
     */

    // Call FileRead class and sets Data Attributes in Constructor
    map<int, vector<std::string>> Data;
    string floor;

    string totalNumberElevator;
    string capacity;

    string TotalPassenger;


    vector<string> visitor;
    vector<string> patient;
    vector<string> supportstaff;
    vector<string> medicalstaff;
    vector<string> securitystaff;

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

    void generateTraffic();

};


#endif //ELEVATOREMULATOR_TRAFFICGENERATOR_H
