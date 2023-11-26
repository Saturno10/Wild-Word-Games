#ifndef TABLAHASH_H
#define TABLAHASH_H
#include <string>
#include <iostream>
#include <list>

using namespace std;
class TablaHash{
private:
//NUEVO
    //list <string> T[TAM] -> DISPERSION ABIERTA DE TAMAÑO FIJO
        //Cada elemento de la tabla es una lista de string
        //CONSTRUCTOR: No hace falta se inicializa directamente en la cabecera.

    //list <string> *T -> DISPERSION ABIERTA DE TAMAÑO VARIABLE
        //Cada posicion de la tabla apunta a una lista de elementos string
        //COSTRUCTOR: T_abierta= new list<string>[tamano_variable]

    //string *T --> DISPERSION CERRADA DE TAMAÑO VARIABLE
        //Cada posicion de la tabla apunta a un elemento
        //CONSTRUCTOR: T_cerrada = new string[tamano_variable];
    static const unsigned int TAMANO_TABLA=150000;
    list<string> T[TAMANO_TABLA]; //DISPERSION ABIERTA TAMANO FIJO
    int nElem; //Numero elementos introducidos en la tabla

public:

    TablaHash ();
    ~TablaHash();
    void insertar (string palabra);
    bool consultar (string palabra);
    void vaciar (void);
    //void reestructurar();
    int numElem(void) {return nElem;}

};
#endif TABLAHASH_H
