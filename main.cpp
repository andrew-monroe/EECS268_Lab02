/**
*	@file main.cpp
*	@author Andy Monroe
*	@date 09-29-2016
*	@brief The main.cpp file of the program. Checks to make sure correct number
        of arguments were given when program ran, then creates a
        MedicalExecutive object and executes its run method.
*/

#include <iostream>
#include "MedicalExecutive.h"

int main(int argc, char* argv[])
{
    //checks for proper number of command line arguments
    if (argc != 2)
    {
        std::cout << "This program requires one file name to be entered as " <<
            " an argument." << std::endl;

        return(0);
    }

    //create MedicalExecutive object using command line argument as file name
    //then execute run method
    MedicalExecutive medEx(argv[1]);
    medEx.run();

    return(0);
}
