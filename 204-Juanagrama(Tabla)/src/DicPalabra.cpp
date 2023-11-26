#include "../include/DicPalabra.h"


//Constructor del diccionario
DicPalabras::DicPalabras()
{
    TablaHash tabla;
}
//Destructor (no necesario al ser un objeto estático)
DicPalabras::~DicPalabras()
{
    //dtor
}
//Elimina las palabras y resetea el contador
void DicPalabras::vaciar(){

    tabla.vaciar();
}
//Añade una palabra, esta tiene que estar normalizada.
void DicPalabras::insertar(string palabra) {
    tabla.insertar(palabra);

}
//Orden de búsqueda de palabras en la tabla del diccionario, la palabra se da normalizada
bool DicPalabras::buscar(string palabra) {

    return tabla.consultar(palabra);

}

string DicPalabras::juanagra(string palabra) {
    return tabla.juanagra(palabra);
}