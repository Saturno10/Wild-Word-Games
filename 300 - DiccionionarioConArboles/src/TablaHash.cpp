//
// Created by alvaro-linux on 11/11/23.
//

#include "../include/TablaHash.h"

const unsigned int TAMANO_TABLA=150000;


//------------------------NUEVO MARIA-----------------------
// Función para calcular el MCD (Máximo Común Divisor) de dos números
int calcularMCD(int a, int b) { //lO DEJO POR SI CAMBIAMOS EL TAMAÑO A MANO 
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Función para encontrar el coprimo de un número dado
int encontrarCoprimo(int numero) {
    if (numero % 2 == 0) {
        // Si es par, devolvemos 1 para evitar problemas con el MCD
        return 1;
    }

    for (int coprimo = 3; coprimo < numero; coprimo += 2) {
        if (calcularMCD(numero, coprimo) == 1) {
            return coprimo;
        }
    }

    return 1; // En caso de no encontrar otro coprimo
}

unsigned int funcionDispersion(string& clave) {
    unsigned int hash = 0;
    for (int i = 0; i < clave.size(); i++) {
        unsigned int coprimo = encontrarCoprimo(TAMANO_TABLA);
        hash = hash * coprimo + clave[i];

    }
    return hash % TAMANO_TABLA;
}




TablaHash::TablaHash() : /*list<string>T[TAMANO_TABLA], (Se inicializa en la cabecera)*/ nElem(0){}



TablaHash::~TablaHash(){
   // delete[] T;
   //NO ES NECESARIO
        //No usamos memoria dinamica (porque es tabla de tamaño fijo)
        //La memoria de contenedores STL borra la memoria estatica.
}




/*--------------------------ANTIGUO ALVARO, NO BORRADO-----------------

unsigned long long int funcionDispersion(string palabra){
    unsigned long long int hash=0;
    for (unsigned int i : palabra) {
        hash+=i*65537/104729;
    }

    return hash;
}

TablaHash::TablaHash() = default; //T(new string*[10]()),B(10),nElem(0){}



TablaHash::~TablaHash(){

}--------------------------------------------------------------------*/

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
    for (unsigned int i = 0; i < TAMANO_TABLA; i++) {
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
