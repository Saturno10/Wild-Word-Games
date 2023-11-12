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

TablaHash::TablaHash() : T(new string[10]()),B(10),nElem(0){}



TablaHash::~TablaHash(){
    delete[] T;
}

void TablaHash::insertar (string palabra){
    int indice = funcionDispersion(palabra)%indice;
    while (!T[indice].empty() && T[indice] != "0"){
        if(T[indice] == palabra) return;
        indice = (indice+1)%indice;
    }
    T[indice] = palabra;
    nElem++;
    if(B*0.75 < nElem) this->reestructurar();
}
bool TablaHash::consultar (string palabra){
    int indice = funcionDispersion(palabra)%indice;
    while (!T[indice].empty() && T[indice] != "0"){
        if (T[indice] == palabra) return true;
        indice = (indice+1)%indice;
    }
    return false;

}
void TablaHash::vaciar (){
    delete[] T;
    B = 10;
    nElem = 0;
    T = new string[B]();

}

void TablaHash::reestructurar() {
    int  nuevoIndice=B*2;
    string* nuevaT = new string[nuevoIndice]();
    for (int i = 0; i < B; ++i) {
        if(!T[i].empty()){
            int indice = funcionDispersion(T[i])%(nuevoIndice);
            while (!nuevaT[indice].empty()){
                indice = (indice+1)%(nuevoIndice);
            }
            nuevaT[indice] = T[i];
        }
    }
    delete[] T;
    T = nuevaT;
    B =nuevoIndice;

}