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
#include "DateTime.h"
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

//    // Elevator Logic
//        Elevators *elevators[StringHelper::string_to_int(Data[2].at(0))];
//
//        for (int i=0; i < StringHelper::string_to_int(Data[2].at(0)); i++){
//            elevators[i] = new Elevators(StringHelper::string_to_int(Data[1].at(0)));
//            elevators[i]->maxCapacity = StringHelper::string_to_int(Data[2].at(1));
//        }

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

    // display("visitors", visitor, Probablity::roundoff(Data[4].at(1),TotalPassenger ));
    Passenger *passenger[StringHelper::string_to_int(TotalPassenger)+1];
    // cout << "=== "<< StringHelper::string_to_int(TotalPassenger)+1 << endl;

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

    // display("Patients", patient, Probablity::roundoff(Data[5].at(1), TotalPassenger));
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


    // display("Support Staff", supportstaff, Probablity::roundoff(Data[6].at(2), TotalPassenger));

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

     // display("Medical  Staff", medicalstaff, Probablity::roundoff(Data[7].at(2), TotalPassenger));

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

    // display("Security Staff", securitystaff, Probablity::roundoff(Data[8].at(2), TotalPassenger));

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

     // introducePassenger(0,StringHelper::string_to_int(TotalPassenger)+1, passenger);

        // LEVEL DATA STRUCTURE
        for(int j=0; j<StringHelper::string_to_int(TotalPassenger)+1; j++)
        {
            Levels[passenger[j]->CurrentFloor].push_back(passenger[j]);

        }


}


