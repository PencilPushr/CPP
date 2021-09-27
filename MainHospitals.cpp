#include <iostream>
#include "Hospitals.h"

using namespace std;

int main() {
    Hospitals hospitals(10, 10);
    hospitals.printBeds();
    hospitals.printPercentages();

    //freeing the memory after its been used.
    hospitals.GarbageBedsandHospitals();
    hospitals.GarbagePercentage();
    return 0;
}