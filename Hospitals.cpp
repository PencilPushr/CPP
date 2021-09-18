#include <iostream>
#include <random>
#include "Hospitals.h"

Hospitals::Hospitals(int noOfHospitals, int noOfBeds) {

    if (noOfHospitals < 1 || noOfBeds < 1){
        noOfBeds = 1;
        noOfHospitals = 1;
    }
    //This is so dumb, I don't understand why I cannot simply instantiate
    //this.beds here with both values instead of iterating through them.
    //e.g. this->beds = new bool[x][y];
    /*
    this->beds = new bool*[noOfHospitals];
    for(int i = 0; i < noOfHospitals; i++){
        this->beds[i] = new bool[noOfBeds];
    }
     */
    this->beds.reserve(noOfHospitals * noOfBeds);

    //this->percentages = new double[noOfHospitals];
    this->percentages.reserve(noOfHospitals);

    assignBeds();
    calcPercentages();
}

bool Hospitals::randomBool() {
    //return rand() > (RAND_MAX / 2);
    static const int shift = static_cast<int>(std::log2(RAND_MAX));
    return (rand() >> shift) & 1;
}


void Hospitals::assignBeds() {

    //need to have a random
    for (int i = 0; i < this->beds.size(); i++) {
        for (int j = 0; j < this->beds[0].size(); j++) {
            this->beds[i][j] = randomBool();
        }
    }

}

void Hospitals::calcPercentages() {

    const int bedSize = this->beds.size();
    const int hospitals = this->beds[0].size();
    int total;
    double temp;

    for (int i = 0; i < hospitals; ++i) {
        for (int j = 0; j < bedSize; ++j) {
            if (this->beds[j][i])
            total++;
        }
        temp = ((double) total) / ((double) bedSize);
        temp = temp * 100.0;
        this->percentages[i] = temp;
    }
    
}

void Hospitals::printBeds() {

}
void Hospitals::printPercentages() {

}

void Hospitals::printMinPercentage() {

}

void Hospitals::printMaxPercentage() {

}
