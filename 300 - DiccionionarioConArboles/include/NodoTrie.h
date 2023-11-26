//
// Created by maria on 26/11/23.
//



#ifndef INC_200_DICCIONARIOCONTABLASDEDISPERSION_NODOTRIE_H
#define INC_200_DICCIONARIOCONTABLASDEDISPERSION_NODOTRIE_H

#include <string>
#include <iostream>
using namespace std;

class NodoTrie {
    private:

        char car;
        //Representacion hijo izquierdo-hermano derecho
        NodoTrie *sig, *ptr; //Un nodo apunta al hijo izquierdo del caracter y otro a su hermano (con los caracteres que le siguen)
        //NodoTrie* hijos[ALFABETO_TAMANO]; para arrays

    public:
        NodoTrie();
        ~NodoTrie ();
        NodoTrie* consulta (char letra);
        void inserta(char l);
        void tomaNuevo (char letra);

        //Marca fin
        void PonMarca();
        void QuitaMarca();
        bool HayMarca();


};




#endif //INC_200_DICCIONARIOCONTABLASDEDISPERSION_NODOTRIE_H
