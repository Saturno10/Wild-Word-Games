#ifndef TABLAHASH_H
#define TABLAHASH_H
#include <string>
#include <iostream>
#include <list>

using namespace std;
const unsigned int TAMANO = 150001; //Tamaño primo para aumentar eficiencia y dispersión
const int COPRIMO_TAMANO = 3;
class TablaHash{
private:

    list<string> T[TAMANO];

    int nElem;

public:
    TablaHash ();
    ~TablaHash();
    void insertar (string palabra);
    bool consultar (string palabra);
    void vaciar (void);
    //void reestructurar(); No se usa por ser tamaño fijo
    int numElem(void) {return nElem;}
    string juanagra(string palabra);

};
#endif TABLAHASH_H