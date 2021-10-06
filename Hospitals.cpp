#include <iostream>
#include <random>
#include "Hospitals.h"

Hospitals::Hospitals(int noOfHospitals, int noOfBeds) {

    if (noOfHospitals < 1 || noOfBeds < 1){
        noOfBeds = 1;
        noOfHospitals = 1;
    }

    //Calloc cannot hold the integer values as they are pointers to the memory address only
    this->sizeOfBeds = noOfBeds;
    this->sizeOfHospitals = noOfHospitals;

    //Memory block size
    int size = noOfBeds*noOfHospitals;

    //this->bedSpecial = (bool**) calloc(size,sizeof(bool*));
    this->bedSpecial = (bool**) calloc(this->sizeOfHospitals,sizeof(bool*)); //pointerA to pointerB
    for (int i = 0; i < size; i++) {
        this->bedSpecial[i] = (bool *) calloc(this->sizeOfBeds, sizeof(bool)); // pointerB to int
    }
    this->percentageSpecial = (double*) calloc(noOfHospitals,sizeof(double));

    //pre-allocating or reserving memory blocks
    this->beds.reserve(noOfHospitals * noOfBeds);
    //vector<vector<int>> M;
    //int m = number of rows, n = number of columns;
    //this->beds.resize(this->sizeOfHospitals, std::vector<int>(this->sizeOfBeds));

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

    for (int i = 0; i < this->beds.size(); i++) {
        for (int j = 0; j < this->beds[i].size(); j++) {
            this->beds[i][j] = randomBool();
            if (this->beds[i][j]){
                std::cout << "bacon" << std::endl;
            }
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

    std::string temp {""};
    int hospitals = this->sizeOfHospitals;
    int beds = this->sizeOfBeds;

    for (int i = 0; i < this->beds.size(); i++) {
        temp = "Hospitals " + std::to_string(i) + " : [ ";
        for (int j = 0; j < this->beds[i].size(); j++) {
            if (this->beds[j][i]) {
                temp = temp + "true";
            } else {
                temp = temp + "false";
            }
            if (j != this->beds.size() - 1) {
                temp = temp + ", ";
            }
        }
        temp = temp + " ]";
        std::cout << temp << std::endl;
    }

}

void Hospitals::printPercentages() {

    std::string temp;

    for(int i = 0; i < this->sizeOfHospitals; i++){
        temp = "Hospital " + std::to_string(i) + " (%): " + std::to_string(this->percentageSpecial[i]);
        std::cout << temp << std::endl;
    }
    std::cout << "It is over." << std::endl;


}

void Hospitals::printMinPercentage() {

}

void Hospitals::printMaxPercentage() {

}

void Hospitals::GarbageBedsandHospitals() {
    free(this->bedSpecial);
}

void Hospitals::GarbagePercentage(){
    free(this->percentageSpecial);
}
