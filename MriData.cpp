//
// Created by averagejoe on 9/26/21.
//

#include "MriData.h"

MriData::MriData() {
    MriData::readData2D();
    MriData::readData3D(149, 149);
}

void MriData::readData2D() {
//std::vector we have included vector in MRIData, if unused don't forget to delete from the .h file.

    std::ifstream inputFile("/home/averagejoe/CLionProjects/Exercises/149.csv");

    // Make sure the file is open
    if(!inputFile.is_open()){
        std::cout << "Cannot open file!";
        exit(1);
    }

    //helper vars
    int rowCount = 0;
    int colCount = 1;//There must be at least 1 column
    std::string line;

    //need to get the size/requirements of the file, akin to moving furniture
    //go back, get the correct size "lorrys", now you can move the furniture.
    //Remember, every "roW" is equally long. If we get one rowlength, we have every rowlength.

    // scouting
    if(inputFile.good()){
        while(!inputFile.eof()){
            std::getline(inputFile, line);
            rowCount++;
            if (rowCount == 1){
                for (int i = 0; i < line.length(); i++) {
                    if (line[i] == ',') {colCount++;}
                }
            }
        }
    }
    std::cout << "Column size is: " << colCount << " \n" << "Row size is: " << rowCount << std::endl;

    //Memory block size (of 2d array)
    int size = rowCount * colCount;

    //calloc the array. "size"
    this->arrayOfMRI2D = (int **) calloc(rowCount, sizeof(int*));
    for (int i = 0; i < size; i++) {
        this->arrayOfMRI2D[i] = (int *) calloc(colCount, sizeof(int));
    }

    //fill in the calloc'd array
    int currentLine = 0;
    while(!inputFile.eof()){
        std::getline(inputFile, line);
        for (int i = 0; i < line.length(); i++) {
            this->arrayOfMRI2D[0][0] = 0;
            if (line[i] == ',') {
                for (int j = 0; j < colCount; j++){
                    this->arrayOfMRI2D;
                }
            }
        }
        currentLine++;
    }
    // Close file
    inputFile.close();
}

void MriData::readData3D(int file1, int file2) {

    //helper vars
    int rowCount = 0;
    int colCount = 1;//There must be at least 1 column
    int filesCount = 0;
    std::string line;
    std::vector<std::vector<std::vector<int>>> array3D;

    //first collect the fileSize (number of files in the given directory)
    auto dirIter = std::filesystem::directory_iterator("/home/averagejoe/CLionProjects/Exercises/");
    int fileCount = 0;

    for (auto& entry : dirIter)
    {
        if (entry.is_regular_file())
        {
            ++fileCount;
        }
    }
    std::cout << fileCount << std::endl;

    //need to dynamically get the name of the first file in the directory, then append it to the string
    // should then act as the inputFile to peek at the contents.
    std::ifstream inputFile("/home/averagejoe/CLionProjects/Exercises/149.csv");

    // Make sure the file is open
    if(!inputFile.is_open()){
        std::cout << "Cannot open file!";
        exit(1);
    }

    //need to get the size/requirements of the file, akin to moving furniture
    //go back, get the correct size "lorrys", now you can move the furniture.
    //Remember, every "roW" is equally long. If we get one rowlength, we have every rowlength.

    // scouting

    //if(inputFile.peek()) consider trying this so we no longer have to reset the file back to the beginning.

    if(inputFile.good()){
        while(!inputFile.eof()){
            std::getline(inputFile, line);
            rowCount++;
            if (rowCount == 1){
                for (int i = 0; i < line.length(); i++) {
                    if (line[i] == ',') {colCount++;}
                }
            }
        }
    }

    for (int i = file1; i <= file2; i++) {
        //std::string files = "/home/averagejoe/CLionProjects/Exercises/" << reinterpret_cast<char *>(this->fileNumber) << ".csv";
        //std::ifstream inputFile(files);
    }


}

void MriData::FreeMemory(){
    free(this->arrayOfMRI2D);
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

