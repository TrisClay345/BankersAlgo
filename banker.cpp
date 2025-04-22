#include <iostream>
#include <fstream>
#include <string>
using std::string;

// This must be changed if one wants to input different numbers of processes
const int numProcess = 5;
// This must be changed if one wants to input different numbers of resources
const int numResources = 3;

int main(int argc, char* argv[]) { 

    if(argc > 2) {
        std::cerr << "Invalid command line arguments" << std::endl;
        exit(1);
    } else if (argc == 1) {
        std::cerr << "Please include input txt file as command line argument" << std::endl;
        exit(1);
    }

    const string filename = argv[1];
    std::ifstream fin(filename);

    // Represents number of available instances of each resource
    int available[numResources];

    // Represents number of allocated instances
    // of each resource to a process
    int allocated[numProcess][numResources];
    
    // Represents max number of allocated instances 
    // of each resource allowed
    int max[numProcess][numResources];

    // Gets table values from the inputted text file
    int input = 0;
    int processCount = 0;
    int i = 0;
    while(!fin.eof()) {
        fin >> input;
        
        if(processCount >= numProcess) {
            available[i] = input;
            ++i;
        } else if(i < numResources) {
            allocated[processCount][i] = input;
            ++i;
        } else if(i < 2 * numResources){
            max[processCount][i - numResources] = input;
            if(++i == 2 * numResources) {
                i = 0;
                ++processCount;
            }
        }   
    }

    // Populates need table

    int need[numProcess][numResources];
    for(int i = 0; i < numProcess; ++i) {
        for(int j = 0; j < numResources; ++j) {
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }

    bool finish[numProcess] = {0};

    // Stores safe sequence
    int safeSeq[numProcess];

    int counter = 0;
    while(counter < numProcess) {
        // True when process is found that can have its needs filled
        bool found = false;
        // Check processes one by one seeing if they can finish with the current available resources
        for(int proc = 0; proc < numProcess; ++proc) {
            if(!finish[proc]) {
                int res;
                // Check if this process can have its needs filled by what's available
                for(res = 0; res < numResources; ++res) {
                    // This statement is true when a procedure requires more of a resource
                    // than is available at the moment (i.e. when it would have to wait)
                    if(need[proc][res] > available[res]) break;
                }
                // If it can be, 
                if(res == numResources) {
                    // free the processes current resources, adding them to what's available
                    for(int k = 0; k < numResources; ++k) {
                        available[k] += allocated[proc][k];
                    }

                    // Add this process to the safe sequence, since it can be finished and 
                    // released without having to wait on anything
                    safeSeq[counter++] = proc;

                    // Mark this procedure as finished
                    finish[proc] = true;

                    // A safe process has been found, so set found to true
                    found = true;
                }
            }
        }
        // If no process can be found that can finish with the available resources,
        // the system is not in a safe state
        if(found == false) {
            std::cout << "The system is not in a safe state." << std::endl;
            break;
        }
    }
    // If the system is safe, print the safe sequence (order that processes can be completed
    // without waiting)
    std::cout << "The system is in a safe state, and the safe sequence is: ";
    for(int i = 0; i < numProcess; ++i) {
        std::cout << 'p' << safeSeq[i] << ' ';
    }
    std::cout << std::endl;
}