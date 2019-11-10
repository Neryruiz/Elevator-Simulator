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
    // cout << "floor :\t" << floor << endl;

    totalNumberElevator = reader->Data[2].at(0);    // Row 2
    capacity = reader->Data[2].at(1);               // Row 2
    // cout << "Capacity:\t" << capacity << endl;
    // cout << "Total Elevator :\t" << totalNumberElevator << endl;

    // Row 3
    TotalPassenger = reader->Data[3].at(0);
    // cout << "Total Passengers " << TotalPassenger << endl;

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

}

TrafficGenerator::TrafficGenerator(){
    // cout << "Destructor " << endl;
}

void TrafficGenerator::generateTraffic()
{
    cout << "\n";
    cout << "========================================================================================"<< endl;cout<<"\n";
    cout << "======================="<< endl;
    cout << "Visitors"<< endl;
    cout << "======================="<< endl;

    cout << "Started generation of Passenger ------>" << endl;cout<<"\n";cout<<"\n";
    cout << "Generating  Visitors based on following Specification------- > " << endl;
    for(auto x:visitor){cout << x<< " ";}cout <<"\n";
    cout << "\n";

    cout << "Total Visitors Generated " << Probablity::roundoff(Data[4].at(1),TotalPassenger ) << endl;


    Passenger *passenger[StringHelper::string_to_int(TotalPassenger)];


    /*
     * Visitors
     */


    for (int i=0; i<Probablity::roundoff(Data[4].at(1),TotalPassenger ); i++)
    {
        passenger[i] = new Visitors();
        passenger[i]->CurrentFloor = RandomGenerator::generateRandomNumber(0,
                StringHelper::string_to_int( Data[1].at(0)));

        passenger[i]->DestinationFloor = RandomGenerator::generateRandomNumber(0,
                StringHelper::string_to_int( Data[1].at(0)));
    }

    for (int i=0; i<Probablity::roundoff(Data[4].at(1),TotalPassenger); i++)
    {
        passenger[i]->introduce();
    }



    /*
      * Patients
      */

    int PatientTotal = Probablity::roundoff(Data[5].at(1), TotalPassenger);

    // visitors previous index where its stops
    int v_p_index = Probablity::roundoff(Data[4].at(1),TotalPassenger );

    // for Loop should Go from
    // 2 to 2+3 items

    cout << "========================================================================================"<< endl;cout<<"\n";
    cout << "======================="<< endl;
    cout << "Patients"<< endl;
    cout << "======================="<< endl;


    cout << "\n";
    cout << "Generating Passengers based on Requirment Specified " << endl;
    cout << "\n";
    for(auto x:patient){cout << x << " ";}cout<<"\n";

    for (int i=v_p_index; i<v_p_index+PatientTotal; i++)
    {
        passenger[i] =  new Patients();
        passenger[i]->CurrentFloor = RandomGenerator::generateRandomNumber(0,
                StringHelper::string_to_int( Data[1].at(0)));


        passenger[i]->DestinationFloor = RandomGenerator::generateRandomNumber(0,
                StringHelper::string_to_int( Data[1].at(0)));
    }

    for (int i=v_p_index; i<v_p_index+PatientTotal; i++)
    {
        passenger[i]->introduce();

    }



    /*
     * Support Staff
     */

    cout << "========================================================================================"<< endl;cout<<"\n";
    cout << "======================="<< endl;
    cout << "Support Staff"<< endl;
    cout << "======================="<< endl;

    cout << "\n";
    cout << "Generating Passengers based on Requirment Specified " << endl;
    cout << "\n";
    for(auto x:supportstaff){cout << x << " ";}cout<<"\n";

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
    }

    for(int i=s_p_index; i<s_p_index+SupportStaffTotal; i++)
    {
        passenger[i]->introduce();
    }






    /*
 * Support Staff
 */

    cout << "========================================================================================"<< endl;cout<<"\n";
    cout << "======================="<< endl;
    cout << "Medical  Staff"<< endl;
    cout << "======================="<< endl;

    cout << "\n";
    cout << "Generating Medical  Staff based on Requirment Specified " << endl;
    cout << "\n";
    for(auto x:medicalstaff){cout << x << " ";}cout<<"\n";

    // for loop goes from
    int m_p_index = v_p_index+PatientTotal;
    int MedicalStaffTotal = Probablity::roundoff(Data[7].at(2), TotalPassenger);

    for(int i=m_p_index; i<m_p_index+MedicalStaffTotal; i++)
    {
        passenger[i] = new MedicalStaff();
        passenger[i]->CurrentFloor = RandomGenerator::generateRandomNumber(0,
                                                                           StringHelper::string_to_int( Data[1].at(0)));

        passenger[i]->DestinationFloor = RandomGenerator::generateRandomNumber(0,
                                                                               StringHelper::string_to_int( Data[1].at(0)));
    }

    for(int i=m_p_index; i<m_p_index+MedicalStaffTotal; i++)
    {
        passenger[i]->introduce();
    }







    /*
* Security Staff
*/

    cout << "========================================================================================"<< endl;cout<<"\n";
    cout << "======================="<< endl;
    cout << "Security Staff"<< endl;
    cout << "======================="<< endl;

    cout << "\n";
    cout << "Generating Security Staff   based on Requirment Specified " << endl;
    cout << "\n";
    for(auto x:securitystaff){cout << x << " ";}cout<<"\n";

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
    }

    for(int i=sec_p_index; i<sec_p_index+SECStaffTotal; i++)
    {
        passenger[i]->introduce();
    }





    cout << "------------------------------------------------------------>" << endl;
}
