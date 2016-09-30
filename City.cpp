/**
*	@file City.cpp
*	@author Andy Monroe
*	@date 09-29-2016
*	@brief asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdf
*/
#include "City.h"

/*
    initializes member variables to default values
*/
City::City()
{
    m_name = "";
    m_population = 0;
    m_infectionLevel = 0;
}


/*
    overloads the == operator to work with City class variables
    returns true if two cities have the same name
*/
bool City::operator== (City c) const
{
    if(m_name == c.getName())
    {
        return(true);
    }

    return(false);
}

/*
    overloads the > operator to work with City class variables
    returns true if the left side city has greater population than the right
        side city
*/
bool City::operator>= (City c) const
{
    if(m_population >= c.getPopulation())
    {
        return(true);
    }

    return(false);
}

/*
    overloads the < operator to work with City class variables
    returns true if the left side city has lesser population than the right
        side city
*/
bool City::operator<= (City c) const
{
    if(m_population <= c.getPopulation())
    {
        return(true);
    }

    return(false);
}

/*
    returns the name of the city
*/
std::string City::getName() const
{
    return(m_name);
}

/*
    sets the name of the city to a specified string
*/
void City::setName(std::string newName)
{
    m_name = newName;
}

/*
    returns the population number
*/
int City::getPopulation() const
{
    return(m_population);
}

/*
    sets the population value to a specified integer
*/
void City::setPopulation(int pop)
{
    m_population = pop;
}

/*
    returns the infection level of the city
*/
int City::getInfectionLevel() const
{
    return(m_infectionLevel);
}

/*
    sets the infection level of the city to a specified integer
*/
void City::setInfectionLevel(int level)
{
    m_infectionLevel = level;
}

/*
    increases the city's infection level by 1
*/
void City::incrementInfectionLevel()
{
    std::cout << "Infection Level of " << m_name << " upgraded from " <<
        m_infectionLevel << " to " << m_infectionLevel+1 << "." << std::endl;

    m_infectionLevel++;
}
