cmake_minimum_required(VERSION 3.15)
project(OfficalElevator)

set(CMAKE_CXX_STANDARD 14)

add_executable(OfficalElevator main.cpp Passenger.cpp Passenger.h Staff.cpp Staff.h SupportStaff.cpp SupportStaff.h MedicalStaff.cpp MedicalStaff.h Security.cpp Security.h Visitors.cpp Visitors.h SecurityPersonnel.cpp SecurityPersonnel.h Patients.cpp Patients.h StringHelper.cpp StringHelper.h RandomGenerator.cpp RandomGenerator.h ElevatorDirection.cpp ElevatorDirection.h GenerateUniquePassenger.cpp GenerateUniquePassenger.h FileRead.cpp FileRead.h TrafficGenerator.cpp TrafficGenerator.h StatisticsKeeper.cpp StatisticsKeeper.h SystemController.cpp SystemController.h timingWheel.cpp timingWheel.h partitions.cpp partitions.h Elevators.cpp Elevators.h)