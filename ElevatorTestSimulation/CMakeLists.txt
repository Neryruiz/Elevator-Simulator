cmake_minimum_required(VERSION 3.15)
project(ElevatorTestSimulation)

set(CMAKE_CXX_STANDARD 14)

add_executable(ElevatorTestSimulation main.cpp
        Passenger.cpp Passenger.h Staff.cpp Staff.h
        Security.cpp Security.h SupportStaff.cpp SupportStaff.h
        MedicalStaff.cpp MedicalStaff.h SecurityPersonnel.cpp
        SecurityPersonnel.h Visitors.cpp Visitors.h Patients.cpp
        Patients.h People.cpp People.h StringHelper.cpp
        StringHelper.h RandomGenerator.cpp RandomGenerator.h
        FileRead.cpp FileRead.h TrafficGenerator.cpp TrafficGenerator.h
        GenerateUniquePassenger.cpp GenerateUniquePassenger.h ElevatorDirection.cpp ElevatorDirection.h Display.cpp Display.h StatisticsKeeper.cpp StatisticsKeeper.h SystemController.cpp SystemController.h Elevators.cpp Elevators.h)