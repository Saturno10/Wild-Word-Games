#include "../include/TablaHash.h"



//TABLA HASH DE DISPERSIÓN ABIERTA Y DE TAMAÑO FIJO
// Función para calcular el MCD (Máximo Común Divisor) de dos números NO USADO POR SER TAMAÑO FIJO, REEMPLAZADO POR CONSTANTE)
/*int calcularMCD(int a, int b) { //lO DEJO POR SI CAMBIAMOS EL TAMAÑO A MANO
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}*/

// Función para encontrar el coprimo de un número dado (NO USADO POR SER TAMAÑO FIJO, REEMPLAZADO POR CONSTANTE)
/*int encontrarCoprimo(int numero) {
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
}*/

unsigned int funcionDispersion(string& clave) {
    unsigned int hash = 0;
    //unsigned int coprimo = encontrarCoprimo(TAMANO); Usado cuando había tamaño variable
    for (unsigned long int i = 0; i < clave.size(); i++) {

        hash = hash * COPRIMO_TAMANO + clave[i];

    }
    return hash % TAMANO;
}





TablaHash::TablaHash() {nElem = 0;}



TablaHash::~TablaHash() = default;


//Inserta un elemento en su cubeta correspondiente si no es encontrado
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

//Consulta si un elemento está en su cubeta (lista ordenada)
bool TablaHash::consultar (string palabra){
    int indice = funcionDispersion(palabra);
    list<string>::iterator it = T[indice].begin();
    while (it!=T[indice].end() && *it!=palabra){
        it++;
    }
    if (it == T[indice].end()|| *it!=palabra) return false;
    return true;

}

//Limpia todas las listas de la tabla y resetea su contador
void TablaHash::vaciar (){
    for (auto & i : this->T) {
        i.clear();
    }
    nElem = 0;

}
