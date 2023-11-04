#include "DicPalabras.h"

std::string convertirPalabraMayuscula(string palabra) {
    string palabraNormalizada;

    for (unsigned int i = 0; i < palabra.length(); i++) {
        unsigned int byteCaracter = palabra[i];


        if ((unsigned int) byteCaracter == 0xFFFFFFC3) {
            unsigned int byteAnterior = byteCaracter;
            i++;
            byteCaracter = (unsigned int) palabra[i];


            if (byteCaracter == 0xFFFFFFA1 || byteCaracter == 0xFFFFFF81) {
                palabraNormalizada += 'A';
            } else if (byteCaracter == 0xFFFFFFA9 || byteCaracter == 0xFFFFFF89) {
                palabraNormalizada += 'E';
            } else if (byteCaracter == 0xFFFFFFAD || byteCaracter == 0xFFFFFF8D) {
                palabraNormalizada += 'I';
            } else if (byteCaracter == 0xFFFFFFB3 || byteCaracter == 0xFFFFFF93) {
                palabraNormalizada += 'O';
            } else if (byteCaracter == 0xFFFFFFBA || byteCaracter == 0xFFFFFF9A) {
                palabraNormalizada += 'U';
            } else if (byteCaracter == 0xFFFFFFB1) {
                palabraNormalizada += "Ñ";
            } else if (byteCaracter == 0xFFFFFFBC) {
                palabraNormalizada += "Ü";
            } else{
                palabraNormalizada += (char) byteAnterior;
                palabraNormalizada += (char) byteCaracter;
            }

        }else {
            palabraNormalizada += (char) toupper(palabra[i]);
        }
    }

    return palabraNormalizada;
}




DicPalabras::DicPalabras() //Constructor de diccionario, 0 palabras inicialmente
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
    devolverTamano();

}

void DicPalabras::insertar(string palabra){
    //Se insertará la palabra de forma ordenada en la lista (conjunto)(si no existe ya).
    // El orden será el de la comparación entre string de C++. Las palabras
    //insertadas deben estar normalizadas. Se usará dentro del comando <insertar>.

    //N palabras que aparecen dentro del comando (aunque esten repetidas)
    //M palabras palabras en el diccionario (No repetidas)


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

        auto it
        it = lista.begin();
        while(it != lista.end() && *it <palabraNormalizada)
            it++;

        if(it == lista.end() || *it != palabra)
            lista.insert(it, cadena);





    }
    contador+=contadorM;
    cout << "Insertando: " << contadorM <<" palabras" << endl;
    devolverTamano() //Usar metodo devolver tamaño

}

void DicPalabras::devolverTamano(){
    //Devolverá el tamaño actual del diccionario (el número de palabras
    //que contiene). Se usa al acabar el comando <insertar>.

    auto It=lista.begin();

    while(*It!=lista.end()){
        contador++;
        It++;
    }
 cout << "Total diccionario: " << contador  <<" palabras"


}

bool DicPalabras:: consultar(string palabra){
    //Busca una palabra dentro del diccionario, indicando si está o no.
    //La palabra debe estar normalizada. Se usa en el comando <buscar>.

    cout << "Buscando: " << palabra <<"-> Encontrada" << endl;
    cout << "Buscando: " << palabra <<"-> No encontrada" << endl;

}
