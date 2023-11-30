#include "Utilidades.h"

using namespace std;
//Todas las funciones para normalizar y trabajar con el diccionario

/*Dada una palabra, la devuelve normalizada para poder trabajarla*/
//Nivel de uso: mucho -> eficiencia máxima requerida
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
//Dado un diccionario le inserta las palabras de la entrada que no tenga ya y lo devuelve modificado
void insertar(DicPalabras &d){

    int npalabras=0;
    string palabra;
    while (cin >> palabra && convertirPalabraMayuscula(palabra) != "</INSERTAR>"){
        d.insertar(convertirPalabraMayuscula(palabra));
        npalabras++;
    }

    cout << "Insertando: " << npalabras << " palabras" << endl;
    cout << "Total diccionario: " << d.GetNumElem() << " palabras" << endl;

}
//Imprime si una palabra se encuentra o no en el diccionario dado
void buscar(DicPalabras &d){
    string palabra;
    cin >> palabra;
    string palabra_norm = convertirPalabraMayuscula(palabra);
    if (d.buscar(palabra_norm)){
        cout << "Buscando: " << palabra_norm << " -> Encontrada" << endl;
    }else{
        cout << "Buscando: " << palabra_norm << " -> No encontrada" << endl;
    }

}
//Dado un diccionario lo devuelve vaciado
void vaciar(DicPalabras &d){
    d.vaciar();
    cout << "Vaciando"<< endl;
    cout << "Total diccionario: "<< d.GetNumElem() << " palabras"<<endl;

}
//Hasta el siguiente comentario son funciones NO IMPLEMENTADAS
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
//NUCLEO y BASE de Wild Word Games --> contiene el diccionario y es el nexo de todos los comandos
//Nivel de uso: mucho -> eficiencia máxima requerida
void InterpreteComandos (DicPalabras &d){
    string palabra;

    while (cin >> palabra && convertirPalabraMayuscula(palabra) != "<EXIT>"){
        string comando_convertido= convertirPalabraMayuscula(palabra);
        if(comando_convertido=="<INSERTAR>"){
            insertar(d);
        }
        else if(comando_convertido=="<VACIAR>"){
            vaciar(d);
        }
        else if(comando_convertido=="<BUSCAR>"){
            buscar(d);
        }
        else if(comando_convertido=="<PARTIDAS>"){
            partidas();
        }
        else if(comando_convertido=="<ALOCADO>"){
            alocado();
        }
        else if(comando_convertido=="<CESAR>"){
            cesar();
        }
        else if(comando_convertido=="<JUANAGRA>"){
            juanagra();
        }
        else if(comando_convertido=="<SACO>"){
            saco();
        }
        else if(comando_convertido=="<CONSOME>"){
            consome();
        }
        else if(comando_convertido=="<ALARGA>"){
            alargapalabras();
        }
    }
    if (convertirPalabraMayuscula(palabra) == "<EXIT>"){
        cout << "Saliendo..." << endl;
    }

    d.vaciar();



}
