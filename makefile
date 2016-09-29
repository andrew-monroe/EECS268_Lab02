Lab02: main.o MedicalExecutive.o City.o
	g++ -g -std=c++11 -Wall main.o MedicalExecutive.o City.o -o Lab02

main.o: main.cpp MedicalExecutive.h City.h
	g++ -g -std=c++11 -Wall -c main.cpp

MedicalExecutive.o: MedicalExecutive.h MedicalExecutive.cpp LinkedList.h LinkedList.hpp Node.h Node.hpp
	g++ -std=c++11 -g -Wall -c MedicalExecutive.cpp

City.o: City.h City.cpp
	g++ -std=c++11 -g -Wall -c City.cpp

clean:
	rm *.o Lab02
