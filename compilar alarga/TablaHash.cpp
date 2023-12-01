#include "TablaHash.h"
#include <algorithm>
//Usamos algorithm ya que tiene un método para ordenar alfabéticamente una string


//Función de dispersión de la tabla
//MODIFACIONES: Las letras de las palabras ahora se ordenan para que las palabras que son anagramas
//estén siempre en las mismas cubetas
unsigned int funcionDispersion(string& clave) {
    unsigned int hash = 0;
    string claveOrdenada = clave;
    sort(claveOrdenada.begin(),claveOrdenada.end());
    //unsigned int coprimo = encontrarCoprimo(TAMANO); Usado cuando había tamaño variable
    for (unsigned long int i = 0; i < claveOrdenada.size(); i++) {

        hash = hash * COPRIMO_TAMANO + claveOrdenada[i];

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
        nElem+=1;
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
//Si una palabra es un anagrama de otra, al ordenar sus caracteres en orden alfabético deben ser iguales
bool esAnagrama(string p1, string p2){
    sort(p1.begin(),p1.end());
    sort(p2.begin(),p2.end());
    return p1==p2;
}
//Función del juego juanagrama, devuelve el primeres anagrama que se encuentre en la lista (el primero alfabéticamente)
string TablaHash::juanagra(string palabra){
    unsigned int posicion = funcionDispersion(palabra);

    for (string potencialAnagrama : T[posicion]) {

        if (esAnagrama(potencialAnagrama, palabra)) return (" " + potencialAnagrama);

    }
    return "";
}
//Los espacios solo se añaden en caso de encontrar un anagrama