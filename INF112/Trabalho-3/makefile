all: Polinomio.o main.o
	g++ -std=c++03 -g -o main Polinomio.o main.o

Polinomio.o: Polinomio.h Polinomio.cpp
	g++ -std=c++03 -g -c Polinomio.h Polinomio.cpp

main.o: main.cpp
	g++ -std=c++03 -g -c main.cpp
