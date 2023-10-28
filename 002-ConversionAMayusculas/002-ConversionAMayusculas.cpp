#include <iostream>
#include <string>

using namespace std;

string convertirPalabraMayuscula(string palabra) {
    string palabraNormalizada;

    for (unsigned int i = 0; i < palabra.length(); i++) {
        //Valores de los bytes del caractér (guardado en C2, explicando todas las Fs en las comparaciones)
        unsigned int byteCaracter = palabra[i];

        //Si es acentuado, se procesarán sus dos bytes distintos
        if ((unsigned int) byteCaracter == 0xFFFFFFC3) {
            unsigned int byteAnterior = byteCaracter;
            i++;
            byteCaracter = (unsigned int) palabra[i];

            //Comparamos el valor del segundo byte para saber qué letra es
            //Hacerlo mediante un switch da error
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
                //Si fuera un caracter de dos bytes que no queremos cambiar simplemente los incorporamos de vuelta
                palabraNormalizada += (char) byteAnterior;
                palabraNormalizada += (char) byteCaracter;
            }

        //Si no es un caracter acentuado, simplemente lo ponemos en mayúscula
        }else {
            palabraNormalizada += (char) toupper(palabra[i]);
        }
    }

    return palabraNormalizada;
}

int main() {

    string entrada;

    int nPalabra = 0;

    while(cin >> entrada){
        nPalabra++;
        cout << nPalabra << ". " << entrada << " -> " << convertirPalabraMayuscula(entrada) << endl;
    }

    return 0;
}
