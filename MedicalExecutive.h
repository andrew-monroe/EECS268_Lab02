/**
*	@file MedicalExecutive.h
*	@author Andy Monroe
*	@date 09-13-2016
*	@brief asfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdf
*/

#include <iostream>
#include <fstream>
#include <string>
#include "City.h"
#include "LinkedList.h"

#ifndef MedicalExecutive_h
#define MedicalExecutive_h

class MedicalExecutive
{
    public:

        /*
            initalize the m_name variable to be the user given file name
            initialize m_cities to a null pointer
        */
        MedicalExecutive(std::string fileName);

        /*
            delete the m_cities heap-allocated variable
        */
        ~MedicalExecutive();

        /*
            toplevel pattern of how the program is supposed to function
        */
        void run();

    private:
        std::string m_name;
        LinkedList<City>* m_cities;
        LinkedList<City>* m_quarentine;
        LinkedList<City>* m_tempCities;

        /*
            read in the information from the provided text file and put into a
            linked list
            return false if no file with the user-specified name exists
        */
        bool readFile();

        /*
            display menu and return user's integer choice
        */
        int menu();

        /*
            take in a City value and sort it into m_cities LinkedList
        */
        void addCity(City newCity);

        /*
            take in a City value and sort it into m_tempCities LinkedList
        */
        void addTempCity(City newCity);

        /*
            take in a City value and sort it into m_quarentine LinkedList
        */
        void addQuarentine(City newCity);

        /*
            increase the infection level by 1 for all cities in m_cities
        */
        void increaseInfectionOfAll();

        /*
            increase the infection level by 1 for a city with a specified name
        */
        void increaseInfectionOfOne(std::string cityName);

        /*
            output the status (population and infection level) for a city with a
                specified name
        */
        void showCityStatus(std::string cityName);

        /*
            output city information from the linked list into an output file
        */
        void createQuarentineLog();

        /*
            output a list of cities that match a certain infection level
        */
        void showCitiesWithInfectionLevel();
};

#endif
