#include "DicPalabras.h"




DicPalabras::DicPalabras()
{
    contador = 0;
}

DicPalabras::~DicPalabras()
{
    //dtor
}

void DicPalabras::vaciar(){
    //Eliminará todas las palabras del diccionario,
    //y se aplica con el comando <vaciar>
    lista.clear();
    contador = 0;
    cout << "Vaciando"<< endl;
    cout << "Total diccionario: "<< contador << " palabras"<<endl;

}

void DicPalabras::insertar(string palabra){
    //Se insertará la palabra de forma ordenada en la lista (conjunto)(si no existe ya).
    // El orden será el de la comparación entre string de C++. Las palabras
    //insertadas deben estar normalizadas. Se usará dentro del comando <insertar>.

    //N palabras que aparecen dentro del comando (aunque esten repetidas)
    //M palabras palabras en el diccionario (No repetidas)

    string palabra;
    int contadorM=0;
    while(cin >> palabra && convertirPalabraMayuscula(palabra) != "</INSERTAR>"){
        string palabraNormalizada = convertirPalabraMayuscula(palabra);

        /* PRIMER MODELO DE ACCESO SECUENCIAL  (Primera idea)

        bool palabraRepetida = false;
         for(auto it=lista.begin(); it != lista.end(); it++)){
             if (*it == palabraNormalizada){
              palabraRepetida = true;
              break;
             }
         }
         if(!palabraRepetida){
            lista.push_back(palabraNormalizada);
            contadorM++;
          }*/

        it = lista.begin();
        while(it != lista.end() && *it <palabraNormalizada)
            it++;

        if(it == lista.end() || *it != palabra)
            lista.insert(it, cadena);





    }
    contador+=contadorM;
    cout << "Insertando: " << contadorM <<" palabras" << endl;
    cout << "Total diccionario: " << contador <<" palabras" << endl;
    //Usar metodo devolver tamaño
}

void DicPalabras::devolverTamaño(){
    //Devolverá el tamaño actual del diccionario (el número de palabras
    //que contiene). Se usa al acabar el comando <insertar>.

}

bool DicPalabras:: consultar(string palabra){
    //Busca una palabra dentro del diccionario, indicando si está o no.
    //La palabra debe estar normalizada. Se usa en el comando <buscar>.

    cout << "Buscando: " << palabra <<"-> Encontrada" << endl;
    cout << "Buscando: " << palabra <<"-> No encontrada" << endl;

}