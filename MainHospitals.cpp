#include <iostream>
#include "Hospitals.h"

using namespace std;

int main() {
    Hospitals hospitals(10, 10);
    hospitals.printBeds();
    hospitals.printPercentages();
    return 0;
}