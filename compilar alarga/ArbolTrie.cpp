#include "ArbolTrie.h"

ArbolTrie::ArbolTrie(): raiz(new NodoTrie()) {
    //Inicializar si es necesario
}

ArbolTrie::~ArbolTrie() {
    delete raiz;
}



void ArbolTrie::insertar(string palabra){
    NodoTrie* nodoActual = raiz;
    //Recorremos el árbol tratando los caracteres de dos bytes
    for (long unsigned int i = 0; i < palabra.size(); i++){
        string caracterProcesado;
        unsigned int letra = palabra[i];

        caracterProcesado += letra;
        if (letra == 0xFFFFFFC3){
            unsigned int siguiente = palabra[++i];
            caracterProcesado += siguiente;
        }
        //Si no encontramos el caracter, lo insertamos, luego simplemente vamos avanzando y añadimos al final la marca de fin de palabra
        if(nodoActual->consultar(caracterProcesado) == nullptr) nodoActual->insertar(caracterProcesado);

        nodoActual = nodoActual -> consultar(caracterProcesado);

        caracterProcesado.clear();
    }
    nodoActual->car = "$";
}
//Dada una palabra, vemos si está
bool ArbolTrie::consultar(string palabra){
    //Partimos desde la raiz
    NodoTrie* nodoActual = raiz;
    string palabraBuscar = "";
    //Recorremos el árbol viendo si están los caracteres de la palabra (tratando las palabras con primer byte C3)
    //Vamos añadiendo los caracteres que encajan a una string que luego compararemos
    for(long unsigned int i = 0; i < palabra.size(); i++){
        string caracterProcesado;
        unsigned int letra = palabra[i];
        caracterProcesado += letra;
        if (letra ==  0xFFFFFFC3){
            unsigned int siguiente = palabra[i+1];
            caracterProcesado += siguiente;
        }
	//Si se encuentra el caracter, continuamos desde él
        if (nodoActual->consultar(caracterProcesado) != nullptr){
            nodoActual = nodoActual->consultar(caracterProcesado);
            palabraBuscar += caracterProcesado;
        }
        caracterProcesado = "";
    }
    //Si las palabras son iguales y hay marca de fin, está la palabra
    if (nodoActual->car=="$" && palabraBuscar.compare(palabra) == 0){
        return true;
    }
    //Cualquier otro caso implica que la palabra no está
    return false;
}

//Una vez que se está al final del prefijo inicial, se busca desde éste la palabra más larga
//Basado en algoritmo Deep First Search (DFS)
void ArbolTrie::palabraMayor(NodoTrie* nodoActual, const string& basePalabra, string& alargada){
    //Si no queda más palabra, no escribir más
    if (nodoActual == nullptr) {
        return;
    }
    //Contamos longitud de la palabra base (con la que nos desplazamos por el árbol) y la alargada (la que devolvemos)
    //Intenté usar enteros sin signo como con el resto de tratamientos de caracteres, pero daba error en el tratamiento de los caracteres
    //del castellano que no están en ascii
    int longitudActual = 0;
    for (unsigned int i = 0; i < basePalabra.size(); i++) {
        long int letra = basePalabra[i];
        if (letra == -61) {
            longitudActual++;
            continue;
        }else if (letra < 0) continue;
        longitudActual++;
    }

    int longitudLarga = 0;
    for (unsigned int i = 0; i < alargada.size(); i++) {
        long int letra = alargada[i];
        if (letra == -61) {
            longitudLarga++;
            continue;
        } else if (letra <0) continue;
        longitudLarga++;
    }

    //Si la base es más grande que la palabra más guarda que tenemos guardada en este momento, hacemos que la nueva alargada sea esa
    if (longitudActual > longitudLarga ||(longitudActual == longitudLarga && basePalabra.compare(alargada) < 0)) {
        alargada = basePalabra;
    }
    //Mientras quede árbol, lo recorremos recursivamente el árbol para ampliar
    NodoTrie* tmp = nodoActual;
    while (tmp != nullptr) {
        palabraMayor(tmp->ptr, basePalabra + tmp->car, alargada);
        tmp = tmp->sig;
    }
}
//Recorre el árbol hasta terminar de recorrer todo el prefijo y busca con una función externa la palabra mayor que luego devuelve
string ArbolTrie::alargapalabras(string prefijo){
    NodoTrie* nodoActual = raiz;
    bool saltar = false;
    string basePalabra = "";
    //Recorremos el árbol en busca del prefijo.
    //Tenemos que tratar los caracteres como la ñ para que no cuenten como dos, si encontramos su byte de inicio, sumamos el siguiente    byte a la cadena
    //para que siga siendo el mismo caracter, pero nos saltamos la iteración del segundo (variable saltar en control de eso)
    for (unsigned int i = 0; i < prefijo.size(); i++) {
        if (saltar){
            saltar = false;
            continue;
        }
        string caracterBuscado = "";
        unsigned int letra = prefijo[i];
        caracterBuscado += letra;
        basePalabra += letra;
        if (letra == 0xFFFFFFC3) {
            unsigned int siguiente = prefijo[i+1];
            caracterBuscado += siguiente;
            saltar = true;
            basePalabra += siguiente;
        }
       
	//Si encontramos el caracter del prefijo, avanzamos y continuamos
        if (nodoActual->consultar(caracterBuscado) != nullptr) {
            
            nodoActual = nodoActual->consultar(caracterBuscado);
        } else {
        //Si en algún momento no lo encontramos, no habrá directamente una palabra más larga, devolvemos una cadena vacía    
            return "";
        }
        
    }
    //Si llegamos a encontrar el prefijo en el árbol, empezamos a buscar la palabra más larga desde él
    //Recorremos el trie para encontrar la palabra más larga
    string alargada = "";
    palabraMayor(nodoActual, basePalabra, alargada);

    return alargada;


}
//Destruimos y reconstruimos el árbol
void ArbolTrie::vaciar () {
    delete raiz;
    raiz = new NodoTrie();


}
//Destruimos el árbol y ponemos el puntero a nulo (si no, da segmentation fault al terminal la entrada o al ejecutar <exit>)
void ArbolTrie::borrar(){
    delete raiz;
    raiz = nullptr;
}
