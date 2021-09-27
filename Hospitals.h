//
// Created by averagejoe on 9/11/21.
//

#ifndef EXERCISES_HOSPITALS_H
#define EXERCISES_HOSPITALS_H
#include <vector>

class Hospitals {
private:

    //variables
    bool** bedSpecial;
    std::vector<std::vector<bool>> beds;
    //can also be declared as bool* beds[NoB * NoH] to set the block of memory;
    //double* percentages;
    double* percentageSpecial;
    std::vector<double> percentages;

    int sizeOfBeds;
    int sizeOfHospitals;

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
    void GarbageBedsandHospitals();
    void GarbagePercentage();
};

#endif //EXERCISES_HOSPITALS_H
