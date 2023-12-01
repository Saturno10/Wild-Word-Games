#ifndef INC_200_DICCIONARIOCONTABLASDEDISPERSION_ARBOLTRIE_H
#define INC_200_DICCIONARIOCONTABLASDEDISPERSION_ARBOLTRIE_H
#include "NodoTrie.h"
#include <iostream>
#include <string>
using namespace std;

class ArbolTrie {
private:

    NodoTrie *raiz;
public:
    ArbolTrie ();
    ~ArbolTrie ();
    void insertar (string palabra);
    bool consultar (string palabra);
    string alargapalabras (string palabra);
    void vaciar ();
    void borrar();
    void palabraMayor(NodoTrie* nodoActual, const string& basePalabra, string& alargada);


    
};



#endif //INC_200_DICCIONARIOCONTABLASDEDISPERSION_ARBOLTRIE_H
