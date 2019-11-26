#include "timingWheel.h"
#include "partitions.h"
#include "Elevators.h"
#include "ElevatorDirection.h"
#include "StringHelper.h"
#include <queue>
#include <vector>
#include <map>


timingWheel::timingWheel(int floors, int delay, map<int, vector<vector<std::string>>> &PData) {

    //constructor
    // why +1 because
    // we have higest floor as 8
    // 0 to 7
    // hence + 1

    currentSlot = 0;
    numFloors = floors + 1;
    delaySize = delay;
    maxDelay = numFloors * delay;
    slots = new partitions * [maxDelay + 1]{ nullptr };

    int numElevators = StringHelper::string_to_int(PData.at(0).at(0).at(1));


    for (int i =0; i <numElevators ; i++)
    {
        timingWheel::insert(0, new Elevators());
        slots[0]->elevator->higestFloor = numFloors;
    }


    slots[0]->elevator->elevatorIntroduce();
    partitions* hasNext = slots[0]->getNextPartitions();

    while (hasNext != nullptr)
    {
        //get next partition pointer in list
        hasNext->elevator->elevatorIntroduce();
        hasNext = hasNext->getNextPartitions();
    }


}

timingWheel::~timingWheel() {
    //deconstructor
    for (int i = 0; i < maxDelay+1; i++)
    {
        //delete all partitions in time slot
        clearSlot(i);
    }

    delete slots;
}

void timingWheel::insert(int travelFloors, Elevators* e) {
    int nextSlot = (currentSlot + (travelFloors * delaySize))%maxDelay;
    partitions* tmp = slots[nextSlot];
    slots[nextSlot] = new partitions(e, tmp);
}

void timingWheel::schedule() {
    //get first partition in current slot
    partitions* currentPartition = slots[currentSlot];

    //next time slot is pointing to a partition
    while (currentPartition != nullptr) {
        //Do work for current partition in that time slot.

        //For each partition:
        //Open elevator door.
        //Disembark passengers from elevator.
        //Fill elevator with waiting passengers at the floor going in the same direction or change direction if the elevator has no next destination.
        //Close elevator door.
        currentPartition->elevatorTask();

        //Create new partition to next corresponding time slot depending on distance of next destination floor.

        //Get next partition pointer in time slot if there more.
        currentPartition = currentPartition->getNextPartitions();
    }
    //delete all partitions in current time slot
}

void timingWheel::clearCurrentSlot() {
    //queue to hold all partitions in slot
    queue <partitions*> partToDel;

    //get next partition in the start of the list
    partitions* hasNext = slots[currentSlot]->getNextPartitions();

    //if the hasNext pointer is not a null pointer
    while (hasNext != nullptr) {
        //push pointer in queue
        partToDel.push(hasNext);

        //get next partition pointer in list
        hasNext = hasNext->getNextPartitions();
    }

    while (!partToDel.empty()) {
        //delete the partitions that the next in queue is pointing to
        delete partToDel.front();

        //pop from queue
        partToDel.pop();
    }

    //delete partiiton where pointer is pointing
    delete slots[currentSlot];
}

void timingWheel::clearSlot(int s) {
    queue <partitions*> partToDel;

    //get next partition in the start of the list
    partitions* hasNext = slots[s]->getNextPartitions();

    //if the hasNext pointer is not a null pointer
    while (hasNext != nullptr) {
        //push pointer in queue
        partToDel.push(hasNext);

        //get next partition pointer in list
        hasNext = hasNext->getNextPartitions();
    }

    while (!partToDel.empty()) {
        //delete the partitions that the next in queue is pointing to
        delete partToDel.front();

        //pop from queue
        partToDel.pop();
    }

    //delete pointer in slot
    delete slots[s];
}