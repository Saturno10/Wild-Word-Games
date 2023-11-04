#ifndef DICPALABRAS_H
#define DICPALABRAS_H

#include <iostream>
#include <list>
#include <string>

using namespace std;

class DicPalabras {
public:
    DicPalabras(); // Constructor por defecto
    virtual ~DicPalabras(); // Destructor virtual

    string convertirPalabraMayuscula(string palabra);

    void vaciar();
    void insertar(string palabra);
    bool buscar(string palabra);
    int GetNumElem() { return contador;
    void devolverTamano();

protected:

private: // Solo accesible por la clase
    list<string> lista; // Almacena las palabras del diccionario
    int contador; // Es el contador M del método void insertar()

    // Puedes declarar el iterador localmente donde lo necesitas
    // list<string>::iterator it;



};

#endif // DICPALABRAS_H
