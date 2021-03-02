#include <fstream>
#include <iostream>

int main() {

    /** Let write to a file and some user input. */
    char data[100];

    // open file to write
    std::ofstream outfile;
    outfile.open("myFile.txt");

    std::cout << "Writing to file" << std::endl;
    std::cout << "Enter your name: " << std::endl;
    std::cin.getline(data, 100); // save whatever is entered to data var, expect max length 100;

    // write input to file
    outfile << data << std::endl;

    std::cout << "Enter your age:" << std::endl;
    std::cin >> data; // write to file.
    // ignore clears the cin input buffer. This makes sure we don't overwrite something in cin
    // also preps the data var to be used for reading from file.
    std::cin.ignore(); 

    // write input to file again
    outfile << data << std::endl;

    // close the file
    outfile.close();

    /** Lets open the file for reading */
    std::ifstream infile;
    infile.open("myFile.txt");

    std::cout << "Reading from the file" << std::endl;
    // reads first line in myFile.txt and writes to screen
    infile >> data;
    std::cout << data << std::endl;

    // writes second line in myFile.txt and writes to screen
    infile >> data;
    std::cout << data << std::endl;

    // close the file.
    infile.close();

    return 0;
}