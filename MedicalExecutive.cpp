/**
*	@file MedicalExecutive.cpp
*	@author Andy Monroe
*	@date 09-13-2016
*	@brief asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdf
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
    std::string cityName = "";
    int choice = 0;

    if (!readFile())
        return;

        while(choice != 6)
        {
            choice = menu();
            if(choice == 1)
            {
                increaseInfectionOfAll();
            }
            else if(choice == 2)
            {
                std::cout << "Enter the name of a city: ";
                std::cin.ignore(1, '\n');
                std::getline(std::cin, cityName);
                std::cout << std::endl;

                increaseInfectionOfOne(cityName);
            }
            else if(choice == 3)
            {
                std::cout << "Enter the name of a city: ";
                std::cin.ignore(1, '\n');
                std::getline(std::cin, cityName);

                showCityStatus(cityName);
            }
            else if(choice == 4)
            {
                createQuarentineLog();
            }
            else if(choice == 5)
            {
                showCitiesWithInfectionLevel();
            }
            else
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
    std::string input = "";
    City* newCity = new City;
    int size = 0;

    std::ifstream inFile;
    inFile.open(m_name);

    if (inFile.is_open())
    {
        inFile >> size;
        inFile.ignore(1, '\n');

        for (int x = 0; x < size; x++)
        {
            std::getline(inFile, input, ',');
            newCity->setName(input);
            std::getline(inFile, input, ',');
            newCity->setPopulation(std::stoi(input));
            std::getline(inFile, input);
            newCity->setInfectionLevel(std::stoi(input));

            addCity(*newCity);
        }
    }
    else
    {
        std::cout << "No file named \"" << m_name << "\" was found." <<
            std::endl;

        return(false);
    }

    return(true);
}

/*
    display menu and return user's integer choice
*/
int MedicalExecutive::menu()
{
    int choice = 0;

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

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again. "<< std::endl;
            std::cout << std::endl;
            choice = 0;
        }
        else if (choice < 1 || choice > 6)
        {
            std::cout << "Invalid choice. Try again." << std::endl;
            std::cout << std::endl;
        }
    } while (choice < 1 || choice > 6);

    return(choice);
}

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
    increase the infection level by 1 for all cities in the linked list
*/
void MedicalExecutive::increaseInfectionOfAll()
{
    City changedCity;
    City newCity;
    int tempLength = 0;

    tempLength = m_cities->getLength();

    std::cout << "tempLength: " << tempLength << std::endl;

    for (int x = 1; x <= tempLength; x++)
    {
        std::cout << "x: " << x << std::endl;
        changedCity = m_cities->getEntry(1);

        std::cout << "Incrementing " << changedCity.getName() << std::endl;
        changedCity.incrementInfectionLevel();

        if (changedCity.getInfectionLevel() == 1)
        {
            m_cities->removeFront();
            changedCity.setPopulation(changedCity.getPopulation() * 0.9);
            addTempCity(changedCity);
        }
        else if (changedCity.getInfectionLevel() == 2)
        {
            m_cities->removeFront();
            changedCity.setPopulation(changedCity.getPopulation() * 0.8);
            addTempCity(changedCity);
        }
        else if (changedCity.getInfectionLevel() == 3)
        {
            m_cities->removeFront();
            newCity = changedCity;
            changedCity.setPopulation(changedCity.getPopulation() * 0.75);
            newCity.setPopulation(newCity.getPopulation() * 0.25);
            newCity.setName("New " + changedCity.getName());
            addTempCity(changedCity);
            addTempCity(newCity);
        }
        else if (changedCity.getInfectionLevel() == 4)
        {
            m_cities->removeFront();

            addQuarentine(changedCity);
        }
    }

    tempLength = m_tempCities->getLength();

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
    City changedCity;
    City newCity;
    changedCity.setName(cityName);
    int x = m_cities->positionOf(changedCity);
    int tempLength = m_cities->getLength();

    if (x == 0)
    {
        if (m_quarentine->positionOf(changedCity) == 0)
        {
            std::cout << cityName << " does not exist." << std::endl;
        }
        else
        {
            std::cout << cityName << " has been quarentined. It can no " <<
                "longer be interacted with." << std::endl;
        }
        return;
    }

    changedCity = m_cities->getEntry(x);

    changedCity.incrementInfectionLevel();

    if (changedCity.getInfectionLevel() == 1)
    {
        m_cities->removeAt(x);
        changedCity.setPopulation(changedCity.getPopulation() * 0.9);
        addCity(changedCity);
    }
    else if (changedCity.getInfectionLevel() == 2)
    {
        m_cities->removeAt(x);
        changedCity.setPopulation(changedCity.getPopulation() * 0.8);
        addCity(changedCity);
    }
    else if (changedCity.getInfectionLevel() == 3)
    {
        m_cities->removeAt(x);
        newCity = changedCity;
        changedCity.setPopulation(changedCity.getPopulation() * 0.75);
        newCity.setPopulation(newCity.getPopulation() * 0.25);
        newCity.setName("New " + changedCity.getName());
        addCity(changedCity);
        addCity(newCity);
    }
    else if (changedCity.getInfectionLevel() == 4)
    {
        tempLength = m_quarentine->getLength();
        m_cities->removeAt(x);

        addQuarentine(changedCity);
    }
}

