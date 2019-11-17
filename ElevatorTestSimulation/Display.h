#include <iostream>
#include <map>
#include <vector>
using namespace std;


#ifndef ELEVATORTESTSIMULATION_DISPLAY_H
#define ELEVATORTESTSIMULATION_DISPLAY_H


class Display {

public:
    /*
     * Methods
     */

    static int TotalPassengerCreated;       // Counts How Many Passenger created for BatchSize
    static void introducePassenger(map<int,vector<Passenger *>> Levels);
    static  void displayTotalPassengerCount(int num);
    static void displayDestinationFloors( map<int , vector<Passenger *>> LevelDest);

};


#endif //ELEVATORTESTSIMULATION_DISPLAY_H
