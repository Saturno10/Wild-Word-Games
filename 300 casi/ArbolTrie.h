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
    void juego2 (string param);
    void vaciar (void);
    void borrar();


     //Publico porque lo voy a utilizar en la clase diccionario (clases exteriores)
};



#endif //INC_200_DICCIONARIOCONTABLASDEDISPERSION_ARBOLTRIE_H