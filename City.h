/**
*	@file City.h
*	@author Andy Monroe
*	@date 09-29-2016
*	@brief Header file for City class, including methods for various operations
        that can be performed on City and three overloaded operators. City
        classes have a string name value, an integer population value, and an
        integer infection value.
*/

#include <string>
#include <iostream>

#ifndef City_h
#define City_h

class City
{
    public:
        /*
            initializes member variables to default values
        */
        City();

        /*
            overloads the == operator to work with City class variables
            returns true if two cities have the same name
        */
        bool operator== (City c) const;

        /*
            overloads the >= operator to work with City class variables
            returns true if the left side city has greater or equal population
            compared to the right side city
        */
        bool operator>= (City c) const;

        /*
            overloads the <= operator to work with City class variables
            returns true if the left side city has lesser or equal population compared
            to the right side city
        */
        bool operator<= (City c) const;

        /*
            returns the name of the city
        */
        std::string getName() const;

        /*
            sets the name of the city to a specified string
        */
        void setName(std::string newName);

        /*
            returns the population number
        */
        int getPopulation() const;

        /*
            sets the population value to a specified integer
        */
        void setPopulation(int pop);

        /*
            returns the infection level of the city
        */
        int getInfectionLevel() const;

        /*
            sets the infection level of the city to a specified integer
        */
        void setInfectionLevel(int level);

        /*
            increases the city's infection level by 1
        */
        void incrementInfectionLevel();

    private:
        std::string m_name;
        int m_population;
        int m_infectionLevel;
};

#endif
