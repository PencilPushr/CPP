//
// Created by averagejoe on 9/26/21.
//

#include "MriData.h"

MriData::MriData() {
    MriData::readData2D();
    //MriData::readData3D(149, 149);
}

void MriData::readData2D() {
//std::vector we have included vector in MRIData, if unused don't forget to delete from the .h file.

    std::ifstream inputFile("149.csv");
    //inputFile.open("149.csv");

    // Make sure the file is open
    if(!inputFile.is_open()){
        std::cout << "Cannot open file!";
        exit(1);
    }

    //helper vars
    rowSize = 0;
    colSize = 0;
    std::string line;

    //need to get the size/requirements of the file, akin to moving furniture
    //go back, get the correct size "lorrys", now you can move the furniture.
    //Remember, every "roW" is equally long. If we get one rowlength, we have every rowlength.

    // scouting
    if(inputFile.good()){
        while(!inputFile.eof()){
            std::getline(inputFile, line);
            rowSize++;
        }
    }

    //calloc the array. "size"

    //fill in the calloc'd array
}

void MriData::readData3D(int file1, int file2) {

}


int MriData::getIntensity2D() {
    return 0;
}

int MriData::getIntensity3D(int x, int y, int z) {
    return 0;
}

int **MriData::getArrayOfMRI2D() {
    return nullptr;
}

int ***MriData::getArrayOfMRI3D() {
    return nullptr;
}

int MriData::getFileNumber() {
    return 0;
}

void MriData::setFileNumber(int fileNumber) {

}

