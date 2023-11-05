#include "DicPalabra.h"


//Constructor del diccionario
DicPalabras::DicPalabras()
{
    list<string> lista; //Almacena las palabras del diccionario
    contador = 0;
}
//Destructor (no necesario al ser un objeto estático)
DicPalabras::~DicPalabras()
{
    //dtor
}
//Elimina las palabras y resetea el contador
void DicPalabras::vaciar(){
    //Eliminará todas las palabras del diccionario,
    //y se aplica con el comando <vaciar>

    this->contador=0;
    this->lista.clear();



}
//Añade una palabra, esta tiene que estar normalizada y ya en el intérprete nos aseguramos de que no está.
void DicPalabras::insertar(string palabra) {

    this->lista.push_back(palabra);

    this->contador++;


}
//Orden de búsqueda de palabras en la lista de un diccionario, la palabra se da normalizada
bool DicPalabras::buscar(string palabra) {

    for (list<string>::iterator it = this->lista.begin(); it != this->lista.end(); ++it ){

        if (*it == palabra) {

            return true;
        }
    }

    return false;
}
