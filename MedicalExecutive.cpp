/**
*	@file MedicalExecutive.cpp
*	@author Andy Monroe
*	@date 09-29-2016
*	@brief Implementation file for MedicalExecutive class. MedicalExecutive
        takes an input file to build a list of infected cities. MedicalExecutive
        prompts the user for various actions to take regarding this linked list
        of cities, and contains the code necessary to perform those actions
        using linked list of City values and their operations.
*/

#include "MedicalExecutive.h"

/*
    initalize the m_name variable to be the user given file name
    initialize m_cities to a null pointer
*/
MedicalExecutive::MedicalExecutive(std::string fileName)
{
    m_name = fileName;
    m_cities = new LinkedList<City>;
    m_quarentine = new LinkedList<City>;
    m_tempCities = new LinkedList<City>;
}

/*
    delete the m_cities heap-allocated variable
*/
MedicalExecutive::~MedicalExecutive()
{
    delete m_cities;
    delete m_quarentine;
    delete m_tempCities;
}

/*
    toplevel pattern of how the program is supposed to function
*/
void MedicalExecutive::MedicalExecutive::run()
{
    //create and intialize variables
    std::string cityName = "";
    int choice = 0;

    //if the user-given file could not be read, quit
    if (!readFile())
        return;

    //loop until user chooses the quit option
    while(choice != 6)
    {
        //call menu method to get user's choice
        choice = menu();

        if(choice == 1) //increase infection level of all cities
        {
            increaseInfectionOfAll();
        }
        else if(choice == 2) //increase infection level of a specific city
        {
            std::cout << "Enter the name of a city: ";
            std::cin.ignore(1, '\n');
            std::getline(std::cin, cityName);
            std::cout << std::endl;

            increaseInfectionOfOne(cityName);
        }
        else if(choice == 3) //get and output status of a specific city
        {
            std::cout << "Enter the name of a city: ";
            std::cin.ignore(1, '\n');
            std::getline(std::cin, cityName);

            showCityStatus(cityName);
        }
        else if(choice == 4) //create a quarentine log in a text file
        {
            createQuarentineLog();
        }
        else if(choice == 5) //find cities with at least a certain infection level
        {
            showCitiesWithInfectionLevel();
        }
        else //quit
        {
            std::cout << "Goodbye!" << std::endl;
        }

        std::cout << std::endl;
    }
}

/*
    read in the information from the provided text file and put into a linked
        list
    return false if no file with the user-specified name exists
*/
bool MedicalExecutive::readFile()
{
    //create variables
    std::string input = "";
    City* newCity = new City;
    int size = 0;

    //create and open input file
    std::ifstream inFile;
    inFile.open(m_name);

    //ensure that input file is indeed open before proceeding
    if (inFile.is_open())
    {
        //take input of number of entries to record
        inFile >> size;
        inFile.ignore(1, '\n');

        //record entries from file into a linked list of cities
        for (int x = 0; x < size; x++)
        {
            std::getline(inFile, input, ',');
            newCity->setName(input);
            std::getline(inFile, input, ',');
            newCity->setPopulation(std::stoi(input));
            std::getline(inFile, input);
            newCity->setInfectionLevel(std::stoi(input));

            //quarentine cities with infection level of at least 4
            if (newCity->getInfectionLevel() >= 4)
            {
                //adding city to quarentine linked list
                addQuarentine(*newCity);
            }
            else
            {
                //adding city to unquarentined city linked list
                addCity(*newCity);
            }
        }
    }
    else //input file could not be found, return false
    {
        std::cout << "No file named \"" << m_name << "\" was found." <<
            std::endl;

        return(false);
    }

    //input file was successfully read from
    return(true);
}

