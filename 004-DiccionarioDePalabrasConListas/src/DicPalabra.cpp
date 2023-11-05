#include "../include/DicPalabra.h"



DicPalabras::DicPalabras()
{
    list<string> lista; //Almacena las palabras del diccionario
    contador = 0;
}

DicPalabras::~DicPalabras()
{
    //dtor
}

void DicPalabras::vaciar(){
    //Eliminará todas las palabras del diccionario,
    //y se aplica con el comando <vaciar>

    this->contador=0;
    this->lista.clear();



}

void DicPalabras::insertar(string palabra) {
    //Se insertará la palabra de forma ordenada en la lista (conjunto)(si no existe ya).
    // El orden será el de la comparación entre string de C++. Las palabras
    //insertadas deben estar normalizadas. Se usará dentro del comando <insertar>.

    //N palabras que aparecen dentro del comando (aunque esten repetidas)
    //M palabras palabras en el diccionario (No repetidas)

    this->lista.push_back(palabra);

    this->contador++;


}

bool DicPalabras::buscar(string palabra) {
    //Busca una palabra dentro del diccionario, indicando si está o no.
    //La palabra debe estar normalizada. Se usa en el comando <buscar>.
    for (list<string>::iterator it = lista.begin(); it != lista.end(); ++it ){

        if (*it == palabra) {

            return true;
        }
    }

    return false;
}
