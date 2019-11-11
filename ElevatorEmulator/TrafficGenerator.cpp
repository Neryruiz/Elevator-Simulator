#include <iostream>
#include <istream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <iterator>


using namespace std;

#include "TrafficGenerator.h"
#include "Probablity.h"
#include "FileRead.h"
#include "StringHelper.h"
#include "RandomGenerator.h"


#include "Passenger.h"
#include "Visitors.h"
#include "SupportStaff.h"
#include "MedicalStaff.h"
#include "Security.h"
#include "Patients.h"
#include "ElevatorDirection.h"

#include "Elevators.h"

TrafficGenerator::~TrafficGenerator()
{

    // cout << "Traffic Generator No Args  Constructor " << endl;
}


TrafficGenerator::TrafficGenerator(std::string Path)
{
    FileRead *reader;
    reader = new FileRead();
    reader->readFile(Path);

    Data = reader->Data;                            // setting up Data so i can use Globally
    floor = reader->Data[1].at(0);                  // Row 1

    totalNumberElevator = reader->Data[2].at(0);    // Row 2
    capacity = reader->Data[2].at(1);               // Row 2

    // Row 3
    TotalPassenger = reader->Data[3].at(0);

    // Row 4  Visitors
    visitor = reader->Data[4];

    // Row 5 Patients
    patient = reader->Data[5];

    // Row 6 Support Staff
    supportstaff = reader->Data[6];

    // Row 7 Medical
    medicalstaff = reader->Data[7];

    // Row 8 Security
    securitystaff = reader->Data[8];

    // Elevator Logic
        Elevators *elevators[StringHelper::string_to_int(Data[2].at(0))];


        for (int i=0; i < StringHelper::string_to_int(Data[2].at(0)); i++){
            elevators[i] = new Elevators(StringHelper::string_to_int(Data[1].at(0)));
            elevators[i]->maxCapacity = StringHelper::string_to_int(Data[2].at(1));
        }

}

TrafficGenerator::TrafficGenerator(){
    // cout << "Destructor " << endl;
}


void TrafficGenerator::display(std::string name,vector<std::string> type, int count)
{
    cout << "\n";
    cout << "\t\t==============================="<< endl;
    cout << "\t\t\t\t\t" << name << endl;
    cout << "\t\t==============================="<< endl;
    cout << "\t\tStarted generation of "<< name  << endl;cout<<"\n";

}

void TrafficGenerator::introducePassenger(int low, int high, Passenger *passenger []){
    cout << "\n";
    cout << "\t\t==============================="<< endl;
    cout << "\t\t\t" << "Passenger in Bulding are : " << endl;
    cout << "\t\t==============================="<< endl;

    for(int i=low; i<high; i++)
    {
        cout << i << ")" << endl;
        passenger[i]->introduce();
    }
}

