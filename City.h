/**
*	@file City.h
*	@author Andy Monroe
*	@date 09-29-2016
*	@brief asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdf
*/

#include <string>
#include <iostream>

#ifndef City_h
#define City_h

class City
{
    public:
        City();
        bool operator== (City c) const;
        bool operator>= (City c) const;
        bool operator<= (City c) const;
        std::string getName() const;
        void setName(std::string newName);
        int getPopulation() const;
        void setPopulation(int pop);
        int getInfectionLevel() const;
        void setInfectionLevel(int level);
        void incrementInfectionLevel();

    private:
        std::string m_name;
        int m_population;
        int m_infectionLevel;
};

#endif
