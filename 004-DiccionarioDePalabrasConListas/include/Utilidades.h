#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <string>
#include <iostream>
#include "DicPalabra.h"
using namespace std;

string convertirPalabraMayuscula(string palabra);

void InterpreteComandos (string comando, DicPalabras d);

void buscar(DicPalabras d);

void insertar(DicPalabras d);

void vaciar(DicPalabras d);

void partidas();

void alocado();

void cesar();

void juanagra();

void saco();

void consome();

void alargapalabras();

void InterpreteComandos (string comando);
#endif // UTILIDADES_H
