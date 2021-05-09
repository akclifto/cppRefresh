#include <iostream>
#include <csignal>
#include "windows.h"

void signalHandler (int sigNum) {
    std::cout << "Interrupt signal (" << sigNum << ") received." << std::endl;
    //other code here 
    //terminate program

    exit(sigNum);
}

int main() {
    //register the signal SIGINT and its handler
    signal(SIGINT, signalHandler);

    //Will need to CTRL+C to interrupt this while loop
    // while(1) {
    //     std::cout << "Going to sleep..." << std::endl;
    //     Sleep(1);
    // }

    int i = 0;

    while(++i) {
        std::cout << "Going to sleep..." << std::endl;
        // will automatically call the signal handler (ie, exit the program) once i == 5
        if(i == 5) {
            raise (SIGINT);
        }
        Sleep(1);
    }
    return 0;
}