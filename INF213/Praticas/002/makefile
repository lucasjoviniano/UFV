all: Segmento.o Retangulo.o Circulo.o FigBase.o TesteFiguras3.o
	g++ -g -o TesteFiguras Segmento.o Retangulo.o Circulo.o FigBase.o TesteFiguras3.o

Segmento.o: Segmento.h Segmento.cpp
	g++ -g -c Segmento.h Segmento.cpp

Retangulo.o: Retangulo.h Retangulo.cpp
	g++ -g -c Retangulo.h Retangulo.cpp

Circulo.o: Circulo.h Circulo.cpp
	g++ -g -c Circulo.h Circulo.cpp

FigBase.o: FigBase.h FigBase.cpp
	g++ -g -c FigBase.h FigBase.cpp

TesteFiguras3.o: TesteFiguras3.cpp
	g++ -g -c TesteFiguras3.cpp