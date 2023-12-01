#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <string>
#include <iostream>
#include "DicPalabra.h"
using namespace std;
//Todas las funciones con las que se tiene que trabajar con el diccionario
string convertirPalabraMayuscula(string palabra);

void InterpreteComandos(DicPalabras &d);

void buscar(DicPalabras &d);

void insertar(DicPalabras &d);

void vaciar(DicPalabras &d);

void partidas();

void alocado();

void cesar();

void juanagra();

void saco();

void consome();

void alargapalabras(DicPalabras &d);


#endif // UTILIDADES_H