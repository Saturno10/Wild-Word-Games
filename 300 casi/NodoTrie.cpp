#include "NodoTrie.h"

NodoTrie::NodoTrie() : car(), sig(nullptr), ptr(nullptr){

    //Inicializar si quisieramos
}

NodoTrie::~NodoTrie() {
    delete sig; //Destruimos hijo izquierdo
    delete ptr; //Destruimos hermano derecho
}

void NodoTrie::insertar(string letra){
    NodoTrie* nodoActual = this;
    while(nodoActual->sig != nullptr && nodoActual->sig->car.compare(letra) < 0) nodoActual = nodoActual->sig;
    if(nodoActual->sig == nullptr || nodoActual->sig->car.compare(letra) != 0){
        NodoTrie* tmp2 = nodoActual->sig;
        nodoActual->sig = new NodoTrie();
        nodoActual->sig->car = letra;
        nodoActual->sig->ptr = new NodoTrie();
        nodoActual->sig->sig = tmp2;
    }
}

NodoTrie* NodoTrie::consultar(string letra){
    NodoTrie* nodoActual = this;
    while (nodoActual->sig != nullptr && nodoActual->car.compare(letra) != 0) nodoActual = nodoActual->sig;

    if(nodoActual!=nullptr && nodoActual->car.compare(letra) == 0) return nodoActual->ptr;
    return nullptr;
}