void TrafficGenerator::generateTraffic()
{

    display("visitors", visitor, Probablity::roundoff(Data[4].at(1),TotalPassenger ));
    Passenger *passenger[StringHelper::string_to_int(TotalPassenger)+1];


    /*
     * Visitors
     */


    for (int i=0; i<Probablity::roundoff(Data[4].at(1),TotalPassenger ); i++)
    {
        // Current Floor
        passenger[i] = new Visitors();
        passenger[i]->CurrentFloor = RandomGenerator::generateRandomNumber(0,
                StringHelper::string_to_int( Data[1].at(0)));

        // Destination Floor
        passenger[i]->DestinationFloor = RandomGenerator::generateRandomNumber(0,
                StringHelper::string_to_int( Data[1].at(0)));

        // Weights
        passenger[i]->Weight=1;

        // Passenger Direction
        passenger[i]->DirectionPassenger = ElevatorDirection::checkDirection(std::to_string(passenger[i]->CurrentFloor),
                std::to_string(passenger[i]->DestinationFloor));
    }

      /*
      * Patients
      */

    display("Patients", patient, Probablity::roundoff(Data[5].at(1), TotalPassenger));
    int PatientTotal = Probablity::roundoff(Data[5].at(1), TotalPassenger);

    // visitors previous index where its stops
    int v_p_index = Probablity::roundoff(Data[4].at(1),TotalPassenger );

    // for Loop should Go from
    // 2 to 2+3 items

    for (int i=v_p_index; i<v_p_index+PatientTotal; i++)
    {
        passenger[i] =  new Patients();
        passenger[i]->CurrentFloor = RandomGenerator::generateRandomNumber(0,
                StringHelper::string_to_int( Data[1].at(0)));


        passenger[i]->DestinationFloor = RandomGenerator::generateRandomNumber(0,
                StringHelper::string_to_int( Data[1].at(0)));

        passenger[i]->Weight= RandomGenerator::generateRandomNumber(StringHelper::string_to_int(Data[5].at(7)),
                                                                    StringHelper::string_to_int(Data[5].at(8)));

        // Passenger Direction
        passenger[i]->DirectionPassenger = ElevatorDirection::checkDirection(std::to_string(passenger[i]->CurrentFloor),
                                                                             std::to_string(passenger[i]->DestinationFloor));


    }


    /*
     * Support Staff
     */


    display("Support Staff", supportstaff, Probablity::roundoff(Data[6].at(2), TotalPassenger));
    // for loop goes from
    int s_p_index = v_p_index+PatientTotal;

    int SupportStaffTotal = Probablity::roundoff(Data[6].at(2), TotalPassenger);

    for(int i=s_p_index; i<s_p_index+SupportStaffTotal; i++)
    {
        passenger[i] = new SupportStaff();
        passenger[i]->CurrentFloor = RandomGenerator::generateRandomNumber(0,
                StringHelper::string_to_int( Data[1].at(0)));

        passenger[i]->DestinationFloor = RandomGenerator::generateRandomNumber(0,
                StringHelper::string_to_int( Data[1].at(0)));

        passenger[i]->Weight= RandomGenerator::generateRandomNumber(StringHelper::string_to_int(Data[6].at(8)),
                StringHelper::string_to_int(Data[6].at(9)));


        // Passenger Direction
        passenger[i]->DirectionPassenger = ElevatorDirection::checkDirection(std::to_string(passenger[i]->CurrentFloor),
                                                                             std::to_string(passenger[i]->DestinationFloor));
    }

     /*
     * Medical  Staff
     */

     display("Medical  Staff", medicalstaff, Probablity::roundoff(Data[7].at(2), TotalPassenger));

    // for loop goes from
    int m_p_index = s_p_index+PatientTotal;
    int MedicalStaffTotal = Probablity::roundoff(Data[7].at(2), TotalPassenger);

    for(int i=m_p_index; i<m_p_index+MedicalStaffTotal; i++)
    {
        passenger[i] = new MedicalStaff();
        passenger[i]->CurrentFloor = RandomGenerator::generateRandomNumber(0,
                                                                           StringHelper::string_to_int( Data[1].at(0)));

        passenger[i]->DestinationFloor = RandomGenerator::generateRandomNumber(0,
                                                                               StringHelper::string_to_int( Data[1].at(0)));
        passenger[i]->Weight=1;


        // Passenger Direction
        passenger[i]->DirectionPassenger = ElevatorDirection::checkDirection(std::to_string(passenger[i]->CurrentFloor),
                                                                             std::to_string(passenger[i]->DestinationFloor));
    }

    /*
    * Security Staff
    */

    display("Security Staff", securitystaff, Probablity::roundoff(Data[8].at(2), TotalPassenger));

    // for loop goes from
    int sec_p_index = m_p_index+MedicalStaffTotal;
    int SECStaffTotal = Probablity::roundoff(Data[8].at(2), TotalPassenger);

    for(int i=sec_p_index; i<sec_p_index+SECStaffTotal; i++)
    {
        passenger[i] = new SecurityPersonnel();
        passenger[i]->CurrentFloor = RandomGenerator::generateRandomNumber(0,
                                                                           StringHelper::string_to_int( Data[1].at(0)));

        passenger[i]->DestinationFloor = RandomGenerator::generateRandomNumber(0,
                                                                               StringHelper::string_to_int( Data[1].at(0)));

        passenger[i]->Weight=1;


        // Passenger Direction
        passenger[i]->DirectionPassenger = ElevatorDirection::checkDirection(std::to_string(passenger[i]->CurrentFloor),
                                                                             std::to_string(passenger[i]->DestinationFloor));
    }

    introducePassenger(0,StringHelper::string_to_int(TotalPassenger)+1, passenger);


        // LEVEL DATA STRUCTURE
        for(int j=0; j<StringHelper::string_to_int(TotalPassenger)+1; j++)
        {
            Levels[passenger[j]->CurrentFloor].push_back(passenger[j]);

        }


}


void TrafficGenerator::displayFloorStatus()
{
    cout << "\n";
    cout << "\t\t==============================="<< endl;
    cout << "\t\t\t\t\t" << "Passenger at Each Floor " << endl;
    cout << "\t\t==============================="<< endl;
    cout << "\n";


    for(int i=0;i<StringHelper::string_to_int(Data[1].at(0)); i++)
    {
        cout << "Floor : " << i << "  Passenger : " ;

        for (auto x: Levels[i])
        {
            cout << x->PassengerId << " ";
        }cout << "\n";

    }
}


void TrafficGenerator::addPassengerToVectors()
{
    // For Each Floor
    for(int i=0;i<StringHelper::string_to_int(Data[1].at(0)); i++)
    {
        // Each Passenger in Each Floor Check
        // Whether Going up or Down

        for (auto x: Levels[i])
        {

            if (x->DirectionPassenger == 'U')
            {
                // push the pointer of that passenger
                PassengerGoingUp.push_back(x);
            }

            if (x->DirectionPassenger == 'D')
            {
                PassengerGoingDown.push_back(x);
            }

            if (x->DirectionPassenger == 'N')
            {
                PassengerGoingNone.push_back(x);
            }

        }
    }
}


void TrafficGenerator::populateElevator()
{
    /*
     * once the Traffic is generated and populated in Levels
     * we want to push everyone in Queue
     * we have two Queue Up and Down
     * we need to Iterate over LevelFloor Data Structure
     */

    displayFloorStatus();
    addPassengerToVectors();
}
