all: Data.o Horario.o Agenda.o TestaAgenda.o
	g++ -g -o TestaAgenda Data.o Horario.o Agenda.o TestaAgenda.o

Agenda.o: Agenda.h Agenda.cpp
	g++ -g -c Agenda.h Agenda.cpp

Data.o: Data.h Data.cpp
	g++ -g -c Data.h Data.cpp

Horario.o: Horario.h Horario.cpp
	g++ -g -c Horario.h Horario.cpp

main.o: TestaAgenda.cpp
	g++ -g -c TestaAgenda.cpp