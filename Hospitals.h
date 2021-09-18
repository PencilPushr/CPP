//
// Created by averagejoe on 9/11/21.
//

#ifndef EXERCISES_HOSPITALS_H
#define EXERCISES_HOSPITALS_H
#include <vector>

class Hospitals {
private:

    //variables
    //bool** beds; //weird, have a look in Hospitals.cpp
    std::vector<std::vector<bool>> beds;
    //can also be declared as bool* beds[NoB * NoH] to set the block of memory;
    //double* percentages;
    std::vector<double> percentages;
    //https://stackoverflow.com/questions/4412749/are-flexible-array-members-valid-in-c

    //Class Methods
    void assignBeds();
    void calcPercentages();
    static bool randomBool();

public:
    //Class constructor
    Hospitals(int noOfHospitals, int noOfBeds);

    //Class methods
    void printBeds();
    void printPercentages();
    void printMinPercentage();
    void printMaxPercentage();
};

#endif //EXERCISES_HOSPITALS_H
