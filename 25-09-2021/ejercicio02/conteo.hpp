
#include <iostream>

using namespace std;

struct nodo{
    int numero;
    nodo *nods;
};

class numeros{
    private:
        nodo *nodoLista;
    public:
        numeros();
        void menu(int);
        void ingresarDato(int);
        void crearLista(int);
        void imprimir();
        void imprimir(nodo *);
        void salir();
};

numeros::numeros(){
    nodoLista = NULL;
}

void numeros::menu(int e){
    int n;
    cout << endl << "Seleccione 1, para ingresar dato";
    cout << endl << "Seleccione 2, para imprimir el conteo";
    cout << endl << "Seleccione 3, para salir" << endl;
    cin >> n;
    e++;
    switch (n)
    {
    case 1:
        return ingresarDato(e);
        break;
    case 2:
        return imprimir();
        break;
    case 3:
        return salir();
        break;
    default:
        return menu(e-1);
        break;
    }
}

void numeros::ingresarDato(int validando){
    int n;
    if(validando == 1){
        cout << endl << "Ingresar el dato hasta donde se contara: ";
        cin >> n;
        crearLista(++n);
    }
    else{
        cout  << endl << "Ya ha ingresado un dato anterior";
        return menu(validando);
    }
}
void numeros::crearLista(int n){
    if(1 < n){
        nodo *nuevoNodo = new nodo;
        nuevoNodo->numero = n-1;
        nuevoNodo->nods = nodoLista;
        nodoLista = nuevoNodo;
        crearLista(--n);
    }
    else{
        return menu(2);
    }
}

void numeros::imprimir(){
    imprimir(nodoLista);
    return menu(2);
}
void numeros::imprimir(nodo *salto){
    if(salto){
        cout << endl << salto->numero; 
    }
    if(salto->nods){
        imprimir(salto->nods);
        cout << endl << salto->numero;
    }
}
void numeros::salir(){
    while(nodoLista){
        nodo *del = nodoLista;
        nodoLista = nodoLista->nods;
        delete (del);
    }
    return;
}