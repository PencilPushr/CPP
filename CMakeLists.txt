cmake_minimum_required(VERSION 3.20)
project(Exercises)

set(CMAKE_CXX_STANDARD 20)

add_executable(Exercises MainHospitals.cpp Hospitals.cpp Hospitals.h MriData.cpp MriData.h Includes.h)
