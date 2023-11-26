//
// Created by maria on 26/11/23.
//

#include "../include/NodoTrie.h"

NodoTrie::NodoTrie() : car('/0'), sig(nullptr), ptr(nullptr){

    //Inicializar si quisieramos
}

NodoTrie::~NodoTrie() {
    delete sig; //Destruimos hijo izquierdo
    delete ptr; //Destruimos hermano derecho
}

NodoTrie *NodoTrie::consulta(char letra) {
    NodoTrie* tmp=sig;
    while(tmp != nullptr & tmp->car < letra ){
        tmp=tmp->sig;
    }

    if(tmp != nullptr and tmp->car == letra){
        return tmp->ptr;
    }
    else{
    return nullptr;}
}



void NodoTrie::inserta(char letra) {
        NodoTrie* tmp = this;

        while (tmp->sig != nullptr && tmp->sig->car < letra) {
            tmp = tmp->sig;
        }

    if (tmp->sig == nullptr || tmp->sig->car != letra)
        tmp->sig = new NodoTrie();

}




void NodoTrie::PonMarca() {
    car = '$';
}


void NodoTrie::QuitaMarca() {
    car = ' ';
}

 bool NodoTrie::HayMarca()  {
    return car == '$';
}

void NodoTrie::tomaNuevo(char letra) {
    //Crea un nodo trie con el valor del parametro asociado a la funcion
    //Pone el nuevo nodo como el hijo izquierdo del actual

    NodoTrie* nuevoNodo= new NodoTrie();

    nuevoNodo->sig= this->sig;
    this->sig=nuevoNodo;



}


