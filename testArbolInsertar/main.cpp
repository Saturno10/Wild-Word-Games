#include <iostream>
#include <string>

using namespace std;


class NodoTrie {
    friend class ArbolTrie;
private:

    char car;
    //Representacion hijo izquierdo-hermano derecho
    NodoTrie *sig, *ptr; //Un nodo apunta al hijo izquierdo del caracter y otro a su hermano (con los caracteres que le siguen)
    //NodoTrie* hijos[ALFABETO_TAMANO]; para arrays

public:
    NodoTrie();
    ~NodoTrie ();



};

NodoTrie::NodoTrie() : car(NULL), sig(nullptr), ptr(nullptr){

    //Inicializar si quisieramos
}

NodoTrie::~NodoTrie() {
    delete sig; //Destruimos hijo izquierdo
    delete ptr; //Destruimos hermano derecho
}




class ArbolTrie {
private:
    NodoTrie *raiz;
    int nElem;
public:
    ArbolTrie ();
    ~ArbolTrie ();
    void insertar (string palabra);



};

ArbolTrie::ArbolTrie(): raiz(new NodoTrie()), nElem(0) {
    //Inicializar si es necesario
}

ArbolTrie::~ArbolTrie() {
    delete raiz;
}
void ArbolTrie::insertar(string palabra) {
    NodoTrie* nodoActual = raiz;
    //Para cada letra...
    for (char c : palabra) {
        NodoTrie *nodoAnterior = nullptr;
        //Buscamos el caracter para ver si hay que insertarlo o no
        while (nodoActual->sig != nullptr && nodoActual->sig->car < c) {
            nodoAnterior = nodoActual;
            nodoActual = nodoActual->sig;
        }
        if (nodoActual->car != c) {
            //Si hay un nodo vacío, lo usa, sino, lo crea
            if (nodoActual->car == '\0') {
                nodoActual->car = c;
                nodoActual->ptr = new NodoTrie();
                nodoActual = nodoActual->ptr;
            } else {
                NodoTrie* temp = nodoActual->sig;
                nodoActual->sig = new NodoTrie();
                nodoActual->sig->car = c;
                nodoActual->sig->ptr = new NodoTrie();
                nodoActual->sig->sig = temp;
                nodoActual = nodoActual->sig->ptr;
            }


        }else nodoActual = nodoActual->ptr;
    }
    // Agregar el nodo de fin de palabra ('$'), mismo funcionamiento que el bucle anterior pero con dolar
    if (nodoActual== nullptr){
        nodoActual=new NodoTrie();
        nodoActual->car='$';
    }else{
        NodoTrie* nodoAnterior = nullptr;
        while(nodoActual->sig!= nullptr && nodoActual->sig->car < '$'){
            nodoAnterior=nodoActual;
            nodoActual=nodoActual->sig;
        }
        if (nodoActual->car!='$'){
            if (nodoActual->car == '\0') {
                nodoActual->car = '$';

            } else {
                nodoAnterior->sig = new NodoTrie();
                nodoAnterior->sig->sig = nodoActual;
                nodoAnterior->sig->car = '$';

            }
        }
    }


}


int main() {
    ArbolTrie* arbol = new ArbolTrie();
    arbol->insertar("aa");
    arbol->insertar("c");
    arbol->insertar("b");
    arbol->insertar("ab");
    delete arbol;
    return 0;
}