#include <iostream>
#include <string>
#include "DicPalabras.h"
using namespace std;

int contador = 0;

string convertirPalabraMayuscula(string palabra) {
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

void buscar (){
    string palabra;
    cin >> palabra;
    palabra=convertirPalabraMayuscula(palabra);

    cout << "Buscando: "<< palabra << " -> No encontrada"<<endl;
}

void partidas(){
    string palabra, palabras;
    while(cin >> palabra && convertirPalabraMayuscula(palabra) != "</PARTIDAS>"){
        palabras += (" " + palabra);
    }
    cout << "Partidas:" << convertirPalabraMayuscula(palabras) << endl << "No implementado" << endl;
}

void alocado(){
    string palabra;
    cin >> palabra;
    palabra=convertirPalabraMayuscula(palabra);
    for (char &c : palabra){
        if(c == ' '){
            c = '-';}
    }
    cout << "Alocado: "<< palabra << endl;
    cout << "No implementado" << endl;
}

void cesar(){
    string palabra;
    cin >> palabra;
    palabra=convertirPalabraMayuscula(palabra);
    cout << "César: "<< palabra << endl;
    cout << "No implementado" << endl;
}

void juanagra(){
    string palabra;
    cin >> palabra;

    cout << "Juanagrama: " << convertirPalabraMayuscula(palabra) << endl;
    cout << "No implementado" << endl;
}

void saco(){
    string palabra1;
    string palabra2;
    cin >> palabra1 >> palabra2;

    cout << "Saco: "<< convertirPalabraMayuscula(palabra1) << " " << convertirPalabraMayuscula(palabra2)<< endl;
    cout << "No implementado" << endl;
}

void consome(){
    string palabra;
    cin >> palabra;
    palabra = convertirPalabraMayuscula(palabra);

    cout << "Consomé: "<< palabra << endl;
    cout << "No implementado" << endl;
}

void alargapalabras(){
    string palabra;
    cin >> palabra;
    palabra = convertirPalabraMayuscula(palabra);

    cout << "Alarga: "<< palabra << endl;
    cout << "No implementado" << endl;
}



void InterpreteComandos (string comando){
    if(convertirPalabraMayuscula(comando)=="<INSERTAR>"){
        DicPalabras palabra;
        insertar(palabra);
    }
    else if(convertirPalabraMayuscula(comando)=="<VACIAR>"){
        vaciar();
    }
    else if(convertirPalabraMayuscula(comando)=="<BUSCAR>"){
        buscar();
    }
    else if(convertirPalabraMayuscula(comando)=="<PARTIDAS>"){
        partidas();
    }
    else if(convertirPalabraMayuscula(comando)=="<ALOCADO>"){
        alocado();
    }
    else if(convertirPalabraMayuscula(comando)=="<CESAR>"){
        cesar();
    }
    else if(convertirPalabraMayuscula(comando)=="<JUANAGRA>"){
        juanagra();
    }
    else if(convertirPalabraMayuscula(comando)=="<SACO>"){
        saco();
    }
    else if(convertirPalabraMayuscula(comando)=="<CONSOME>"){
        consome();
    }
    else if(convertirPalabraMayuscula(comando)=="<ALARGA>"){
        alargapalabras();
    }
}


int main(){
    string palabra;

    while(cin >> palabra && convertirPalabraMayuscula(palabra) != "<EXIT>"){
        InterpreteComandos(palabra);
    }
    if (convertirPalabraMayuscula(palabra) == "<EXIT>"){
        cout << "Saliendo..." << endl;
    }

    return 0;
}
