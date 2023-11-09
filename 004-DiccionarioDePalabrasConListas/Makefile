a.out: main.o Utilidades.o DicPalabra.o
	g++ main.o Utilidades.o DicPalabra.o

main.o: main.cpp Utilidades.h
	g++ -c main.cpp

Utilidades.o: Utilidades.cpp Utilidades.h
	g++ -c Utilidades.cpp

DicPalabra.o: DicPalabra.cpp DicPalabra.h
	g++ -c DicPalabra.cpp