/*
    output the status (population and infection level) for a city with a
        specified name
*/
void MedicalExecutive::showCityStatus(std::string cityName)
{
    City statusCity;
    statusCity.setName(cityName);
    int positionCity = 0;
    int positionQuarentine = 0;

    std::string name = "";
    int population = 0;
    int infectionLevel = 0;

    positionCity = m_cities->positionOf(statusCity);
    positionQuarentine = m_quarentine->positionOf(statusCity);

    if(positionCity != 0)
    {
        name = m_cities->getEntry(positionCity).getName();
        population = m_cities->getEntry(positionCity).getPopulation();
        infectionLevel = m_cities->getEntry(positionCity).getInfectionLevel();

        std::cout << std::endl;
        std::cout << name << ":" << std::endl;
        std::cout << "\tPopulation: " << population << std::endl;
        std::cout << "\tInfection Level: " << infectionLevel << std::endl;
    }
    else if(positionQuarentine != 0)
    {
        name = m_quarentine->getEntry(positionQuarentine).getName();
        population = m_quarentine->getEntry(positionQuarentine).getPopulation();
        infectionLevel = m_quarentine->getEntry(positionQuarentine).getInfectionLevel();

        std::cout << std::endl;
        std::cout << name << ":" << std::endl;
        std::cout << "\tPopulation: " << population << std::endl;
        std::cout << "\tInfection Level: 4 [QUARENTINED]" << std::endl;
    }
    else
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
    int size = m_quarentine->getLength();

    std::ofstream outFile;
    outFile.open("QuarentineLog.txt");

    outFile << size << std::endl;

    for (int x = 1; x <= size; x++)
    {
        outFile << m_quarentine->getEntry(x).getName() << ", ";
        outFile << m_quarentine->getEntry(x).getPopulation() << ", ";
        outFile << m_quarentine->getEntry(x).getInfectionLevel() << std::endl;
    }

    outFile.close();

    std::cout << "Quarentine log completed." << std::endl;
}

/*
    output a list of cities that match a certain infection level
*/
void MedicalExecutive::showCitiesWithInfectionLevel()
{
    int level = 0;
    int size = 0;

    std::cout << "Enter an infection level: ";
    std::cin >> level;
    std::cout << std::endl;
    while ( std::cin.fail() )
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Bad input. Try again." << std::endl << std::endl;
        std::cout << "Enter an infection level: ";
        std::cin >> level;
        std::cout << std::endl
    }

    if(level > 4)
    {
        std::cout << "There are no cities with infection level greater than 4."
            << std::endl;

        return;
    }

    std::cout << "Cities with infection level of at least " << level << ":" <<
        std::endl;

    if(level == 4)
    {
        size = m_quarentine->getLength();

        for(int x = 1; x <= size; x++)
        {
            std::cout << m_quarentine->getEntry(x).getName() << std::endl;
        }
    }
    else
    {
        size = m_cities->getLength();

        for (int x = 1; x <= size; x++)
        {
            if(m_cities->getEntry(x).getInfectionLevel() >= level)
            {
                std::cout << m_cities->getEntry(x).getName() << std::endl;
            }
        }

        size = m_quarentine->getLength();

        for(int x = 1; x <= size; x++)
        {
            std::cout << m_quarentine->getEntry(x).getName() << std::endl;
        }
    }
}
