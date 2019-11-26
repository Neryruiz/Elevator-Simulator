cmake_minimum_required(VERSION 3.15)
project(ElevatorSimulationsSoftware)

set(CMAKE_CXX_STANDARD 14)

add_executable(ElevatorSimulationsSoftware main.cpp Passenger.cpp Passenger.h Staff.cpp Staff.h
        SupportStaff.cpp SupportStaff.h MedicalStaff.cpp MedicalStaff.h Security.cpp Security.h
        SecurityPersonnel.cpp SecurityPersonnel.h Visitors.cpp Visitors.h Patients.cpp Patients.h
        People.cpp People.h RandomGenerator.cpp RandomGenerator.h StringHelper.cpp StringHelper.h FileRead.cpp FileRead.h
        GenerateUniquePassenger.cpp GenerateUniquePassenger.h ElevatorDirection.cpp ElevatorDirection.h
        StatisticsKeeper.cpp StatisticsKeeper.h TrafficGenerator.cpp TrafficGenerator.h Display.cpp Display.h SystemController.cpp SystemController.h Elevators.cpp Elevators.h timingWheel.cpp timingWheel.h partitions.cpp partitions.h)