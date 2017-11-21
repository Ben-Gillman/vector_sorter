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
    std::vector<std::string> nameSorted;
    std::vector<std::string> balanceSorted;

    nameSorted.push_back(nameVector[0]);
    balanceSorted.push_back(balanceVector[0]);

    for (size_t i = 1; i != nameVector.size(); ++i){
        // std::cout << "i: " << i << "\n";
        for (size_t k = 0; k != nameSorted.size(); ++k){   
            // std::cout << "k: " << k << "\n";
            // std::cout << "k: " << k-1 << "\n";
            // k_minus = k - 1;
            // std::cout << "k: " << k_minus << "\n";
            // std::cout << "k: " << k+1 << "\n";
            std::cout << "compare: " << nameVector[i] << " " << nameSorted[k] << "\n";

            if ( nameVector[i] <= nameSorted[k] ) {
                int k_minus = k - 1;
                if ( k_minus <= 0) {
                    std::cout << "begin 1: " << "\n";
                    nameSorted.insert( nameSorted.begin(), nameVector[i] );
                    balanceSorted.insert( balanceSorted.begin(), balanceVector[i] );   
                }
                else {
                    std::cout << "begin 2" << "\n";
                    nameSorted.insert( nameSorted.begin()+(k_minus), nameVector[i] );
                    balanceSorted.insert( balanceSorted.begin()+(k_minus), balanceVector[i] );
                }
                break;
            } 
            
            else if ( nameVector[i] > nameSorted[k] ) {
                int k_plus = k + 1;
                if ( k_plus >= nameSorted.size()){
                    std::cout << "end 1" << "\n";
                    nameSorted.insert( nameSorted.end(), nameVector[i] );
                    balanceSorted.insert( balanceSorted.end(), balanceVector[i] );
                }
                else {
                    std::cout << "end 2" << "\n";
                    nameSorted.insert( nameSorted.begin()+(k_plus), nameVector[i] );
                    balanceSorted.insert( balanceSorted.begin()+(k_plus), balanceVector[i] );
                }
                break;
            } 
            
            else { std::cout << "error " << nameVector[i] << nameSorted[0] << nameSorted.back() << "\n"; 
                break;
            }
        }
    }

    for (size_t i = 0; i != nameSorted.size(); ++i){
        std::cout << nameSorted[i] << ": " << balanceSorted[i] << "\n";
    }

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

    // for (size_t i = 0; i != nameVector.size(); ++i){
    //     std::cout << nameVector[i] << ": " << balanceVector[i] << "\n";
    // }

}