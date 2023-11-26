//
// Created by maria on 26/11/23.
//

#include "ArbolTrie.h"

 ArbolTrie::ArbolTrie(): raiz(new NodoTrie()), nElem(0) {
    //Inicializar si es necesario
}

ArbolTrie::~ArbolTrie() {
    delete raiz;
}



void ArbolTrie:: insertar (string palabra){
    NodoTrie* nodoActual = raiz;

    for(char c: palabra){
        NodoTrie* siguenteNodo = nodoActual->consulta(c);

        if(siguenteNodo == nullptr){
            nodoActual->inserta(c);
            siguenteNodo=nodoActual->consulta(c);
        }

        nodoActual=siguenteNodo;
    }
    //Ultimo nodo final de palabra
    nodoActual->PonMarca();
    nElem++;
}
bool ArbolTrie:: consultar (string palabra){


    NodoTrie* nodoActual = raiz;

    for (char c : palabra) {
        NodoTrie* siguienteNodo = nodoActual->consulta(c);
        if (siguienteNodo == nullptr) {
            return false;  // La palabra no está en el árbol
        }

        nodoActual = siguienteNodo;
    }

    // Verificar si el último nodo tiene marca, lo que indica que la palabra está en el árbol
    return nodoActual->HayMarca();

}
void ArbolTrie:: juego2 (string param){

    //TODO SIN IMPLEMENTAR EL JUEGO

}
void ArbolTrie::  vaciar () {
    delete raiz;
    raiz = new NodoTrie();
    nElem = 0;

}