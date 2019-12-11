#include "timingWheel.h"
#include "partitions.h"
#include "Elevators.h"
#include "ElevatorDirection.h"
#include "Passenger.h"
#include "StringHelper.h"
#include <queue>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>
using namespace std;


timingWheel::timingWheel(int floors, int delay, map<int, vector<vector<std::string>>> &PData, Elevators ** elevator) {

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
	cout << "Total number of Elevators: " << numElevators << endl;
	cout << "Total number of Floors: " << numFloors << endl;

    //Create a partition for each elevator and place them in the starting slot
	for (int i =0; i <numElevators ; i++)
    {
		timingWheel::insertAt(0, elevator[i], 'N');//new Elevators()); //not needed
		//timingWheel::insertAt(1, elevator[i], 'I');//increament partition
        //slots[0]->elevator->higestFloor = numFloors-1;
		//slots[0]->elevator->maxCapacity = stoi(PData.at(0).at(0).at(2));
    }

	//To introduce each elevator created
   // slots[0]->elevator->elevatorIntroduce();
	partitions* hasNext = slots[0];// ->getNextPartitions();
	cout << "============= Elevators =============" << endl;
    while (hasNext != nullptr)
    {
        //Introduce elevator at that partition
        hasNext->elevator->elevatorIntroduce();

		//get next partition pointer in list
        hasNext = hasNext->getNextPartitions();
    }

	//setup for level call type map;
	map<char, char>none;
	none.insert(pair<char, char>('U', 'N'));
	none.insert(pair<char, char>('D', 'N'));

	vector<Passenger*>* tmp;
	Dest = new map<int, vector<Passenger*>>;
	for (int i = 0; i < numFloors; i++) {
		//levelCall.insert(pair<int, char[2]>(i,));
		tmp = new vector<Passenger*>;
		(*Dest).insert(pair<int, vector<Passenger*>>(i, *tmp));
		levelCall[i] = none;

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

void timingWheel::insertAt(int time, Elevators* e, char type, char direction) {
	int nextSlot = time % maxDelay;
	partitions* tmp = slots[nextSlot];
	slots[nextSlot] = new partitions(e, tmp, type, direction);
}

void timingWheel::insert(int travelFloors, Elevators* e, char type, char direction) {
	int nextSlot;
	if (travelFloors != 0) {
		nextSlot = (currentSlot + (travelFloors * delaySize)) % maxDelay;
	}
	else {
		nextSlot = (currentSlot + 1) % maxDelay;
	}
	partitions* tmp = slots[nextSlot];
    slots[nextSlot] = new partitions(e, tmp, type, direction);
}

map<int, vector<Passenger *>> *timingWheel::schedule(map<int, vector<Passenger *>> * Levels) {
    //results map of passengers at each destination
	map<int, vector<Passenger*>> *temp;
	map<int, vector<Passenger*>> *temp2;
	
	//get first partition in current slot
    partitions* currentPartition = slots[currentSlot];

	if (currentPartition == nullptr) {
		cout << "no partitions" << endl;
	}
	else {
		//next time slot is pointing to a partition
		//check levels for call types
		elevatorRequestStop(Levels, true);
		while (currentPartition != nullptr) {
			//Do work for current partition in that time slot.

			//For each partition:
			//Open elevator door.
			//Disembark passengers from elevator.
			//Fill elevator with waiting passengers at the floor going in the same direction or change direction if the elevator has no next destination.
			//Close elevator door.

			//change directions when requested

			//currentPartition->elevator->increamentFloor();
			temp2 = currentPartition->elevatorTask(Levels);
			addToMap(*Dest, *temp2);
			//elevatorRequestStop(Levels, false, true, true);
			
			insertToNextSlot(Levels, currentPartition);
			

			//Get next partition pointer in time slot if there more.
			currentPartition = currentPartition->next;//getNextPartitions();
		}
	}
    //delete all partitions in current time slot after
	return Dest;
}

void timingWheel::insertToNextSlot(map<int, vector<Passenger*>>* Levels, partitions* currentPartition) {
	//Create new partition to next corresponding time slot depending on distance of next destination floor.
	if (!evacCall) {
		if (currentPartition->elevator->currentTask != 'P') {
			//not priority call
			if (currentPartition->elevator->currentDirection == 'U' and currentPartition->elevator->currentFloor != numFloors - 1) {
				//when elevator is going up
				int f = currentPartition->elevator->currentFloor;
				int count = 0;
				bool direction = false;//false = down, true = up

				//for each floor between current floor and destination floor
				while (f <= currentPartition->elevator->currentDestination) {
					if (levelCall[f]['U'] != 'N') {
						currentPartition->elevator->currentTask = levelCall[f]['U'];
						currentPartition->elevator->currentDirection = 'U';
						currentPartition->elevator->currentFloor = f;
						insert(abs(f - currentPartition->elevator->currentFloor), currentPartition->elevator, levelCall[f]['U'], 'U');
						cout << "elevator " << currentPartition->elevator->ElevatorId << "next destination " << f << endl;

						//elevator going pick up floor
						levelCall[f]['U'] = 'N';
						break;
					}
					else if (f == currentPartition->elevator->currentDestination) {
						currentPartition->elevator->currentDirection = 'U';
						currentPartition->elevator->currentFloor = currentPartition->elevator->currentDestination;
						insert(abs(currentPartition->elevator->currentDestination - currentPartition->elevator->currentFloor), currentPartition->elevator, currentPartition->elevator->currentTask, currentPartition->elevator->currentDirection);
						cout << "elevator " << currentPartition->elevator->ElevatorId << "next destination " << f << endl;
						break;
					}
					else {
						//cout << "Elevator stuct" << endl;
						//cout << "Elevator: " << currentPartition->elevator->ElevatorId << endl;
						//cout << "Current Floor: " << currentPartition->elevator->currentFloor << endl;
						//check next floor
					}
					f = f + 1;
				}
			}
			else if (currentPartition->elevator->currentDirection == 'D' and currentPartition->elevator->currentFloor != 0) {
				//when elevator is going down
				int f = currentPartition->elevator->currentFloor;
				int count = 0;
				bool direction = false;//false = down, true = up

				//for each floor between current floor and destination floor
				while (f >= currentPartition->elevator->currentDestination) {
					if (levelCall[f]['D'] != 'N') {
						currentPartition->elevator->currentTask = levelCall[f]['D'];
						currentPartition->elevator->currentDirection = 'D';
						currentPartition->elevator->currentFloor = f;
						insert(abs(f - currentPartition->elevator->currentFloor), currentPartition->elevator, levelCall[f]['D'], 'D');
						cout << "elevator " << currentPartition->elevator->ElevatorId << "next destination " << f << endl;
						levelCall[f]['D'] = 'N';
						break;
					}
					else if (f == currentPartition->elevator->currentDestination) {
						currentPartition->elevator->currentDirection = 'D';
						currentPartition->elevator->currentFloor = currentPartition->elevator->currentDestination;
						insert(abs(currentPartition->elevator->currentDestination - currentPartition->elevator->currentFloor), currentPartition->elevator, currentPartition->elevator->currentTask, currentPartition->elevator->currentDirection);
						cout << "elevator " << currentPartition->elevator->ElevatorId << "next destination " << f << endl;
						break;
					}
					else {
						//cout << "Elevator stuct" << endl;
						//cout << "Elevator: " << currentPartition->elevator->ElevatorId << endl;
						//cout << "Current Floor: " << currentPartition->elevator->currentFloor << endl;
						//check next floor
					}
					f = f - 1;
				}
			}
			else {
				//when elevator is not moving
				int f = currentPartition->elevator->currentFloor;
				int count = 0;
				bool direction = true;//false = down, true = up

				//for each floor
				//cout << numFloors*2 << endl;
				//cout << levelCall[9]['U'] << levelCall[9]['D'] << endl;
				while (count <= int(numFloors * 2) - 2) {
					if (direction == true) {
						//check floor for calls by increamenting floor number
						if (levelCall[f]['U'] != 'N' and levelCall[f]['U'] != NULL) {
							currentPartition->elevator->currentTask = levelCall[f]['U'];
							if (f < currentPartition->elevator->currentFloor) {
								currentPartition->elevator->currentDirection = 'U';
							}
							else {
								currentPartition->elevator->currentDirection = 'D';
							}
							currentPartition->elevator->currentFloor = f;
							insert(abs(f - currentPartition->elevator->currentFloor), currentPartition->elevator, levelCall[f]['U'], 'U');
							cout << "elevator " << currentPartition->elevator->ElevatorId << " next destination " << f << "Direction: " << "up" << endl;
							levelCall[f]['U'] = 'N';
							break;
						}
						else if (levelCall[f]['D'] != 'N' and levelCall[f]['D'] != NULL) {
							currentPartition->elevator->currentTask = levelCall[f]['D'];
							if (f < currentPartition->elevator->currentFloor) {
								currentPartition->elevator->currentDirection = 'U';
							}
							else {
								currentPartition->elevator->currentDirection = 'D';
							}
							currentPartition->elevator->currentFloor = f;
							insert(abs(f - currentPartition->elevator->currentFloor), currentPartition->elevator, levelCall[f]['D'], 'D');
							cout << "elevator " << currentPartition->elevator->ElevatorId << " next destination " << f << "Direction: " << "down" << endl;
							levelCall[f]['D'] = 'N';
							break;
						}
						else {
							//on one to pick at this floor
						}

						//increament floor number
						//cout << "look for next destination count: " << count << " f: " << f << "up " << endl;
						f = f + 1;
						if (f == numFloors - 1) {
							//cout << "top reached limit" << endl;
							//reached limit change direction
							direction = false;
						}
					}
					else {
						//check floor for calls by decreamenting floor number
						//cout << "Decreamenting" << endl;
						if (levelCall[f]['U'] != 'N' and levelCall[f]['U'] != NULL) {
							currentPartition->elevator->currentTask = levelCall[f]['U'];
							if (f < currentPartition->elevator->currentFloor) {
								currentPartition->elevator->currentDirection = 'U';
							}
							else {
								currentPartition->elevator->currentDirection = 'D';
							}
							currentPartition->elevator->currentFloor = f;
							insert(abs(f - currentPartition->elevator->currentFloor), currentPartition->elevator, levelCall[f]['U'], 'U');
							cout << "elevator " << currentPartition->elevator->ElevatorId << " next destination " << f << "Direction: " << "up" << endl;
							levelCall[f]['U'] = 'N';
							break;
						}
						else if (levelCall[f]['D'] != 'N' and levelCall[f]['D'] != NULL) {
							currentPartition->elevator->currentTask = levelCall[f]['D'];
							if (f < currentPartition->elevator->currentFloor) {
								currentPartition->elevator->currentDirection = 'U';
							}
							else {
								currentPartition->elevator->currentDirection = 'D';
							}
							currentPartition->elevator->currentFloor = f;
							insert(abs(f - currentPartition->elevator->currentFloor), currentPartition->elevator, levelCall[f]['D'], 'D');
							cout << "elevator " << currentPartition->elevator->ElevatorId << " next destination " << f << "Direction: " << "down" << endl;
							levelCall[f]['D'] = 'N';
							break;
						}
						else {
							/*cout << "Elevator stuct" << endl;
							cout << "Elevator: " << currentPartition->elevator->ElevatorId << endl;
							cout << "Current Floor: " << currentPartition->elevator->currentFloor << endl;
							*/
							//on one to pick at this floor
						}

						//decreament floor number
						f = f - 1;
						//after two check the levels for calls
						//cout << "look for next destination count: " << count << " f: " << f << "down" << endl;
						if (f == 0) {
							//cout << "bottom limit reach" << endl;
							//reached limit change direction
							direction = true;
						}
					}


					if (count == (numFloors * 2) - 2) {
						//no new calls
						cout << "stay at level" << endl;
						insert(0, currentPartition->elevator, 'N');
						cout << "elevator " << currentPartition->elevator->ElevatorId << "next destination " << currentPartition->elevator->currentFloor << endl;
						break;
					}
					count = count + 1;
				}
			}
		}
		else if (currentPartition->elevator->currentTask == 'P') {
			//elevator picking up a emergency call
			currentPartition->elevator->currentFloor = currentPartition->elevator->currentDestination;
			insert(abs(currentPartition->elevator->currentFloor - currentPartition->elevator->currentDestination), currentPartition->elevator);
			cout << "elevator " << currentPartition->elevator->ElevatorId << "next destination " << currentPartition->elevator->currentDestination << endl;
		}
		else {
			//try again at next timeslot
			insert(0, currentPartition->elevator);
			cout << "elevator " << currentPartition->elevator->ElevatorId << "next destination " << currentPartition->elevator->currentDestination << endl;
		}
		cout << endl;
	}
	else {
		//evac operatation
		currentPartition->elevator->currentTask = 'E';
		elevatorRequestStop(Levels, false);
		/*if (currentPartition->elevator->currentCapacity < currentPartition->elevator->maxCapacity) {

			//insert(abs(currentPartition->elevator->currentFloor - currentPartition->elevator->currentDestination), currentPartition->elevator, 'E');
		}
		else {*/
		if (currentPartition->elevator->currentFloor != 0 and currentPartition->elevator->currentCapacity == currentPartition->elevator->maxCapacity) {
			currentPartition->elevator->currentDirection = 'D';
			currentPartition->elevator->currentFloor = 0;
			insert(abs(currentPartition->elevator->currentFloor - 0), currentPartition->elevator, 'E');
		}
		else if (currentPartition->elevator->currentFloor != 0 and currentPartition->elevator->currentCapacity < currentPartition->elevator->maxCapacity) {
			int nextpick = 0;
			for (int i = currentPartition->elevator->currentFloor; i > 0; i--) {
				if (!levelCall[i].empty()) {
					nextpick = i;
					break;
				}
			}
			if (nextpick == 0) {
				currentPartition->elevator->currentFloor = 0;
				insert(abs(currentPartition->elevator->currentFloor - 0), currentPartition->elevator, 'E');
			}
			else {
				currentPartition->elevator->currentFloor = nextpick;
				insert(abs(currentPartition->elevator->currentFloor - nextpick), currentPartition->elevator, 'E');
			}
		}
		else {
			currentPartition->elevator->currentDirection = 'U';
			int nextpick = 0;
			for (int i = numFloors - 1; i > 0; i--) {
				if (!levelCall[i].empty()) {
					nextpick = i;
					break;
				}
			}
			//look for highest floor with passengers
			if (nextpick == 0) {
				//simulation ends
				cout << "Evac was successful!" << endl;
				exit(0);
			}
			else {
				currentPartition->elevator->currentDirection = 'U';
				currentPartition->elevator->currentFloor = nextpick;
				insert(abs(nextpick), currentPartition->elevator, 'E');
			}

		}


	}
}

void timingWheel::insertNextIncreamentSlot(partitions* currentPartition) {
	insert(1, currentPartition->elevator, 'I');
}

void timingWheel::clearCurrentSlot() {
    //queue to hold all partitions in slot
    queue <partitions*> partToDel;

    //get next partition in the start of the list
	partitions* hasNext = slots[currentSlot];// ->getNextPartitions();

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

    /*//delete partiiton where pointer is pointing
	if (slots[currentSlot] != nullptr) {
		delete slots[currentSlot];
		slots[currentSlot] = nullptr;
	}
	else {
		//continue
	}*/
	slots[currentSlot] = nullptr;
}

void timingWheel::clearSlot(int s) {
    queue <partitions*> partToDel;

    //get next partition in the start of the list
	partitions* hasNext = slots[s];// ->getNextPartitions();

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

    /*//delete pointer in slot
	if(slots[s] != nullptr){
		delete slots[s];
		slots[s] = nullptr;
	}*/
	slots[s] = nullptr;
    
}

//list call for each floor also take care of evac calls
void timingWheel::elevatorRequestStop(map<int, vector<Passenger *>> * Levels, bool print, bool printFinal, bool checkOnly) {
	//check the levels for elevators calls
	if (!checkOnly) {
		for (int i = 0; i < numFloors; i++) {
			if (print) cout << "Check for call at floor " << i << endl;
			//check if level is empty
			if (!(*Levels)[i].empty()) {
				//loop thur the passengers waiting at this level
				for (int j = 0; j < (*Levels)[i].size(); j++) {
					//check for evac calls
					if ((*Levels)[i][j]->callType != 'E' or evacCall) {
						//check if passengers have a directions of travel
						if ((*Levels)[i][j]->DirectionPassenger == 'U' or (*Levels)[i][j]->DirectionPassenger == 'D') {
							//check off the level call
							if (levelCall[i][(*Levels)[i][j]->DirectionPassenger] == 'N') {//if the call
								levelCall[i][(*Levels)[i][j]->DirectionPassenger] = (*Levels)[i][j]->callType;
								if (print) cout << "Passenger " << (*Levels)[i][j]->PassengerId << " call elevator going " << (*Levels)[i][j]->DirectionPassenger << endl;
							}
							else if ((*Levels)[i][j]->callType == 'P') {
								levelCall[i][(*Levels)[i][j]->DirectionPassenger] = (*Levels)[i][j]->callType;
							}
							/*else if (levelCall[i][(*Levels)[i][j]->DirectionPassenger] == 'R') {
								levelCall[i][(*Levels)[i][j]->DirectionPassenger] = (*Levels)[i][j]->callType;
							}*/
							else
							{
								if (print) cout << "Passenger " << (*Levels)[i][j]->PassengerId << " dont need to call elevator, Elevator already been called to that level" << endl;
								//cout << "Passenger " << (*Levels)[i][j]->PassengerId << " didnt call elevator" << endl;
							}
						}
						else {
							if (print) cout << "Passenger " << (*Levels)[i][j]->PassengerId << " does have direction set" << endl;
						}
					}
					else {
						//evac call was made
						evacCall = true;
					}
				}
			}
			else {
				//no one called for elevator
				levelCall[i]['U'] = 'N';
				levelCall[i]['D'] = 'N';
			}

		}
	}
	if (print) cout << endl;

	if (printFinal) {
		map<int, map<char, char>>::iterator mmit;
		map<char, char>::iterator mit;
		for (mmit = levelCall.begin(); mmit != levelCall.end(); mmit++) {
			cout << mmit->first << ":" << endl;
			for (mit = (mmit->second).begin(); mit != (mmit->second).end(); mit++) {
				cout << "\t" << mit->first << " : " << mit->second << endl;
			}
		}
	}
	//stops least filled elevator that is on the current floor where the call was made
	//if normal call
		//normal pickup if they fit
	//if emergency call
		//drop off all current passengers and pick up caller
		//the elevator should become dedicated to the emergency caller
	//if evacuate??
}

void timingWheel::addToMap(map<int, vector<Passenger*>>& target, map<int, vector<Passenger*>>& input) {
	//append each vector from input to target map
	//cout << "Appending two map together" << endl;
	//cout << "target:" << target.size() << ", input: " << input.size() << endl;
	vector<Passenger*>::iterator it;
	map<int, vector<Passenger*>>::iterator mit;
	for (int i = 0; i < (input).size(); i++) {
		//each key
		//target[i].insert(input[i].begin(), input[i].end(), input[i].begin());
		for (int j = 0; j < (input).at(i).size(); j++) {
			//each value in vector
			(target)[i].push_back((input).at(i).at(j));
		}
	}
	//return target map
}
