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
        /** @pre None.
    	*   @post Member variables intitialized.
    	*/
        City();

        /** @pre None.
    	*   @post None.
    	*   @return true if the cities have the same name.
    	*/
        bool operator== (City c) const;

        /** @pre None.
    	*   @post None.
    	*   @return true if population of left side city is greater or equal to
                population of right side city.
    	*/
        bool operator>= (City c) const;

        /** @pre None.
    	*   @post None.
    	*   @return true if population of left side city is lesser or equal to
                population of right side city.
    	*/
        bool operator<= (City c) const;

        /** @pre None.
    	*   @post None.
    	*   @return m_name of the city.
    	*/
        std::string getName() const;

        /** @pre None.
    	*   @post Sets m_name of the city to newName.
    	*/
        void setName(std::string newName);

        /** @pre None.
    	*   @post None.
    	*   @return m_population of the city.
    	*/
        int getPopulation() const;

        /** @pre None.
    	*   @post Sets m_population of the city to pop.
    	*/
        void setPopulation(int pop);

        /** @pre None.
    	*   @post None.
    	*   @return m_infectionLevel of the city.
    	*/
        int getInfectionLevel() const;

        /*
            sets the infection level of the city to a specified integer
        */
        /** @pre None.
    	*   @post Sets the m_infectionLevel of the city to level.
    	*/
        void setInfectionLevel(int level);

        /** @pre None.
    	*   @post m_infectionLevel of the city raised by 1.
    	*/
        void incrementInfectionLevel();

    private:
        std::string m_name;
        int m_population;
        int m_infectionLevel;
};

#endif
