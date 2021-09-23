#include <iostream>
#include <random>
#include "Hospitals.h"

Hospitals::Hospitals(int noOfHospitals, int noOfBeds) {

    if (noOfHospitals < 1 || noOfBeds < 1){
        noOfBeds = 1;
        noOfHospitals = 1;
    }

    this->sizeOfBeds = noOfBeds;
    this->sizeOfHospitals = noOfHospitals;

    //Memory block size
    int size = noOfBeds*noOfHospitals;
    //this->bedSpecial = (bool**) calloc(size,sizeof(bool*));
    this->bedSpecial = (bool**) calloc(this->sizeOfHospitals,sizeof(bool*));
    for (int i = 0; i < size; i++) {
        this->bedSpecial[i] = (bool *) calloc(this->sizeOfBeds, sizeof(bool));
    }
    this->percentageSpecial = (double*) calloc(noOfHospitals,sizeof(double));

    this->beds.reserve(noOfHospitals * noOfBeds);
    this->percentages.reserve(noOfHospitals);

    assignBeds();
    calcPercentages();

    /*
    for (int i = 0; i < this->sizeOfHospitals; i++){
        free(this->bedSpecial[i]);
    }
    free(this->bedSpecial);
     */
}

bool Hospitals::randomBool() {
    //return rand() > (RAND_MAX / 2);
    static const int shift = static_cast<int>(std::log2(RAND_MAX));
    return (rand() >> shift) & 1;
}


void Hospitals::assignBeds() {


    for(int a = 0; a < this->sizeOfHospitals; a++){
        for(int b= 0; b < this->sizeOfBeds; b++){
            this->bedSpecial[a][b] = randomBool();
            std::string temp = "Unoccupied";
            if (this->bedSpecial[a][b]){ //if it is not 0/false, it is occupied
                temp = "Occupied";
            }
            std::cout << "Bed number: " << std::to_string(b) << " in hospital number: " << std::to_string(a) << " is " << temp << "." << std::endl;
        }
    }

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
    int total {0};
    int totalSpecial {0};
    double temp {0.0};
    double cent {100.0}; //consider this the percentage we want to multiply for percentageSpecial


    for (int a = 0; a < this->sizeOfHospitals; a++) {
        totalSpecial = 0.0;
        for (int b = 0; b < this->sizeOfBeds; b++) {
            if (this->bedSpecial[b][a]){
                totalSpecial = totalSpecial + 1.0;
            }
        }
        this->percentageSpecial[a] = cent*(totalSpecial/this->sizeOfBeds);
    }


    for (int i = 0; i < hospitals; i++) {
        for (int j = 0; j < bedSize; j++) {
            if (this->beds[j][i])
            total++;
        }
        temp = ((double) total) / ((double) bedSize);
        temp = temp * 100.0;
        this->percentages[i] = temp;
    }
    
}

void Hospitals::printBeds() {
/*
    std::string temp;
    int hospitals = this->sizeOfHospitals;
    int beds = this->sizeOfBeds;

    for (int i = 0; i < hospitals; i++) {
        temp = "Hospitals " + std::to_string(i) + " : [ ";
        for (int j = 0; j < beds; j++) {
            if (this->beds[j][i]) {
                temp += "true";
            } else {
                temp += "false";
            }
            if (j != beds - 1) {
                temp += ", ";
            }
        }
        temp += " ]";
        std::cout << temp << std::endl;
    }
*/

}

void Hospitals::printPercentages() {
    /*
    for (int i = 0; i < this->sizeOfHospitals; ++i) {
        std::cout << std::to_string(this->percentageSpecial[i]) << std::endl;
    }
    */

}

void Hospitals::printMinPercentage() {

}

void Hospitals::printMaxPercentage() {

}


