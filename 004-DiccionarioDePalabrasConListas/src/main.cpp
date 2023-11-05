#include <iostream>
#include <string>
#include "../include/DicPalabra.h"
#include "../include/Utilidades.h"
using namespace std;


DicPalabras diccionario;

int main(){
    string palabra;

    while(cin >> palabra && convertirPalabraMayuscula(palabra) != "<EXIT>"){
        InterpreteComandos(palabra, diccionario);
    }
    if (convertirPalabraMayuscula(palabra) == "<EXIT>"){
        cout << "Saliendo..." << endl;
    }

    return 0;
}
