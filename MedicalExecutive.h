/**
*	@file MedicalExecutive.h
*	@author Andy Monroe
*	@date 09-29-2016
*	@brief Header file for MedicalExecutive class. MedicalExecutive takes an
        input file to build a list of infected cities. MedicalExecutive prompts
        the user for various actions to take regarding this linked list of
        cities, and contains the code necessary to perform those actions using
        linked list of City values and their operations.
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
        /** @pre None.
    	*   @post Three empty lists created and file name is recorded.
    	*/
        MedicalExecutive(std::string fileName);

        /** @pre All three list pointers are allocated.
    	*   @post All three lists are deallocated.
    	*/
        ~MedicalExecutive();

        /** @pre m_cities, m_tempCities, and m_quarentine are allocated.
    	*   @post Program is finished running.
    	*/
        void run();

    private:
        std::string m_name;
        LinkedList<City>* m_cities;
        LinkedList<City>* m_quarentine;
        LinkedList<City>* m_tempCities;

        /** @pre fileName contains the name of the input file.
    	*   @post The city and quarentine lists are filled with data from the
                input file.
            @return true if file was read successfully, false otherwise.
    	*/
        bool readFile();

        /** @pre None.
    	*   @post None.
    	*   @return user's choice.
    	*/
        int menu();

        /** @pre m_cities is allocated.
    	*   @post one more city is in m_cities.
    	*/
        void addCity(City newCity);

        /** @pre m_tempCities is allocated.
    	*   @post one more city is in m_tempCities.
    	*/
        void addTempCity(City newCity);

        /** @pre m_quarentine is allocated.
    	*   @post one more city is in m_quarentine.
    	*/
        void addQuarentine(City newCity);

        /** @pre m_cities, m_tempCities, and m_quarentine are allocated.
    	*   @post all cities in m_cities have had infection level raised by 1.
    	*/
        void increaseInfectionOfAll();

        /** @pre m_cities and m_quarentine are allocated and a city with name
                cityName exists.
    	*   @post The city with name cityName has had infection level raised by
                1.
    	*/
        void increaseInfectionOfOne(std::string cityName);

        /** @pre m_cities and m_quarentine are allocated.
    	*   @post None.
    	*/
        void showCityStatus(std::string cityName);

        /** @pre m_quarentine is allocated.
    	*   @post QuarentineLog.txt is created and filled with information of
                all cities in m_quarentine.
    	*/
        void createQuarentineLog();

        /** @pre m_cities and m_quarentine are allocated.
    	*   @post None.
    	*/
        void showCitiesWithInfectionLevel();
};

#endif
