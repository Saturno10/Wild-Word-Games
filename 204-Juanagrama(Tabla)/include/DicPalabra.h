#ifndef DICPALABRAS_H
#define DICPALABRAS_H

#include <iostream>
#include <list>
#include <string>
#include "TablaHash.h"

using namespace std;

//Atributos y métodos del diccionario
class DicPalabras
{
public:
    DicPalabras(); //Constructor por defecto
    virtual ~DicPalabras(); //Destructor virtual
    void vaciar();
    void insertar(string palabra);
    bool buscar (string palabra);
    int GetNumElem() {return tabla.numElem();}
    string juanagra(string palabra);

protected:

private: //Solo accesible por la clase
    TablaHash tabla; //Almacena las palabras del diccionario
    //list <int>::interator it; //Interador lista no hace falta se puede hacer localmente cuando lo necesite

};

#endif // DICPALABRAS_H