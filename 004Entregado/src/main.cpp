#include <iostream>
#include <string>
#include "DicPalabras.h"

using namespace std;

int contador = 0;



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
        Diccionario1.insertar(palabra);
    }
    else if(convertirPalabraMayuscula(comando)=="<VACIAR>"){
        Diccionario1.vaciar();
    }
    else if(convertirPalabraMayuscula(comando)=="<BUSCAR>"){
        Diccionario1.consultar(palabra);
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

    DicPalabras Diccionario1;
    string palabra

    while(cin >> palabra && convertirPalabraMayuscula(palabra) != "<EXIT>"){
        InterpreteComandos(palabra);
    }
    if (convertirPalabraMayuscula(palabra) == "<EXIT>"){
        cout << "Saliendo..." << endl;
    }

    return 0;
}
