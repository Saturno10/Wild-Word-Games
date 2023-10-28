#include <iostream>
#include <string>

using namespace std;

int main() {

    string entrada;

    int nPalabra = 0;

    while(cin >> entrada){
        nPalabra++;
        cout << nPalabra << ". " << entrada << endl;


    }

    return 0;
}