/*
    display menu and return user's integer choice
*/
int MedicalExecutive::menu()
{
    //create and intialize choice variable
    int choice = 0;

    //loop until user makes a valid choice
    do
    {
        std::cout << "Make a selection: " << std::endl << std::endl;
        std::cout << "1) Increase infection level of all cities." << std::endl;
        std::cout << "2) Increase infection level of specific city." <<
            std::endl;
        std::cout << "3) Print status of a specific city." << std::endl;
        std::cout << "4) Create quarantine log." << std::endl;
        std::cout << "5) Print all cities above an infection level." <<
            std::endl;
        std::cout << "6) Exit." << std::endl;
        std::cout << std::endl;
        std::cout << "Choice: ";
        std::cin >> choice;
        std::cout << std::endl;

        //check to make sure user gave an integer
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again. "<< std::endl;
            std::cout << std::endl;
            choice = 0;
        }
        else if (choice < 1 || choice > 6) //tell user to pick something else
        {
            std::cout << "Choice must be a value from 1 to 6." << std::endl;
            std::cout << std::endl;
        }
    } while (choice < 1 || choice > 6);

    //return the user's choice
    return(choice);
}

/*
    take in a City value and sort it into m_cities LinkedList
*/
void MedicalExecutive::addCity(City newCity)
{
    int length = m_cities->getLength();

    if(length == 0)
    {
        m_cities->addFront(newCity);
    }

    for (int y = 1; y <= length; y++)
    {
        if (y == length)
        {
            m_cities->addBack(newCity);
        }
        else if(newCity >= m_cities->getEntry(y))
        {
            m_cities->insert(y, newCity);
        }

    }
}

/*
    take in a City value and sort it into m_tempCities LinkedList
*/
void MedicalExecutive::addTempCity(City newCity)
{
    int length = m_tempCities->getLength();

    if(length == 0)
    {
        m_tempCities->addFront(newCity);
    }

    for (int y = 1; y <= length; y++)
    {
        if (y == length)
        {
            m_tempCities->addBack(newCity);
        }
        else if(newCity >= m_tempCities->getEntry(y))
        {
            m_tempCities->insert(y, newCity);
        }

    }
}

/*
    take in a City value and sort it into m_quarentine LinkedList
*/
void MedicalExecutive::addQuarentine(City newCity)
{
    int length = m_quarentine->getLength();

    if(length == 0)
    {
        m_quarentine->addFront(newCity);
    }

    for (int y = 1; y <= length; y++)
    {
        if (y == length)
        {
            m_quarentine->addBack(newCity);
        }
        else if(newCity >= m_quarentine->getEntry(y))
        {
            m_quarentine->insert(y, newCity);
        }

    }
}

/*
    increase the infection level by 1 for all cities in m_cities
*/
void MedicalExecutive::increaseInfectionOfAll()
{
    //create necessary variables
    City changedCity;
    City newCity;
    int tempLength = 0;

    //record length of m_cities at this instant
    tempLength = m_cities->getLength();

    //loop for whatever the length of m_cities was
    for (int x = 1; x <= tempLength; x++)
    {
        //changedCity gets the first value in m_cities
        changedCity = m_cities->getEntry(1);

        //increase infection level of changedCity by 1
        changedCity.incrementInfectionLevel();

        //what to do to changedCity depending on what its new infection level is
        if (changedCity.getInfectionLevel() == 1) //infection level 1
        {
            //remove changedCity from m_cities
            m_cities->removeFront();

            //reduce changedCity's population 10%
            changedCity.setPopulation(changedCity.getPopulation() * 0.9);

            //add changedCity to temporary storate in m_tempCities
            addTempCity(changedCity);
        }
        else if (changedCity.getInfectionLevel() == 2) //infection level 2
        {
            //remove changedCity from m_cities
            m_cities->removeFront();

            //reduce changedCity's population 20%
            changedCity.setPopulation(changedCity.getPopulation() * 0.8);
            addTempCity(changedCity);
        }
        else if (changedCity.getInfectionLevel() == 3) //infection level 3
        {
            //remove changedCity from m_cities
            m_cities->removeFront();

            //create a new city from changedCity
            newCity = changedCity;

            //reduce changedCity's population 25%
            changedCity.setPopulation(changedCity.getPopulation() * 0.75);

            //set newCity's population to 25% of changedCity's original population
            newCity.setPopulation(newCity.getPopulation() * 0.25);

            //add "New " to the beginning of newCity's name
            newCity.setName("New " + changedCity.getName());

            //add changedCity and newCity to temporary storate in m_tempCities
            addTempCity(changedCity);
            addTempCity(newCity);
        }
        else if (changedCity.getInfectionLevel() == 4) //infection level 4
        {
            //remove changedCity from m_cities
            m_cities->removeFront();

            //add changedCity to m_quarentine linked list
            addQuarentine(changedCity);
        }
    }

    //set tempLength to length of m_tempCities at this instant
    tempLength = m_tempCities->getLength();

    //empty out m_tempCities into m_cities
    for (int x = 1; x <= tempLength; x++)
    {
        addCity(m_tempCities->getEntry(1));
        m_tempCities->removeFront();
    }
}

