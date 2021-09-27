//
// Created by averagejoe on 9/26/21.
//

#ifndef EXERCISES_MRIDATA_H
#define EXERCISES_MRIDATA_H

#include <iostream>
#include <fstream>
#include <vector>

class MriData{
private:

    //we assume for both arrays, that the number of columns and rows do not change in size.
    int** arrayOfMRI2D;
    int*** arrayOfMRI3D;

    int fileNumber;

    //helper vars
    int rowSize;
    int colSize;
    std::string FilePath;

public:
    MriData();

    //class methods
    void readData3D(int file1, int file2);
    void readData2D();

    //getters and setters
    int getIntensity2D();
    int getIntensity3D(int x, int y, int z);
    int** getArrayOfMRI2D();
    int*** getArrayOfMRI3D();
    int getFileNumber();
    void setFileNumber(int fileNumber);
};


#endif //EXERCISES_MRIDATA_H
