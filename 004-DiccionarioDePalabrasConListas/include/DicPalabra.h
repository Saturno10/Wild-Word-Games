#ifndef DICPALABRAS_H
#define DICPALABRAS_H

#include <iostream>
#include <list>
#include <string>

using namespace std;


class DicPalabras
{
public:
    DicPalabras(); //Constructor por defecto
    virtual ~DicPalabras(); //Destructor virtual
    void vaciar();
    void insertar (string palabra);
    bool buscar (string palabra);
    int GetNumElem (void) {return contador;}

protected:

private: //Solo accesible por la clase
    list<string> lista; //Almacena las palabras del diccionario
    //list <int>::interator it; //Interador lista no hace falta se puede hacer localmente cuando lo necesite
    int contador; //Es el contador M del metodo void insertar()
};

void DicPalabras::vaciar() {
    this->contador=0;
    this->lista.clear();
}


bool DicPalabras::buscar(string palabra) {
    for (string elemento : lista){
        if (palabra == elemento) return true;
    }
    return false;
}
void DicPalabras::insertar(string palabra) {
    if (buscar(palabra)) return;
    lista.push_back(palabra);
    contador++;
}





#endif // DICPALABRAS_H