/*
    increase the infection level by 1 for a city with a specified name
*/
void MedicalExecutive::increaseInfectionOfOne(std::string cityName)
{
    //create necessary variables
    City changedCity;
    City newCity;
    changedCity.setName(cityName);
    int x = m_cities->positionOf(changedCity); //position of given city
    int tempLength = m_cities->getLength(); //length of m_cities

    //check to make sure city exists and is not in quarentine
    if (x == 0)
    {
        if (m_quarentine->positionOf(changedCity) == 0) //doesn't exist
        {
            std::cout << cityName << " does not exist." << std::endl;
        }
        else //is quarentined
        {
            std::cout << cityName << " has been quarentined. It can no " <<
                "longer be interacted with." << std::endl;
        }

        //quit method
        return;
    }

    //changedCity is the city being altered
    changedCity = m_cities->getEntry(x);

    //changedCity's infection level increased by 1
    changedCity.incrementInfectionLevel();

    //what to do to changedCity depending on what its new infection level is
    if (changedCity.getInfectionLevel() == 1) //infection level 1
    {
        //remove changedCity from m_cities
        m_cities->removeAt(x);

        //reduce changedCity's population 10%
        changedCity.setPopulation(changedCity.getPopulation() * 0.9);

        //add changedCity back to m_cities
        addCity(changedCity);
    }
    else if (changedCity.getInfectionLevel() == 2) //infection level 2
    {
        //remove changedCity from m_cities
        m_cities->removeAt(x);

        //reduce changedCity's population 20%
        changedCity.setPopulation(changedCity.getPopulation() * 0.8);

        //add changedCity back to m_cities
        addCity(changedCity);
    }
    else if (changedCity.getInfectionLevel() == 3) //infection level 3
    {
        //remove changedCity from m_cities
        m_cities->removeAt(x);

        //create a new city from changedCity
        newCity = changedCity;

        //reduce changedCity's population 25%
        changedCity.setPopulation(changedCity.getPopulation() * 0.75);

        //set newCity's population to 25% of changedCity's original population
        newCity.setPopulation(newCity.getPopulation() * 0.25);

        //add "New " to the beginning of newCity's name
        newCity.setName("New " + changedCity.getName());

        //add changedCity and newCity back to m_cities
        addCity(changedCity);
        addCity(newCity);
    }
    else if (changedCity.getInfectionLevel() == 4) //infection level 4
    {
        //remove changedCity from m_cities
        m_cities->removeAt(x);

        //add changedCity to m_quarentine
        addQuarentine(changedCity);
    }
}

