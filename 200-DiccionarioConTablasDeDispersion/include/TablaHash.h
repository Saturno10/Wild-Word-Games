#ifndef TABLAHASH_H
#define TABLAHASH_H
#include <string>
#include <iostream>
using namespace std;
class TablaHash{
private:
    
    string *T;
    int B = 5;
    int nElem;

public:
    TablaHash ();
    ~TablaHash();
    void insertar (string palabra);
    bool consultar (string palabra);
    void vaciar (void);
    void reestructurar();
    int numElem(void) {return nElem;}
};


#endif TABLAHASH_H
