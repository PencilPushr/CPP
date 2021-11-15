//
// Created by averagejoe on 9/26/21.
//

#ifndef EXERCISES_MRIDATA_H
#define EXERCISES_MRIDATA_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <filesystem>
#include <iterator>

class MriData{
private:

    //we assume for both arrays, that the number of columns and rows do not change in size.
    int** arrayOfMRI2D;
    int*** arrayOfMRI3D;
    std::vector<std::string> filesFound;
    int fileCount;
    int rowCount;
    int colCount = 1; //there must be at least one column

public:
    MriData();

    //class methods
    void readData3D(int file1, int file2);
    void readData2D();

    //Garbage Disposal
    void FreeMemory();

    //getters and setters
    int getIntensity2D();
    int getIntensity3D(int x, int y, int z);
    int** getArrayOfMRI2D();
    int*** getArrayOfMRI3D();
    int getFileNumber();
    void setFileNumber(int fileNumber);

    void ReadIn3D();

    void DirectoryNFilePeeker();

    void CstyleReader();
};


#endif //EXERCISES_MRIDATA_H