/*
    output the status (population and infection level) for a city with a
        specified name
*/
void MedicalExecutive::showCityStatus(std::string cityName)
{
    //create necessary variables
    City statusCity;
    statusCity.setName(cityName);
    int positionCity = 0;
    int positionQuarentine = 0;
    std::string name = "";
    int population = 0;
    int infectionLevel = 0;

    //find the position of the given city in m_cities/m_quarentine
    positionCity = m_cities->positionOf(statusCity);
    positionQuarentine = m_quarentine->positionOf(statusCity);

    //if statusCity exists, get its status and output to console
    if(positionCity != 0) //if statusCity is in m_cities
    {
        name = m_cities->getEntry(positionCity).getName();
        population = m_cities->getEntry(positionCity).getPopulation();
        infectionLevel = m_cities->getEntry(positionCity).getInfectionLevel();

        std::cout << std::endl;
        std::cout << name << ":" << std::endl;
        std::cout << "\tPopulation: " << population << std::endl;
        std::cout << "\tInfection Level: " << infectionLevel << std::endl;
    }
    else if(positionQuarentine != 0) //if statusCity is in m_quarentine
    {
        name = m_quarentine->getEntry(positionQuarentine).getName();
        population = m_quarentine->getEntry(positionQuarentine).getPopulation();
        infectionLevel = m_quarentine->getEntry(positionQuarentine).getInfectionLevel();

        std::cout << std::endl;
        std::cout << name << ":" << std::endl;
        std::cout << "\tPopulation: " << population << std::endl;
        std::cout << "\tInfection Level: " << infectionLevel <<
            " [QUARENTINED]" << std::endl;
    }
    else //no record of statusCity exists
    {
        std::cout << std::endl;
        std::cout << "Could not find a city named \"" << cityName << "\"." <<
            std::endl;
    }
}

/*
    output city information from the linked list into an output file
*/
void MedicalExecutive::createQuarentineLog()
{
    //create variable to store size of m_quarentine at an instant
    int size = m_quarentine->getLength();

    //create output file
    std::ofstream outFile;
    outFile.open("QuarentineLog.txt");

    //output number of entries to be recorded
    outFile << size << std::endl;

    //loop through outputing every entry within m_quarentine
    for (int x = 1; x <= size; x++)
    {
        outFile << m_quarentine->getEntry(x).getName() << ", ";
        outFile << m_quarentine->getEntry(x).getPopulation() << ", ";
        outFile << m_quarentine->getEntry(x).getInfectionLevel() << std::endl;
    }

    //close the output file
    outFile.close();

    //confirmation
    std::cout << "Quarentine log completed." << std::endl;
}

/*
    output a list of cities that match a certain infection level
*/
void MedicalExecutive::showCitiesWithInfectionLevel()
{
    //create necessary variables
    int level = 0;
    int size = 0;
    bool noneFound = true;

    //gather user input on what infection level to check against
    std::cout << "Enter an infection level: ";
    std::cin >> level;
    std::cout << std::endl;
    //ensure user gave valid input
    while ( std::cin.fail() || level < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Bad input. Try again." << std::endl << std::endl;
        std::cout << "Enter an infection level: ";
        std::cin >> level;
        std::cout << std::endl;
    }

    std::cout << "Cities with infection level of at least " << level << ":" <<
        std::endl;

    //all cities with infection level 4+ are quarentined, so only quarentine is
    //outputed here
    if(level >= 4)
    {
        //set size to the length of m_quarentine at an instant
        size = m_quarentine->getLength();

        //loop through original size of m_quarentine
        for(int x = 1; x <= size; x++)
        {
            //if city with specified infection level or higher is found
            if(m_cities->getEntry(x).getInfectionLevel() >= level)
            {
                //output the city's name
                std::cout << m_quarentine->getEntry(x).getName() << std::endl;

                //record that a city was found
                noneFound = false;
            }
        }
    }
    else
    {
        //set size to the length of m_cities at an instant
        size = m_cities->getLength();

        //loop through original size of m_quarentine
        for (int x = 1; x <= size; x++)
        {
            //if city with specified infection level or higher is found
            if(m_cities->getEntry(x).getInfectionLevel() >= level)
            {
                //output the city's name
                std::cout << m_cities->getEntry(x).getName() << std::endl;

                //record that a city was found
                noneFound = false;
            }
        }

        //set size to the length of m_quarentine at an instant
        size = m_quarentine->getLength();

        //loop through original size of m_quarentine
        for(int x = 1; x <= size; x++)
        {
            //if city with specified infection level or higher is found
            if(m_cities->getEntry(x).getInfectionLevel() >= level)
            {
                //output the city's name
                std::cout << m_quarentine->getEntry(x).getName() << std::endl;

                //record that a city was found
                noneFound = false;
            }
        }
    }
}
