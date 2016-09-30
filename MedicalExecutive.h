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
        MedicalExecutive(std::string fileName);
        ~MedicalExecutive();
        void run();

    private:
        std::string m_name;
        LinkedList<City>* m_cities;
        LinkedList<City>* m_quarentine;
        LinkedList<City>* m_tempCities;

        bool readFile();
        int menu();
        void addCity(City newCity);
        void addTempCity(City newCity);
        void addQuarentine(City newCity);
        void increaseInfectionOfAll();
        void increaseInfectionOfOne(std::string cityName);
        void showCityStatus(std::string cityName);
        void createQuarentineLog();
        void showCitiesWithInfectionLevel();
};

#endif
