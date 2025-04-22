# Banker's Algorithm
## Tristian Clayman | 4/22/2025
The banker's algorithm is an algorithm for finding a safe sequence of processes that can be completed without causing a deadlock given a certain number of allocated and available resources. 

The algorithm gets its name from bankers who must choose carefully how to hand out money (resources) to their customers (processes) such that there is always enough money in the bank for the next customer (avoiding deadlock).

The program takes an input of a table of values, where each row represents a process. The first n integers represent the number of each resource (n resources) that is currently allocated to the process. The second n integers represent the number of each resource that the process needs for completion . The final row of n integers does not represent a process and instead represents the currently available number of instances for each resource (money in the bank).

## Brief Deadlock Explanation
When a process runs, it tries to get all the resources that it needs. If there is enough resources for the process, it completes its execution before releasing all the resources it had. If there is not enough resources, it will begin to run and then need to wait for another process to free its resources before taking those to complete its execution. If this continues on long enough, processes will wait on other waiting processes, and this can cause cycles of waiting programs which are stuck and cannot complete their execution. This is called deadlock. 

The banker's algorithm tells you if the processes are in a safe state (whether it is possible to have all the processes run consecutively without waiting), and if it is, what order of process execution allows the unconflicted execution of all the processes.

This program uses the banker's algorithm to give you the correct safe sequence for the given processes and resources. 

## Usage
Note:
By default, the number of expected processes is 5 and the number of resources is 3. If you want to change this, change the two variables at the top of banker.cpp before compilation.

To use this program, first compile it using the command below. 
```c++
    g++ banker.cpp -o banker
```

Then, create your text file with the correctly formatted tables (as discussed previously.)
See the included input.txt as an example.

Once that is done, run the program like so:
```c++
    ./banker input.txt
```

## License
[MIT](https://choosealicense.com/licenses/mit/)