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
    //Eliminará todas las palabras del diccionario,
    //y se aplica con el comando <vaciar>
    tabla.vaciar();

    /*this->contador=0;
    this->lista.clear();*/



}
//Añade una palabra, esta tiene que estar normalizada y ya en el intérprete nos aseguramos de que no está.
void DicPalabras::insertar(string palabra) {
    tabla.insertar(palabra);
    /*list<string>::iterator it= lista.begin();
    while (it!=lista.end() && *it<palabra)
        it++;
    if (it==lista.end() || *it!=palabra) {
        lista.insert(it, palabra);
        contador++;
    }*/


}
//Orden de búsqueda de palabras en la lista de un diccionario, la palabra se da normalizada
bool DicPalabras::buscar(string palabra) {

    return tabla.consultar(palabra);


   /* list<string>::iterator  it = lista.begin();
    while (it!=this->lista.end() && *it < palabra) it++;
    if(it==lista.end() || *it!=palabra) return false;
    return true;*/
}