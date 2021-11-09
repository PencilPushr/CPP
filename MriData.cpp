//
// Created by averagejoe on 9/26/21.
//

#include "MriData.h"

MriData::MriData() {
    MriData::DirectoryNFilePeeker();
    //MriData::readData2D();
    //MriData::readData3D(149, 149);
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
    std::string line;

    //need to get the size/requirements of the file, akin to moving furniture
    //go back, get the correct size "lorrys", now you can move the furniture.
    //Remember, every "roW" is equally long. If we get one rowlength, we have every rowlength.

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
                    this->arrayOfMRI2D[i][j] = line[i]+1;
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
    std::string line;
    std::vector<std::string> fileName;
    std::vector<std::vector<std::vector<int>>> array3D;

    //need to dynamically get the name of the first file in the directory, then append it to the string
    // should then act as the inputFile to peek at the contents.

    //for(int i = 0; i < fileName.size(); i++)
    std::ifstream inputFile(filesFound.at(0));

    // Make sure the file is open
    if(!inputFile.is_open()){
        std::cout << "Cannot open file!";
        exit(1);
    }

    for (int i = 0; i < filesFound.size(); i++) {
        while(inputFile.peek()!=EOF){
            std::getline(inputFile, line);
            for (int j = 0; j < rowCount; ++j) {
                
            }
        }
    }

}

void MriData::DirectoryNFilePeeker(){

    //helper vars
    std::vector<std::string> fileName;
    std::string line;

    //first collect the fileSize (number of files in the given directory)
    auto dirIter = std::filesystem::directory_iterator("/home/averagejoe/CLionProjects/Exercises/Data");

    //check: if directory is empty
    if(std::filesystem::is_empty("/home/averagejoe/CLionProjects/Exercises/Data")){
        std::cout << "Directory is empty!";
        exit(1);
    }

    //this CAN BE MADE MORE EFFICIENT!!!
    //For now, we simply iterate through the known files in a directory and append them to a vector
    //however we could simply skip this by directly iterating through the files themselves
    for (auto& entry : dirIter)
    {
        if (entry.is_regular_file())
        {
            ++fileCount;
            fileName.push_back(entry.path());
        }
    }

    //get the first file
    std::ifstream inputFile(fileName.at(0));

    // Make sure the file is open
    if(!inputFile.is_open()){
        std::cout << "Cannot open file!";
        exit(1);
    }

    if (inputFile.good()){
        while(!inputFile.eof()){
            std::getline(inputFile, line);
            rowCount++;
            if (rowCount == 1){
                for (int i = 0; i < line.length(); i++) {
                    if (line[i] == ',') {colCount++;}
                }
            }
        }
        std::cout << "Rows: " << rowCount << " Columns: " << colCount << std::endl;
    }

}

void MriData::ReadIn3D(){

    std::vector<std::vector<double> > values;
    std::ifstream fin("textread.csv");
    for (std::string line; std::getline(fin, line); )
    {
        std::replace(line.begin(), line.end(), ',', ' ');
        std::istringstream in(line);
        values.push_back(
                std::vector<double>(std::istream_iterator<double>(in),
                                    std::istream_iterator<double>()));
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

