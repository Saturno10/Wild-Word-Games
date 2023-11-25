//
// Created by alvaro-linux on 11/11/23.
//

#include "../include/TablaHash.h"

unsigned long long int funcionDispersion(string palabra){
    unsigned long long int hash=0;
    for (unsigned int i : palabra) {
        hash+=i*65537/104729;
    }

    return hash;
}

TablaHash::TablaHash() = default; //T(new string*[10]()),B(10),nElem(0){}



TablaHash::~TablaHash(){

}

void TablaHash::insertar (string palabra){
    int indice = funcionDispersion(palabra);
    list<string>::iterator it = T[indice].begin();
    while (it != T[indice].end() && *it<palabra){
        it++;
    }
    if (it==T[indice].end() || *it != palabra){
        nElem++;
        T[indice].insert(it,palabra);
    }
}
bool TablaHash::consultar (string palabra){
    int indice = funcionDispersion(palabra);
    list<string>::iterator it = T[indice].begin();
    while (it!=T[indice].end() && *it!=palabra){
        it++;
    }
    if (it == T[indice].end()|| *it!=palabra) return false;
    return true;

}
void TablaHash::vaciar (){
    for (unsigned int i = 0; i < TAMANO; i++) {
        this->T[i].clear();
    }
    nElem = 0;

}

/*void TablaHash::reestructurar() {
    int nuevoIndice = B * 2;
    string *nuevaT = new string[nuevoIndice]();
    for (int i = 0; i < B; ++i) {
        if (!T[i].empty()) {
            int indice = funcionDispersion(T[i]) % (nuevoIndice);
            while (!nuevaT[indice].empty()) {
                indice = (indice + 1) % (nuevoIndice);
            }
            nuevaT[indice] = T[i];
        }
    }
    delete[] this->T;
    this->T = nuevaT;
    this->B = nuevoIndice;
}*/
