#include "ArbolTrie.h"

ArbolTrie::ArbolTrie(): raiz(new NodoTrie()) {
    //Inicializar si es necesario
}

ArbolTrie::~ArbolTrie() {
    delete raiz;
}



void ArbolTrie::insertar(string palabra){
    NodoTrie* nodoActual = raiz;
    for (long unsigned int i = 0; i < palabra.size(); i++){
        string caracterProcesado;
         unsigned int letra = palabra[i];
        //Se intentó hacer con unsigned ints como en el normalizador de palabras, pero falla con las ñ por alguna razón
        caracterProcesado += letra;
        if (letra == 0xFFFFFFC3){
            unsigned int siguiente = palabra[++i];
            caracterProcesado += siguiente;
        }
        if(nodoActual->consultar(caracterProcesado) == nullptr) nodoActual->insertar(caracterProcesado);

        nodoActual = nodoActual -> consultar(caracterProcesado);

        caracterProcesado.clear();
    }
    nodoActual->car = "$";
}

bool ArbolTrie::consultar(string palabra){
    NodoTrie* nodoActual = raiz;
    string palabraBuscar = "";
    for(long unsigned int i = 0; i < palabra.size(); i++){
        string caracterProcesado;
        unsigned int letra = palabra[i];
        caracterProcesado += letra;
        if (letra ==  0xFFFFFFC3){
            unsigned int siguiente = palabra[i+1];
            caracterProcesado += siguiente;
        }

        if (nodoActual->consultar(caracterProcesado) != nullptr){
            nodoActual = nodoActual->consultar(caracterProcesado);
            palabraBuscar += caracterProcesado;
        }
        caracterProcesado.clear();
    }
    if (nodoActual->car=="$" && palabraBuscar.compare(palabra) == 0){
        return true;
    }
    return false;
}
void ArbolTrie:: juego2 (string param){

    //TODO SIN IMPLEMENTAR EL JUEGO

}
void ArbolTrie::  vaciar () {
    delete raiz;
    raiz = new NodoTrie();


}

void ArbolTrie::borrar(){
    delete raiz;
    raiz = nullptr;
}
