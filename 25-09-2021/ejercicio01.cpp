/* 1) Dados dos números enteros llamados mayor y menor, obtener el máximo común divisor (mcd) de ambos por el método de Euclides. Para resolver este problema se procede así: a) se realiza la división entera del mayor entre el menor, b) si el residuo es cero, el mcd está en la variable llamada menor, despliega el resultado y termina el programa, c) pero si el residuo no es cero, el valor de menor pasa a mayor y el valor de residuo pasa a menor, d) repetir el paso a. */

#include <iostream>

using namespace std;

int mcd_recursivo(int, int);

int main(void){

    int a = 0, b = 0;

    cout << endl;
    cout << "\tMCD con el Teorema de Euclides" << endl << endl;;
    cout << "Ingrese el primer numero: "; cin >> a;
    cout << "Ingrese el segundo numero: "; cin >> b;
    cout << endl;
    cout << "El MCD es: " <<  mcd_recursivo(a, b);
    cout << endl << endl;
    return 0;
}

// dos formas de realizar el Teorema de Euclides

// 1

int mcd_recursivo(int a, int b) {
    if (a % b == 0) return b;
    return mcd_recursivo(b, a % b);
    }



// 2

/* int mcd_recursivo(int a, int b) {
    if (b == 0) return a;
    return mcd_recursivo(b, a % b);
    }
 */
