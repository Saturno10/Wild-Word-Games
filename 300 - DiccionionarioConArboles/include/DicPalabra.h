#ifndef DICPALABRAS_H
#define DICPALABRAS_H

#include <iostream>
#include <list>
#include <string>
#include "TablaHash.h"
#include "ArbolTrie.h"

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
    int GetNumElem() {return arbolTrie.numElem();}

protected:

private: //Solo accesible por la clase
    ArbolTrie arbolTrie;
    //TablaHash tabla; //Almacena las palabras del diccionario
    //list <int>::interator it; //Interador lista no hace falta se puede hacer localmente cuando lo necesite

};










#endif // DICPALABRAS_H