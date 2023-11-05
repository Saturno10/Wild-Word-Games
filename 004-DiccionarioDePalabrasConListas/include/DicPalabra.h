#ifndef DICPALABRAS_H
#define DICPALABRAS_H

#include <iostream>
#include <list>
#include <string>

using namespace std;


class DicPalabras
{
public:
    DicPalabras(); //Constructor por defecto
    virtual ~DicPalabras(); //Destructor virtual
    void vaciar();
    void insertar(string palabra);
    bool buscar (string palabra);
    int GetNumElem() {return contador;}

protected:

private: //Solo accesible por la clase
    list<string> lista; //Almacena las palabras del diccionario
    //list <int>::interator it; //Interador lista no hace falta se puede hacer localmente cuando lo necesite
    int contador; //Es el contador M del metodo void insertar()
};










#endif // DICPALABRAS_H