void TrafficGenerator::displayFloorStatus()
{
    cout << "\n";
    cout << "\t\t==============================================="<< endl;
    cout << "\t\t\t\t\t" << "Passenger at Each Floor " << endl;
    cout << "\t\t==============================================="<< endl;
    cout << "\n";


    for(int i=0;i<=StringHelper::string_to_int(Data[1].at(0)); i++)
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
    for(int i=0;i<=StringHelper::string_to_int(Data[1].at(0)); i++)
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


void TrafficGenerator::passengerIntroduce()
{

    cout << "\n";
    cout << "\t\t==============================="<< endl;
    cout << "\t\t\t\t\t" << " Total Passenger Generated   " << endl;
    cout << "\t\t==============================="<< endl;
    cout << "\n";

    // for each level call introduce  Method
    for (int i=0; i<Levels.size(); i++)
    {
        for(auto j:Levels[i])
        {
            j->introduce();
        }

    }


}

void TrafficGenerator::passengerGoingUpSummary()
{

    int TotalWeightcounter = 0;

    cout << "\n";
    cout << "\t\t========================================================"<< endl;
    cout << "\t\t\t\t\t" << " Passenger going Up Weight Summary  " << endl;
    cout << "\t\t======================================================="<< endl;
    cout << "\n";

    for (int i=0; i<Levels.size(); i++)
    {

        for (auto x: Levels[i])
        {
            if (x->DirectionPassenger == 'U')
            {
                TotalWeightcounter = TotalWeightcounter +  x->Weight;
                cout << "\t\t"<< "Passenger ID: " << x->PassengerId << " Weight :" << x->Weight << endl;

            }
        }
    }

    cout << "\t\t---------------------------------------------------------"<< endl;
    cout << "\t\t" << " Total Weight of Passenger Going Up :" <<TotalWeightcounter << endl;
    cout << "\t\t---------------------------------------------------------\""<< endl;

    TotalWeightcounter = 0;
    cout << "\n";

}

void TrafficGenerator::passengerFoingDownSummary()
{

    int TotalWeightcounter = 0;

    cout << "\n";
    cout << "\t\t========================================================"<< endl;
    cout << "\t\t\t\t\t" << " Passenger going Down Weight Summary  " << endl;
    cout << "\t\t======================================================="<< endl;
    cout << "\n";

    for (int i=0; i<Levels.size(); i++)
    {

        for (auto x: Levels[i])
        {
            if (x->DirectionPassenger == 'D')
            {
                TotalWeightcounter = TotalWeightcounter +  x->Weight;
                cout << "\t\t"<< "Passenger ID: " << x->PassengerId << " Weight :" << x->Weight << endl;

            }
        }
    }

    cout << "\t\t========================================================"<< endl;
    cout << "\t\t" << " Total Weight of Passenger Going Down :" <<TotalWeightcounter << endl;
    cout << "\t\t======================================================="<< endl;

    TotalWeightcounter = 0;
    cout << "\n";

}

void TrafficGenerator::populateElevator()
{
    /*
     * once the Traffic is generated and populated in Levels
     * we want to push everyone in Queue
     * we have two Queue Up and Down
     * we need to Iterate over LevelFloor Data Structure
     */


    passengerIntroduce();           // call the introduce methods on all passenger in bulding
    displayFloorStatus();           // display floor status for each passenger
    addPassengerToVectors();        // add all the up going passenger to up and down queue
    passengerGoingUpSummary();      // Passenger going up Weight Summary
    passengerFoingDownSummary();    // Passenger going Down Summary



    Elevators *elevators[StringHelper::string_to_int(Data[2].at(0))];

    int TotalElevatorCount = StringHelper::string_to_int(Data[2].at(0));
    int TotalNumberElevatorGoingUp = TotalElevatorCount / 2;
    int TotalNumberofElevatorgoingDown = TotalElevatorCount - TotalNumberElevatorGoingUp ;


    // for each 4 elevator
    for (int i=0; i < StringHelper::string_to_int(Data[2].at(0)); i++)
    {
        elevators[i] = new Elevators();

        // First Two Elevators are Starting from Level 0
        // initialize the Char to U
        elevators[i]->directionElevator= 'U';
        elevators[i]->maxCapacity = StringHelper::string_to_int(Data[2].at(1));


    }

    cout << "\n";
    cout << "\t\t==============================="<< endl;
    cout << "\t\t\t\t\t" << "Elevators are Ready" << endl;
    cout << "\t\t==============================="<< endl;
    cout << "\n";

    for(int j=0; j<TotalElevatorCount; j++)
    {
        elevators[j]->elevatorIntroduce();
    }

    cout << "\n";
    cout << "\t\t============================================="<< endl;
    cout << "\t\t\t\t\t" << "Elevators are Now Starting" << endl;
    cout << "\t\t=============================================="<< endl;
    cout << "\n";


    /*
     * Here There should be one more loop for each Elevators
     * for each floor
     * for each passenger on that floow
     * condition
     * chech if counterwt ic < max capacity
     * add in queue
     * if no
     * next elevator will serve them
     */


    // For the First Elevator
    for (int j=0; j<1 ; j++)
    {
        // cout << "Elevator Id " << elevators[j]->ElevatorId << endl;

        // For Each all Floors
        for(int i=0;i<=StringHelper::string_to_int(Data[1].at(0)); i++)
        {
            // cout << "\tFloor : " << i << "  Passenger : " << endl;
            elevators[j]->elevatorCurrentFloor = i ;


            // For all Passengers on that Floor
            for (auto x: Levels[i])
            {
                // check if the Passenger are UP passengers

                if (x->DirectionPassenger == 'U')
                {
                    /*
                     * what you need to do is add these passenger into queue
                     * check and see if counterweight is < Max Weight
                     * if less than server the passenger
                     * if exceeeds than next elevator will serve that passengers
                     */

                    // Add the weight to the weight couter
                    elevators[j]->ElevatorWeightCounter = elevators[j]->ElevatorWeightCounter  + x->Weight;

                    //check for condition that if weight is less than maximum capacity

                    if(elevators[j]->ElevatorWeightCounter <= elevators[j]->maxCapacity
                    and x->CurrentFloor == elevators[j]->elevatorCurrentFloor )
                    {
                        x->CreationRTime = DateTime::getDateTime();
                        elevators[j]->Up.push(x);

                        cout << "\n";
                        cout << "\t\t==============================="<< endl;
                        cout << "\t\t" << "passenger Getting ON the  Lift " << endl;
                        cout << "\t\t" << "Id :" << x->PassengerId << endl;
                        cout << "\t\tGot in on Floor " << x->CurrentFloor <<endl;
                        cout << "\t\tTime of Enter " << DateTime::getDateTimechar() << endl;
                        cout << "\t\t==============================="<< endl;
                        cout << "\n";


                        /*
                         * check for condition
                         * Elevator current Floor is ==  Passenger Dest floor
                         * if yes
                         * then
                         * pop from the  queue
                         * and decrement the counter
                         * and update the time
                         * and print out the time elapsed
                         *
                         */

                    }

                    if (elevators[j]->elevatorCurrentFloor == x->DestinationFloor)
                    {

                        /*
                         * then pop the person
                         * update the Dest floor
                         * update the elapsed time
                         */

                        // Store that into a pointer
                        Passenger *tem;
                        tem = elevators[j]->Up.front();
                        x->GetOffTime =DateTime::getDateTime();

                        elevators[j]->ElevatorWeightCounter = elevators[j]->ElevatorWeightCounter  - x->Weight;

                        cout << "\n";
                        cout << "\t\t==============================="<< endl;
                        cout << "\t\t" << "passenger Getting OFF " << endl;
                        cout << "\t\t" << "Id :" << x->PassengerId << endl;
                        cout << "\t\tGot in off Floor " << x->DestinationFloor <<  endl;
                        cout << "\t\tTime of Enter " << DateTime::getDateTimechar() << endl;
                        cout << "\t\t==============================="<< endl;
                        cout << "\n";

                    }

                }

            }cout << "\n";
        }
    }

}
