#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

void readPrintInput(std::vector<std::string>& nameVector, 
               std::vector<std::string>& balanceVector);

void main()
{
    //read data in from a text file
    std::vector<std::string> nameVector;
    std::vector<std::string> balanceVector;
    readPrintInput(nameVector, balanceVector);

    //sort the vector 

    // for (size_t i = 0; i != nameVector.size()-1; ++i){
    //     std::cout << nameVector[i];
    //     std::cout << nameVector[i+1];
    // }

}

void readPrintInput(std::vector<std::string>& nameVector, 
               std::vector<std::string>& balanceVector){
    std::ifstream infile("data.txt");
    const char delim = '|';
    std::string line;

    while (std::getline(infile, line)){
        std::string data;
        std::stringstream ss(line);
        int counter = 1;
        while (std::getline(ss, data, delim)){
            if (counter % 2 != 0) {
                nameVector.push_back(data);
            }
            else {
                balanceVector.push_back(data);
            }
            counter += 1;
        }           
    }

    for (size_t i = 0; i != nameVector.size(); ++i){
        std::cout << nameVector[i] << ": " << balanceVector[i] << "\n";
    }

}