#include <iostream>
#include <fstream>
#include <string>
using std::string;

int numProcess = 5;
int numResources = 3;

int main(int argc, char* argv[]) { 

    if(argc > 2) {
        std::cerr << "Invalid command line arguments" << std::endl;
        exit(1);
    } else if (argc == 1) {
        std::cerr << "Please include input txt file as command line argument" << std::endl;
        exit(1);
    }

    string filename = argv[1];
    std::ifstream fin(filename);

    // Represents number of available instances of each resource
    int available[numResources];

    // Represents number of allocated instances
    // of each resource to a process
    int allocated[numProcess][numResources];
    
    // Represents max number of allocated instances 
    // of each resource allowed
    int max[numProcess][numResources];

    int input = 0;
    int processCount = 0;
    int i = 0;
    while(!fin.eof()) {
        fin >> input;
        
        if(processCount >= numProcess) {
            available[i] = input;
            ++i;
        } else if(i < 3) {
            allocated[processCount][i] = input;
            ++i;
        } else if(i < 6){
            max[processCount][i - 3] = input;
            if(++i == 6) {
                i = 0;
                ++processCount;
            }
        }   
    }

    int need[numProcess][numResources];
    for(int i = 0; i < numProcess; ++i) {
        for(int k = 0; k < numResources; ++k)
    }


    int finish[numProcess];
    for(int& e : finish){
        e = false;
    }

}