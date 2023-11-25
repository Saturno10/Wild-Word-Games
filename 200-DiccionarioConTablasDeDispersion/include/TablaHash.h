#ifndef TABLAHASH_H
#define TABLAHASH_H
#include <string>
#include <iostream>
#include <list>

using namespace std;
const unsigned int TAMANO = 200000;
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
    //void reestructurar();
    int numElem(void) {return nElem;}

};
#endif TABLAHASH_H