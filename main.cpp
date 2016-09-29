/**
*	@file main.cpp
*	@author Andy Monroe
*	@date 09-29-2016
*	@brief aasdfasdfasdfasdfasdfasdfasdfasdfasdf
*/

#include <iostream>
#include "MedicalExecutive.h"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "This program requires one file name to be entered as " <<
            " an argument." << std::endl;

        return(0);
    }

    MedicalExecutive medEx(argv[1]);
    medEx.run();

    return(0);
}
