#ifndef INC_200_DICCIONARIOCONTABLASDEDISPERSION_NODOTRIE_H
#define INC_200_DICCIONARIOCONTABLASDEDISPERSION_NODOTRIE_H

#include <string>
#include <iostream>
using namespace std;

class NodoTrie {
friend class ArbolTrie;

private:

    string car;
    //Representacion hijo izquierdo-hermano derecho
    NodoTrie *sig, *ptr; //Un nodo apunta al hijo izquierdo del caracter y otro a su hermano (con los caracteres que le siguen)
    //NodoTrie* hijos[ALFABETO_TAMANO]; para arrays

public:
    NodoTrie();
    ~NodoTrie ();
    NodoTrie* consultar (string letra);
    void insertar(string l);


};




#endif //INC_200_DICCIONARIOCONTABLASDEDISPERSION_NODOTRIE_H